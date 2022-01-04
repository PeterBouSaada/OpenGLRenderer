#include "Window.h"

namespace Renderer
{

	Window::Window(const glm::vec2 &size, const bool &fullscreen)
	{
		InitializeGLFW(size, fullscreen);
	}

	Window::Window(const uint32_t &sizeX, const uint32_t &sizeY, const bool &fullscreen)
	{
		InitializeGLFW({sizeX, sizeY}, fullscreen);
	}

	Window::~Window()
	{
		DestroyWindow();
	}

	void Window::InitializeGLFW(const glm::vec2 &size, const bool &fullscreen)
	{
		if(!glfwInit())
			std::cout << "Oh no, big problem!" << std::endl;

		glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		GLFWmonitor* monitor = nullptr;

		if (fullscreen)
		{
			monitor = glfwGetPrimaryMonitor();
		}

		m_Window = glfwCreateWindow(size.x, size.y, "Test window", monitor, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window)
		{
			glfwSetWindowShouldClose(window, true);
		});

	}

	void Window::OnUpdate()
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	const bool Window::ShouldClose()
	{
		return glfwWindowShouldClose(m_Window);
	}

	void Window::DestroyWindow()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}


}
