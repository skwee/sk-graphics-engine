/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_PLUGIN_H_
#define SKGE_PLUGIN_H_

#include "Skge.hpp"

namespace skge{

	/** 
	 * Plugin encapsulation.
	 */
	class SKGE_API Plugin{
	private:
		String m_Name; /**< Plugin (also filename without the extensions) */
		bool m_Loaded; /**< Determines if the plugin was loaded. */

		HINSTANCE m_hDLL; /**< Plugin instance. */

	public:
		/** 
		 * Constructor.
		 * @param _pluginName Name of the Plugin.
		 */
		Plugin(const String& _pluginName):m_Name(_pluginName), m_Loaded(false){}

		/** 
		 * Destructor.
		 * Unloads the plugin.
		 */
		~Plugin(){
			unload();
		}

		/** 
		 * Get the name of the plugin.
		 * @return Library name.
		 */
		const String& getName() const { return m_Name; }

		/** 
		 * Was the plugin loaded?
		 * @return True if loaded otherwise false.
		 */
		inline bool loaded() const { return m_Loaded; }

		/** 
		 * Load plugin.
		 */
		void load();

		/** 
		 * Unload plugin.
		 */
		void unload();

		/** 
		 * Get pointer to function.
		 * @param _name Function name to get.
		 */
		void* getFunction(const String& _name);
	};

}

#endif