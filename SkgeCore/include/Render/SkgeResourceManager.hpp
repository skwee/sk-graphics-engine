/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_RESOURCE_MANAGER_H_
#define SKGE_RESOURCE_MANAGER_H_

#include "Skge.hpp"
#include "SkgeLogger.hpp"
#include "SkgeException.hpp"

namespace skge{

	/**
	 * Resource manager.
	 * T managed resource.
	 */
	template<class T>
	class ResourceManager{
	protected:
		/** 
		 * Resource map.
		 */
		typedef stdext::hash_map<String, T> ResourceMap;

		ResourceMap m_ResourceMap; /**< Name->Resource Map. */

		/** 
		 * Check if the given name is unique.
		 * @param _name Name to check.
		 * @return True if name unique, otherwise false.
		 */
		inline bool isNameUnique(const String& _name) const {
			if(m_ResourceMap.find(_name) == m_ResourceMap.end()){
				return true;
			}
			return false;
		}

	public:
		/** 
		 * Constructor.
		 */
		ResourceManager(){}

		/** 
		 * Destructor. Unloads all resources.
		 */
		virtual ~ResourceManager(){
			collect(true);
		}

		/** 
		 * Get resource by name.
		 * @param _name Resource's name to get.
		 * @return Resource identified by <c>_name</c>.
		 * @throw InvalidResourceException if resoruce identified by name was not loaded.
		 */
		T get(const String& _name) const;

		/** 
		 * Resource removal.
		 */
		//@{
		/** 
		 * Remove resource identified by <c>_name</c>.
		 * @param _name Name of resource to remove.
		 */
		void remove(const String& _name);

		/** 
		 * Remove resource <c>_resource</c>.
		 * @param _resource Resource to remove.
		 */
		void remove(T& _resource);
		//@}

		/** 
		 * Remove resources who is not shared among the application and just sits here and takes memory :).
		 * @param _all If false only resource who is not shared will be removed,
		 * if true everything will be removed.
		 */
		void collect(bool _all = false);
	};

	template<class T>
	T ResourceManager<T>::get(const String& _name) const {
		//Find the resource.
		ResourceMap::const_iterator it = m_ResourceMap.find(_name);

		//If resource not found, it was not loaded
		if(it == m_ResourceMap.end()){
			throw InvalidResourceException("Requested unloaded resource " + _name);
		}

		//Return resource
		return static_cast<T>(it->second);
	}

	template<class T>
	void ResourceManager<T>::remove(const String& _name){
		//Find resource
		ResourceMap::const_iterator it = m_ResourceMap.find(_name);

		if(it == m_ResourceMap.end()){
			//This is not an error, so no need to throw exception here
			//however if there is a request to remove unloaded texture,
			//than something was wrong
			Logger::getInstance()->log("Request to remove unloaded resource " + _name);
		}

		//Remove it
		m_ResourceMap.erase(it);
	}

	template<class T>
	void ResourceManager<T>::remove(T& _resource){
		remove(_resource->getInfo().getName());
	}

	template<class T>
	void ResourceManager<T>::collect(bool _all){
		if(_all){
			m_ResourceMap.clear();
			return;
		}

		ResourceMap::iterator it = m_ResourceMap.begin();
		ResourceMap::iterator endIt = m_ResourceMap.end();

		while(it != endIt){
			if(it->second.unique()){
				it = m_ResourceMap.erase(it);
			}
		}
	}

}

#endif