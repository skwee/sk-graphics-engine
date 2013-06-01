/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_OPENGL_RENDER_WINDOW_H_
#define SKGE_OPENGL_RENDER_WINDOW_H_

#include "SkgeOpenGL.hpp"

#include "Render\SkgeRenderWindow.hpp"

namespace skge{

	/** 
	 * OpenGL Rendering window.
	 */
	class SKGE_OPENGL_API OpenGLRenderWindow: public RenderWindow{
	private:
		/** 
		 * Create rendering window.
		 */
		void create();

		/** 
		 * Destroy rendering window.
		 */
		void destroy();

	public:
		/** 
		 * Create rendering window.
		 * @param _windowInfo Application Window Info.
		 */
		OpenGLRenderWindow(const ApplicationWindowInfo& _windowInfo):
		RenderWindow(_windowInfo){
			create();
		}

		/** 
		 * Destroy rendering window.
		 */
		~OpenGLRenderWindow(){
			destroy();
		}

		/** 
		 * @copydoc RenderWindow::setViewport
		 */
		void setViewport(const Graphics::Viewport& _viewport);

		/** 
		 * @copydoc RenderWindow::update
		 */
		void update();
	};

}

#endif