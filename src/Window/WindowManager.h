#pragma once

#include <vector>
#include <Window/Window.h>

namespace Renderer
{

	class WindowManager
	{
	public:
		static WindowManager& instance();

		static Window* CreateWindow(const glm::vec2& windowSize = { 1920, 1080}, const std::string& name = "Test", const bool& fullscreen = false);
		static Window* CreateWindow(const uint32_t& sizeX = 1920, const uint32_t& sizeY = 1080, const std::string& name = "Test", const bool& fullscreen = false);

		static bool DestroyWindow(const uint32_t& index);

		static bool ShouldClose();

		static void OnUpdate();
		static void OnExit();

	private:
		static std::vector<Window*> m_Windows;

	};
}