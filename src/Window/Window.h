#pragma once

#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <functional>

namespace Renderer
{

	class Window
	{
	public:
		explicit Window(const glm::vec2& size, const std::string& name = "Test", const bool& fullscreen = false);
		explicit Window(const uint32_t& sizeX,const uint32_t& sizeY, const std::string& name = "Test", const bool& fullscreen = false);

		~Window();

		const bool ShouldClose();

		void OnUpdate();

		void DestroyWindow();

		void SetCloseCallback(std::function<bool(uint32_t)> func, int32_t index);

		void SetCallbackIndex(int32_t index);

	private:
		Window() {};
		void InitializeGLFW(const glm::vec2& size, const std::string& name, const bool& fullscreen);

	private:
		std::function<bool(uint32_t)> m_CloseCallbackFunc = nullptr;
		int32_t m_CallbackIndex = -1;

		bool m_IsFullscreen = false;
		GLFWwindow* m_Window = nullptr;
	};

}