/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#include "SkgeOpenGL.hpp"
#include "SkgeOpenGLRenderDevice.hpp"

#include "SkgeRootDevice.hpp"

extern "C" void SKGE_OPENGL_EXPORT_API installPlugin(){
	skge::RootDevice::getInstance()->registerRenderDevice(new skge::OpenGLRenderDevice());
}

extern "C" void SKGE_OPENGL_EXPORT_API uninstallPlugin(){
	skge::RootDevice::getInstance()->unregisterRenderDevice();
}