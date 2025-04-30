#include "sepch.h"
#include "src/Application.h"
#include "src/Events/ApplicationEvent.h"
#include "src/Log.h"

namespace SulfameEngine{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}