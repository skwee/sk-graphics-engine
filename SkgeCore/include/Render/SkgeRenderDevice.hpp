/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_RENDER_DEVICE_H_
#define SKGE_RENDER_DEVICE_H_

#include "Skge.hpp"
#include "Render/SkgeRenderWindow.hpp"

namespace skge{

	/** 
	 * Render Device. Responsible for all the rendering.
	 */
	class SKGE_API RenderDevice{
	protected:
		bool m_Active; /**< Is device active? */
		RenderWindow* m_RenderWindow; /**< The rendering window where device render itself. */

		/** 
		 * Create rendering device.
		 */
		virtual void create() = 0;

		/** 
		 * Destroy rendering device.
		 */
		virtual void destroy() = 0;

	public:
		RenderDevice():m_RenderWindow(0){}

		/** 
		 * Destructor.
		 */
		virtual ~RenderDevice(){}

		/** 
		 * Initialize device creation (this is actually the creation of the device).
		 * @param _windowInfo Window information to create.
		 */
		virtual void initialize(const ApplicationWindowInfo& _windowInfo) = 0;

		/** 
		 * Query for device active status.
		 * @return True if device is active, otherwise false.
		 */
		bool active() const { return m_Active; }

		/** 
		 * Get device's rendering window.
		 */
		RenderWindow* getRenderWindow() const { return m_RenderWindow; }

		/** 
		 * Set projection matrix.
		 * @param _fovy Field of view in y direction.
		 * @param _aspect Aspect ration determines the field of view in x direction.
		 * @param _znear Near clipping plane.
		 * @param _zfar Far clipping plane.
		 */
		virtual void setProjection(Math::Degree _fovy, Real _aspect, Real _znear, Real _zfar) = 0;
	};

}

#endif