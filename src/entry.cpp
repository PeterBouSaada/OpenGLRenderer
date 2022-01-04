#include <Renderer/Core.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "UI/Window.h"

namespace Renderer
{
	bool OnStart()
	{
		glm::vec2 windowSize = {1920, 1080};

		Renderer::Window window(windowSize, false);

		while(!window.ShouldClose()) {
			window.OnUpdate();
		}

		window.DestroyWindow();

		return 0;
	}
}

int main()
{
	return Renderer::OnStart();
}