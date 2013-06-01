/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_GRAPHICS_H_
#define SKGE_GRAPHICS_H_

#include "Skge.hpp"

namespace skge{

	namespace Graphics{
		typedef struct Viewport_t{
			uint x, y;
			uint width, height;

			Viewport_t():x(0), y(0), width(0), height(0){}
			Viewport_t(uint _x, uint _y, uint _w, uint _h):x(_x), y(_y), width(_w), height(_h){}
		}Viewport;
	}

}

#endif