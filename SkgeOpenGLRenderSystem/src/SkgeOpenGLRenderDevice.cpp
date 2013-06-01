/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#include "SkgeOpenGLRenderDevice.hpp"
#include "SkgeLogger.hpp"

namespace skge{

	void OpenGLRenderDevice::create(){
		//Set clear color
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

		//Enable and disable some states.
		glEnable(GL_DEPTH_TEST);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
		glDisable(GL_FOG);

		//Enable face culling.
		/*glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);*/

		//Device now active
		m_Active = true;

		Logger::getInstance()->log("OpenGL Render Device created!");
	}

	void OpenGLRenderDevice::destroy(){
		if(m_Active){
			m_Active = false;
			Logger::getInstance()->log("OpenGL Render Device destroyed!");
		}
	}

	void OpenGLRenderDevice::setProjection(Math::Degree _fovy, Real _aspect, Real _znear, Real _zfar){
		Real xmin, xmax, ymin, ymax;

		//Calculate y
		ymax = _znear * Math::tan(Math::toRadian(_fovy / 2));
		ymin = -ymax;

		//calculate x
		xmin = ymin * _aspect;
		xmax = ymax * _aspect;

		//Set projection matrix
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glFrustum(xmin, xmax, ymin, ymax, _znear, _zfar);

		//Set model view matrix
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

}