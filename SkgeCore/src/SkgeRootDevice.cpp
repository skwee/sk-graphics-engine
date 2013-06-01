/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#include "SkgeRootDevice.hpp"
#include "SkgeLogger.hpp"
#include "SkgeConfigFile.hpp"

namespace skge{

	DECLARE_SINGLETON(RootDevice);

	void RootDevice::cleanup(){
		//Destroy managers
		MeshManager::destroyInstance();
		m_MeshManager = 0;

		PluginManager::destroyInstance();
		m_PluginManager = 0;

		//Log end, and destroy logger.
		Logger::getInstance()->log("Closing...");
		Logger::destroyInstance();
	}

	void RootDevice::init(const String& _applicationName, const String& _configFile){
		Logger::getInstance()->log("Starting up...");

		//Create managers
		m_PluginManager = PluginManager::getInstance();
		m_MeshManager = MeshManager::getInstance();

		//Load config
		ConfigFile cf;
		cf.load(_configFile);

		//get window info
		m_WindowInfo.bitsPerPixel = cf.get<uint>("BitsPerPixel", RenderWindow::DEFAULT_BPP);
		m_WindowInfo.dimensions = Dimensions2(cf.get<uint>("Width", RenderWindow::DEFAULT_WIDTH),
			cf.get<uint>("Height", RenderWindow::DEFAULT_HEIGHT));
		m_WindowInfo.fullscreen = cf.get<bool>("Fullscreen", RenderWindow::DEFAULT_FULLSCREEN);
		m_WindowInfo.caption = _applicationName;

		//Get render system
		String renderSystem = cf.getString("RenderSystem", "OpenGL");

		//Convert render system to render system plugin name, and load it
		String renderSystemPlugin = "SkgeRenderSystem_" + renderSystem;
		m_PluginManager->load(renderSystemPlugin);
	}

	void RootDevice::registerRenderDevice(RenderDevice* _renderDevice){
		m_RenderDevice = _renderDevice;
		m_RenderDevice->initialize(m_WindowInfo);
		m_RenderWindow = m_RenderDevice->getRenderWindow();

		//Set viewport to cover all screen
		m_RenderWindow->setViewport();

		//Set projection matrix
		m_RenderDevice->setProjection(Math::Degree(45.0),
			(Real)m_WindowInfo.dimensions.width / (Real)m_WindowInfo.dimensions.height,
			Real(0.1), Real(100.0));
	}

	void RootDevice::unregisterRenderDevice(){
		delete m_RenderDevice;
		m_RenderDevice = 0;
		m_RenderWindow = 0;
	}

}