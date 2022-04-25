/*
 *  Author: Peter Bou Saada
 *  Filename: Application.cpp
 *  Description: Application class that allows us to centralize program flow.
 */

#include "Application.h"

namespace Renderer {

	Application::Application()
	{
		std::string name = "Window " + std::to_string(1);
		WindowManager::CreateWindow({1920, 1080}, name);
	}

	void Application::OnRun()
	{
		while(!WindowManager::ShouldClose())
		{
			WindowManager::OnUpdate();
		}
	}

	Application::~Application()
	{
		WindowManager::OnExit();
	}

}