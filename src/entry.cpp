#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

int main() {

	glm::vec2 windowSize = {1920, 1080};
	bool fullscreen = false;

	glfwInit();

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWmonitor* monitor;

	if(fullscreen)
	{
		monitor = glfwGetPrimaryMonitor();
	}
	else
	{
		monitor = nullptr;
	}

	GLFWwindow* window = glfwCreateWindow(windowSize.x, windowSize.y, "Test window", monitor, nullptr);
	glfwMakeContextCurrent(window);
	glfwSetWindowCloseCallback(window, [](GLFWwindow* window){ glfwSetWindowShouldClose(window, true); });
	while(!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	return 0;
}