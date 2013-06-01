/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_TYPES_H_
#define SKGE_TYPES_H_

#include "SkgeStdHeaders.hpp"

namespace skge{

	/** 
	* @name String definition.
	*/
	//@{
#ifdef SKGE_UNICODE
	typedef std::wstring String;
#else
	typedef std::string String;
#endif
	//@}

	/** 
	* @name Generic types.
	*/
	//@{
	typedef unsigned int uint;
	typedef unsigned long ulong;
	typedef unsigned char byte;
	typedef unsigned short ushort;
	//@}

	/** 
	* @name Real value.
	*/
	//@{
#ifdef SKGE_DOUBLE_PRECISION
	typedef double Real;
#else
	typedef float Real;
#endif
	//@}

}

#endif