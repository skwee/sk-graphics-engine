/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#ifndef SKGE_ROOT_DEVICE_H_
#define SKGE_ROOT_DEVICE_H_

#include "SkgeSingleton.hpp"
#include "Render/SkgeRenderDevice.hpp"

#include "SkgePluginManager.hpp"
#include "Render/SkgeMeshManager.hpp"

namespace skge{

	/** 
	 * Root Device, the manager of all other devices.
	 */
	class SKGE_API RootDevice: public Singleton<RootDevice>{
	private:
		RenderDevice* m_RenderDevice; /**< Render Device. */
		RenderWindow* m_RenderWindow; /**< Render Window. */

		PluginManager* m_PluginManager; /**< Plugin manager. */
		MeshManager* m_MeshManager; /**< Mesh Manager. */

		ApplicationWindowInfo m_WindowInfo; /**< Window information. */

		/** 
		 * @copydoc RootDevice::~RootDevice.
		 */
		void cleanup();

	public:
		/** 
		 * Constructor.
		 */
		RootDevice(){}

		/** 
		 * Destroy root device, and everything that is connected to it.
		 */
		~RootDevice(){
			cleanup();
		}

		/** 
		 * Initialize root device.
		 * @param _applicationName Name of application to show in window title.
		 * @param _cofigFile Configuration File.
		 */
		void init(const String& _applicationName, const String& _configFile);

		/** 
		 * Register render device.
		 * @param _renderDevice Render device to register.
		 */
		void registerRenderDevice(RenderDevice* _renderDevice);

		/** 
		 * Unregister render device.
		 */
		void unregisterRenderDevice();
	};

}

#endif