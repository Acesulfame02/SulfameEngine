#pragma once

#include "src/Core.h"
#include "src/Events/Event.h"
#include "src/Window.h"

namespace SulfameEngine {

	class SULFAME_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);
	private:
		bool m_Running = true;
		std::unique_ptr<Window> m_Window;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
