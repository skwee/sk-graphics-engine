/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_OPENGL_RENDER_DEVICE_H_
#define SKGE_OPENGL_RENDER_DEVICE_H_

#include "SkgeOpenGL.hpp"
#include "SkgeOpenGLRenderWindow.hpp"

#include "Render/SkgeRenderDevice.hpp"

namespace skge{

	/** 
	 * OpenGL Render device.
	 */
	class SKGE_OPENGL_API OpenGLRenderDevice: public RenderDevice{
	private:
		/** 
		 * Create render device.
		 */
		void create();

		/** 
		 * Destroy render device.
		 */
		void destroy();

	public:
		/** 
		 * Destroy render device and render window.
		 */
		~OpenGLRenderDevice(){
			destroy();
			if(m_RenderWindow) delete m_RenderWindow;
		}

		/** 
		 * @copydoc RenderDevice::initialize
		 */
		inline void initialize(const ApplicationWindowInfo& _windowInfo){
			m_RenderWindow = new OpenGLRenderWindow(_windowInfo);
			create();
		}

		/** 
		 * @copydoc RenderDevice::setProjection
		 */
		void setProjection(Math::Degree _fovy, Real _aspect, Real _znear, Real _zfar);
	};

}

#endif