/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_RENDER_WINDOW_H_
#define SKGE_RENDER_WINDOW_H_

#include "Skge.hpp"
#include "Math/SkgeMath.hpp"
#include "SkgeGraphics.hpp"

namespace skge{

	typedef struct ApplicationWindowInfo_t{
		String caption;
		Dimensions2 dimensions;
		uint bitsPerPixel;
		bool fullscreen;
	}ApplicationWindowInfo;

	/** 
	 * Abstract rendering class.
	 */
	class SKGE_API RenderWindow{
	protected:
		ApplicationWindowInfo m_WindowInfo; /**< Window information. */
		bool m_Created; /**< Was the window created? */
		Graphics::Viewport m_CurrentViewport; /**< Current viewport. */

		/** 
		 * Create rendering window.
		 */
		virtual void create() = 0;

		/** 
		 * Destroy rendering window.
		 */
		virtual void destroy() = 0;

	public:
		/** 
		 * @name Default constants.
		 * Default window constants.
		*/
		//@{
		static const uint DEFAULT_WIDTH = 800;
		static const uint DEFAULT_HEIGHT = 600;
		static const uint DEFAULT_BPP = 32;
		static const bool DEFAULT_FULLSCREEN = false;
		//@}

		/** 
		 * Set information for rendering window, but does not create it.
		 * @param _windowInfo Application Window Info.
		 */
		RenderWindow(const ApplicationWindowInfo& _windowInfo): m_WindowInfo(_windowInfo), m_Created(false) {}

		/** 
		 * Does nothing special :)
		 */
		virtual ~RenderWindow(){}

		/** 
		 * Set viewport to cover all screen.
		 */
		inline void setViewport(){
			Graphics::Viewport vp(0, 0, m_WindowInfo.dimensions.width, m_WindowInfo.dimensions.height);
			setViewport(vp);
		}

		/** 
		 * Set viewport.
		 * @param _viewport Viewport to set.
		 */
		virtual void setViewport(const Graphics::Viewport& _viewport) = 0;

		/** 
		 * Update window. Should be called at end of each frame.
		 */
		virtual void update() = 0;
	};

}

#endif