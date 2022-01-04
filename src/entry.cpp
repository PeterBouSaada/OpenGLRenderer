#include <Renderer/Core.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "UI/WindowManager.h"

namespace Renderer
{
	bool OnStart()
	{

		for(int i = 0; i < 5; i++)
		{
			std::string name = "Window " + std::to_string(i + 1);
			WindowManager::CreateWindow({400, 400}, name);
		}

		while(!WindowManager::ShouldClose())
		{
			WindowManager::OnUpdate();
		}

		WindowManager::OnExit();

		return 0;
	}
}

int main()
{
	return Renderer::OnStart();
}