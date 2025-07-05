#pragma once

#include "src/Core.h"
#include "src/Events/Event.h"
#include "src/Events/ApplicationEvent.h"
#include "src/Window.h"
#include "src/LayerStack.h"

namespace SulfameEngine {

	class SULFAME_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool m_Running = true;
		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
