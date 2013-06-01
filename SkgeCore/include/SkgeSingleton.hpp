/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_SINGLETON_H_
#define SKGE_SINGLETON_H_

#include "Skge.hpp"

namespace skge{

	/** 
	 * Template singleton class. Provides single instance of T.
	 */
	template<class T>
	class SKGE_API Singleton{
	private:
		static T* m_Instance; /**< Single Instance. */

	protected:
		/** 
		 * Private creation and destruction.
		 */
		//@{
		Singleton(){}
		virtual ~Singleton(){}
		//@}

	public:
		/** 
		 * Get Single Instance.
		 * @return Single instance of T.
		 */
		static T* getInstance(){
			if(m_Instance == 0){
				m_Instance = new T();
			}

			return m_Instance;
		}

		/** 
		 * Destroy Single Instance.
		 */
		static void destroyInstance(){
			if(m_Instance){
				delete m_Instance;
				m_Instance = 0;
			}
		}
	};

#define DECLARE_SINGLETON(x) template<> x* Singleton<x>::m_Instance = 0

}

#endif