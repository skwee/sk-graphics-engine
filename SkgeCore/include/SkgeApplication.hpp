/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_APPLICATION_H_
#define SKGE_APPLICATION_H_

#include "SkgeRootDevice.hpp"

namespace skge{

	/** 
	 * Application class is the top-level class that uses the engine.
	 * Everyone who wishes to use SKGE must inherit from here.
	 */
	class SKGE_API Application{
	private:
		String m_applicationName;
		String m_CofigFile;
	protected:
		RootDevice* m_Root; /**< The root device. */
		bool m_Running; /**< Indicate if the application is running or not. */

	public:
		/** 
		 * Constructor. Create Application.
		 * @param _applicationTitle Application title to use.
		 * @param _configFile Configuration file of the engine to use.
		 */
		Application(const String& _applicationName = "S-K.G.E Demo", const String& _configFile = "SkgeConfig.ini"):
		  m_applicationName(_applicationName), m_CofigFile(_configFile){}

		/** 
		 * Destructor, destroy application.
		 */
		virtual ~Application();

		/** 
		 * Initialize Application.
		 * @param _applicationConfigFile Application configuration file.
		 * @return True if application can run, otherwise false.
		 */
		void init();

		/** 
		 * Run method. Execute application.
		 */
		virtual void run() = 0;
	};

}

#endif