/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#include "SkgePlugin.hpp"
#include "SkgeLogger.hpp"
#include "SkgeException.hpp"

namespace skge{

	void Plugin::load(){
		if(m_Loaded){
			Logger::getInstance()->log("Loading library that was already loaded!", Logger::LOG_WARNING);
			return;
		}

#ifdef SKGE_DEBUG
		String libName = m_Name + "_d.dll";
#else
		String libName = m_Name + ".dll";
#endif
		m_hDLL = LoadLibraryA(libName.c_str());

		if( ! m_hDLL){
			throw DynamicLibraryLoadingFailed("Failed to load " + libName);
		}

		m_Loaded = true;

		Logger::getInstance()->log("Plugin " + m_Name + " was loaded successfully!", Logger::LOG_NORMAL);
	}

	void Plugin::unload(){
		if(m_Loaded){
			FreeLibrary(m_hDLL);
			m_Loaded = false;
			Logger::getInstance()->log("Plugin " + m_Name + " was unloaded successfully!", Logger::LOG_NORMAL);
		}
	}

	void* Plugin::getFunction(const String& _name){
		return (void*)GetProcAddress(m_hDLL, _name.c_str());
	}

}