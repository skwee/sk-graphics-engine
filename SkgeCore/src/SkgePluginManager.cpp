/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#include "SkgePluginManager.hpp"
#include "SkgeLogger.hpp"

namespace skge{

	DECLARE_SINGLETON(PluginManager);

	typedef void (*PluginLoadFunction)(void);
	typedef void (*PluginUnloadFunction)(void);

	void PluginManager::unloadPlugin(Plugin* _plugin){
		PluginUnloadFunction func = (PluginUnloadFunction)_plugin->getFunction("uninstallPlugin");
		func();

		_plugin->unload();
	}

	void PluginManager::load(const String& _name){
		PluginList::iterator it = m_Plugins.find(_name);

		//If we reached the end
		if(it == m_Plugins.end()){
			//Create new library and loaded.
			Plugin* plugin = new Plugin(_name);
			plugin->load();

			//Add library to list
			m_Plugins[_name] = plugin;

			//Install plugin
			PluginLoadFunction func = (PluginLoadFunction)plugin->getFunction("installPlugin");
			func();
		}else{
			Logger::getInstance()->log("Plugin " + _name + " already was loded!", Logger::LOG_WARNING);
		}
	}

	void PluginManager::unload(Plugin* _plugin){
		//Get the library iterator.
		PluginList::iterator it = m_Plugins.find(_plugin->getName());

		//If not iterator found, something is wrong here
		if(it == m_Plugins.end()){
			Logger::getInstance()->log("Trying to unload not loaded library!", Logger::LOG_WARNING);
			return;
		}

		unloadPlugin(_plugin);

		//Delete the library and erase iterator.
		delete it->second;
		m_Plugins.erase(it);
	}

	void PluginManager::unloadAll(){
		PluginList::iterator it = m_Plugins.begin();
		PluginList::iterator endIt = m_Plugins.end();

		//iterate via all libraries, unload them, and delete them.
		while(it != endIt){
			unloadPlugin(it->second);

			delete it->second;
			it = m_Plugins.erase(it);
		}
	}
}