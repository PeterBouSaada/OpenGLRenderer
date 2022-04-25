/*
 *  Author: Peter Bou Saada
 *  Filename: WindowManager.cpp
 *  Description: Singleton class that manages the windows created by our application.
 */

#include "WindowManager.h"

namespace Renderer
{

	std::vector<Window*> WindowManager::m_Windows = std::vector<Window*>();

	WindowManager &WindowManager::instance()
	{
		static WindowManager m_Instance;
		return m_Instance;
	}

	 Window* WindowManager::CreateWindow(const glm::vec2 &windowSize, const std::string& name,  const bool &fullscreen)
	{
		return CreateWindow(windowSize.x, windowSize.y, name, fullscreen);
	}

	Window* WindowManager::CreateWindow(const uint32_t &sizeX, const uint32_t &sizeY, const std::string& name, const bool &fullscreen)
	{
		// Create a new window, and set the callback and index
		m_Windows.push_back(new Window(sizeX, sizeY, name, fullscreen));
		uint32_t index = m_Windows.size() - 1;
		m_Windows[index]->SetCloseCallback(WindowManager::DestroyWindow, index);
		return m_Windows[index];
	}

	bool WindowManager::DestroyWindow(const uint32_t &index)
	{
		// Iterate through all windows and update index.
		if(index < m_Windows.size())
		{
			m_Windows.erase(m_Windows.begin() + index);
			for(int i = 0; i < m_Windows.size(); i++)
			{
				m_Windows[i]->SetCallbackIndex(i);
			}
			return true;
		}
		return false;
	}

	void WindowManager::OnUpdate()
	{
		for(auto &win: m_Windows)
		{
			win->OnUpdate();
		}
		glfwPollEvents();
	}

	void WindowManager::OnExit()
	{
		for(auto &win: m_Windows)
		{
			win->DestroyWindow();
		}
		glfwTerminate();
	}

	bool WindowManager::ShouldClose()
	{
		// if all windows are closed
		if(m_Windows.size() < 1)
			return true;

		// loop through all windows and check if they should all close.
		bool close = false;
		for(auto& win : m_Windows)
		{
			close = close && !win->ShouldClose();
		}

		return close;
	}

}

