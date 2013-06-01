/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_MATH_H_
#define SKGE_MATH_H_

#include "Skge.hpp"

namespace skge{
	/**
	 * 2D Dimensions structure.
	 */
	typedef struct Dimensions2_t{
		uint width, height;
		Dimensions2_t(uint _w, uint _h):width(_w), height(_h){}
		Dimensions2_t():width(0), height(0){}
	}Dimensions2;

	/**
	* 3D Dimensions structure.
	*/
	typedef struct Dimensions3_t{
		uint width, height, depth;
		Dimensions3_t(uint _w, uint _h, uint _d):width(_w), height(_h), depth(_d){}
		Dimensions3_t():width(0), height(0), depth(0){}
	}Dimensions3;

	/** 
	 * 3D point structure.
	 */
	typedef struct Point3_t{
		uint x, y, z;
		Point3_t():x(0), y(0), z(0){}
		Point3_t(uint _x, uint _y, uint _z):x(_x), y(_y), z(_z){}
	}Point3;

	class SKGE_API Math{
	private:
		static const Real DEGREE_TO_RADIAN;
		static const Real RADIAN_TO_DEGREE;

	public:
		typedef Real Degree;
		typedef Real Radian;

		static const Radian PI;

		static inline Real tan(Radian _rad, bool _useTable = false) { return ::tan(_rad); }

		static inline Radian toRadian(Degree _deg) { return _deg * DEGREE_TO_RADIAN; }
		static inline Degree toDegree(Radian _rad) { return _rad * RADIAN_TO_DEGREE; }
	};

}

#endif