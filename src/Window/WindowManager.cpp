#include "WindowManager.h"

namespace Renderer
{

	std::vector<Window*> WindowManager::m_Windows = std::vector<Window*>();

	WindowManager &WindowManager::instance()
	{
		static WindowManager m_Instance;
		return m_Instance;
	}

	void WindowManager::CreateWindow(const glm::vec2 &windowSize, const std::string& name,  const bool &fullscreen)
	{
		CreateWindow(windowSize.x, windowSize.y, name, fullscreen);
	}

	void WindowManager::CreateWindow(const uint32_t &sizeX, const uint32_t &sizeY, const std::string& name, const bool &fullscreen)
	{
		m_Windows.push_back(new Window(sizeX, sizeY, name, fullscreen));
		uint32_t index = m_Windows.size() - 1;
		m_Windows[index]->SetCloseCallback(WindowManager::DestroyWindow, index);
	}

	bool WindowManager::DestroyWindow(const uint32_t &index)
	{
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
		if(m_Windows.size() < 1)
			return true;

		bool close = false;
		for(auto& win : m_Windows)
		{
			close = close && !win->ShouldClose();
		}

		return close;
	}

}

