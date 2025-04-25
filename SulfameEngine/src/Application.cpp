#include "sepch.h"
#include "src/Application.h"
#include "src/Events/ApplicationEvent.h"
#include "src/Log.h"

namespace SulfameEngine{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		SE_TRACE("{}", e.ToString());
		while (true);
	}
}