/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_OPENGL_H_
#define SKGE_OPENGL_H_

#ifdef SKGEOPENGLRENDERSYSTEM_EXPORTS
#define SKGE_OPENGL_BUILD_LIBRARY
#define SKGE_OPENGL_API
#endif

#ifdef SKGE_OPENGL_BUILD_LIBRARY
#define SKGE_OPENGL_EXPORT_API __declspec(dllexport)
#else
#define SKGE_OPENGL_EXPORT_API __declspec(dllimport)
#endif

#ifdef _DEBUG
#define SKGE_OPENGL_DEBUG
#endif

#pragma comment(lib, "SDLmain.lib")
#pragma comment(lib, "SDL.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "GLee.lib")

#ifdef SKGE_OPENGL_DEBUG
#pragma comment(lib, "SkgeCore_d.lib")
#else
#pragma comment(lib, "SkgeCore.lib")
#endif

#include "Skge.hpp"
#include "SkgeOpenGLStdHeaders.hpp"

#endif