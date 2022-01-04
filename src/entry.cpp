#include <Renderer/Core.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "UI/Window.h"

namespace Renderer
{
	bool OnStart()
	{
		Renderer::Window window({1920, 1080}, false);

		while(!window.ShouldClose())
		{
			window.OnUpdate();
		}

		return 0;
	}
}

int main()
{
	return Renderer::OnStart();
}