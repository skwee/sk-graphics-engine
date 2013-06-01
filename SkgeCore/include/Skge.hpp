/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_H_
#define SKGE_H_

#ifdef SKGECORE_EXPORTS
#define SKGE_BUILD_LIBRARY
#endif

#ifdef _DEBUG
#define SKGE_DEBUG
#endif

#define SKGE_PLATFROM_WIN	0x1
#define SKGE_PLATFORM_LINUX 0x2
#define SKGE_PLATFROM_MAC	0x3

#ifdef _WIN32
#define SKGE_PLATFROM SKGE_PLATFORM_WIN
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#else
#error "Only Windows 32bit supported!"
#endif

#include "SkgeCommon.hpp"

#endif