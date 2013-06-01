/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_RESOURCE_H_
#define SKGE_RESOURCE_H_

#include "Skge.hpp"

namespace skge{

	/** 
	 * Resource Information.
	 */
	class SKGE_API ResourceInfo{
	private:
		String m_Name; /**< Resource unique name. */

	public:
		/** 
		 * Constructor. Sets resource information
		 * @param _name Resource name.
		 */
		ResourceInfo(const String& _name):m_Name(_name){}

		/** 
		 * Name getter.
		 * @return Resource name.
		 */
		inline const String& getName() const { return m_Name; }
	};

	/** 
	 * Resource, basic type of all resources.
	 */
	class SKGE_API Resource{
	protected:
		ResourceInfo m_Info; /**< Resource Info. */
		bool m_Loaded; /**< Was the resource loaded? */

	public:
		/** 
		 * Constructor.
		 * @param _name Resource name.
		 */
		Resource(const String& _name): m_Info(_name), m_Loaded(false){}

		/** 
		 * Destructor.
		 */
		virtual ~Resource(){}

		/** 
		 * Get Resource Info.
		 * @return Resource info.
		 */
		inline const ResourceInfo& getInfo() const { return m_Info; }
	};

}

#endif