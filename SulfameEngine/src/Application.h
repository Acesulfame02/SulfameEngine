#pragma once

#include "src/Core.h"
#include "Events/Event.h"

namespace SulfameEngine {

	class SULFAME_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
