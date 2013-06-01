/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_VECTOR_3_H_
#define SKGE_VECTOR_3_H_

#include "Skge.hpp"

namespace skge{

	/** 
	 * 3D Vector.
	 */
	class SKGE_API Vector3{
	public:
		Real x, y, z;

		inline Vector3(Real _x, Real _y, Real _z):x(_x), y(_y), z(_z){}
	};

}

#endif