/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_PLUGIN_MANAGER_H_
#define SKGE_PLUGIN_MANAGER_H_

#include "SkgePlugin.hpp"
#include "SkgeSingleton.hpp"

namespace skge{

	/** 
	 * Plugin manager.
	 */
	class SKGE_API PluginManager: public Singleton<PluginManager>{
	private:
		/** 
		 * Plugin List structure.
		 */
		typedef std::map<String, Plugin*> PluginList;

		PluginList m_Plugins; /**< Plugins list. */

		/** 
		 * Unload plugin, calls the unload method, the unloads the library from memory.
		 * @param _plugin Plugin to unload.
		 */
		void unloadPlugin(Plugin* _plugin);

	public:
		/** 
		 * Constructor.
		 */
		PluginManager(){}

		/** 
		 * Destructor, unload all plugins.
		 */
		~PluginManager(){
			unloadAll();
		}

		/** 
		 * Load plugin with name <c>_name</c>.
		 * @param _name Name of plugin to load.
		 */
		void load(const String& _name);

		/** 
		 * Unload plugin.
		 */
		void unload(Plugin* _plugin);

		/** 
		 * Unload all plugins.
		 */
		void unloadAll();
	};

}

#endif