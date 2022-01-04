#pragma once

#include <Renderer/Core.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace Renderer
{

	class Window
	{
	public:
		explicit Window(const glm::vec2& size = {1920, 1080}, const bool& fullscreen = false);
		explicit Window(const uint32_t& sizeX = 1920, const uint32_t& sizeY = 1080, const bool& fullscreen = false);

		~Window();

		const bool ShouldClose();

		void OnUpdate();
		void DestroyWindow();


	private:
		void InitializeGLFW(const glm::vec2& size, const bool& fullscreen);

	private:
		bool m_IsFullscreen = false;
		GLFWwindow* m_Window = nullptr;

	};

}