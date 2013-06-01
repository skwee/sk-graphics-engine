/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#include "SkgeOpenGLRenderWindow.hpp"
#include "SkgeException.hpp"
#include "SkgeLogger.hpp"

namespace skge{

	void OpenGLRenderWindow::create(){
		//try to initialize SDL
		if(SDL_Init(SDL_INIT_VIDEO) == -1){
			String sdlError(SDL_GetError());
			throw InitializationFailedException("Failed to initialize SDL to create render window. " + sdlError);
		}

		//Enable double buffering.
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		//Create needed flags
		Uint32 flags = SDL_OPENGL;
		if(m_WindowInfo.fullscreen){
			flags |= SDL_FULLSCREEN;
		}

		//Create video mode
		if(SDL_SetVideoMode(m_WindowInfo.dimensions.width, m_WindowInfo.dimensions.height,
			m_WindowInfo.bitsPerPixel, flags) == NULL){
			String sdlError(SDL_GetError());
			SDL_QuitSubSystem(SDL_INIT_VIDEO);
			throw InitializationFailedException("Failed to set video mode! " + sdlError);
		}

		//Set window title
		SDL_WM_SetCaption(m_WindowInfo.caption.c_str(), NULL);

		//window now created
		m_Created = true;

		Logger::getInstance()->log("OpenGL Render Window created!");
	}

	void OpenGLRenderWindow::destroy(){
		if(m_Created){
			SDL_QuitSubSystem(SDL_INIT_VIDEO);
			m_Created = false;
			Logger::getInstance()->log("OpenGL Render Window destroyed!");
		}
	}

	void OpenGLRenderWindow::setViewport(const Graphics::Viewport& _viewport){
		glViewport(_viewport.x, _viewport.y, _viewport.width, _viewport.height);
		m_CurrentViewport = _viewport;
	}

	void OpenGLRenderWindow::update(){
		SDL_GL_SwapBuffers();
	}

}