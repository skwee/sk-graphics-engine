/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_COMMON_H_
#define SKGE_COMMON_H_

//API Symbols
#ifdef SKGE_BUILD_LIBRARY
#define SKGE_API __declspec(dllexport)
#else
#define SKGE_API __declspec(dllimport)
#endif

#ifdef SKGE_FULL_WARNINGS
#else
//'class' : class 'some_class' needs to have dll-interface to be used by clients of class 'class'
#pragma warning (disable : 4251)

//'func_name': This function or variable may be unsafe. Consider using funcname_s instead.
#pragma warning (disable : 4996)
#endif

#include "SkgeTypes.hpp"

#endif