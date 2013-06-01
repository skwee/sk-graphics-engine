/*
* This File is a part of SK-Game Engine.
* 
* Copyright (c) 2009 by Dmitry skwo Kudryavtsev / SK-Software
* s.kwee357@gmail.com
*/

#include "SkgeApplication.hpp"

namespace skge{

	Application::~Application(){
		RootDevice::destroyInstance();
		m_Root = 0;
	}

	void Application::init(){
		m_Root = RootDevice::getInstance();

		m_Root->init(m_applicationName, m_CofigFile);
	}

}