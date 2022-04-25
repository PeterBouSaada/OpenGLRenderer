#include "Application.h"

namespace Renderer {

	Application::Application()
	{
		std::string name = "Window " + std::to_string(1);
		WindowManager::CreateWindow({400, 400}, name);
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