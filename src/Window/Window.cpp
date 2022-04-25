/*
 *  Author: Peter Bou Saada
 *  Filename: Window.cpp
 *  Description: Logic for initializing GLFW and creating a window.
 */

#include "Window.h"

namespace Renderer
{

	Window::Window(const glm::vec2 &size, const std::string& name, const bool &fullscreen)
	{
		InitializeGLFW(size, name, fullscreen);
	}

	Window::Window(const uint32_t &sizeX, const uint32_t &sizeY, const std::string& name, const bool &fullscreen)
	{
		InitializeGLFW({sizeX, sizeY}, name, fullscreen);
	}

	Window::~Window()
	{
		DestroyWindow();
	}

	void Window::InitializeGLFW(const glm::vec2 &size, const std::string& name, const bool &fullscreen)
	{
		// Attempt to initialize GLFW
		if(!glfwInit())
		{
			std::cout << "Renderer::Window: Failed to Initialize GLFW. Terminating process..." << std::endl;
			return;
		}

		glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		// fullscreen support
		GLFWmonitor* monitor = nullptr;

		if (fullscreen)
		{
			monitor = glfwGetPrimaryMonitor();
		}

		m_Window = glfwCreateWindow(size.x, size.y, name.c_str(), monitor, nullptr);
		glfwMakeContextCurrent(m_Window);

		// Set this window id user pointer to the current class instance to retrieve later.
		glfwSetWindowUserPointer(m_Window, this);

		// Create and provide window close callback
		auto WindowCloseCallback = [](GLFWwindow *window)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			glfwSetWindowShouldClose(window, true);
			win->DestroyWindow();

		};

		glfwSetWindowCloseCallback(m_Window, WindowCloseCallback);

		m_IsFullscreen = fullscreen;

	}

	void Window::OnUpdate()
	{
		glfwMakeContextCurrent(m_Window);
		glfwSwapBuffers(m_Window);
	}

	const bool Window::ShouldClose()
	{
		return glfwWindowShouldClose(m_Window);
	}

	void Window::DestroyWindow()
	{
		// destroy current window and call WindowManager function with correct index
		glfwDestroyWindow(m_Window);
		if(m_CallbackIndex >= 0 && m_CloseCallbackFunc != nullptr)
			m_CloseCallbackFunc((uint32_t)m_CallbackIndex);
	}

	void Window::SetCloseCallback(std::function<bool(uint32_t)> func, int32_t index)
	{
		m_CloseCallbackFunc = func;
		m_CallbackIndex = index;
	}

	void Window::SetCallbackIndex(int32_t index)
	{
		m_CallbackIndex = index;
	}
}
