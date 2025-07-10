#pragma once
#include "src/Core.h"
#include "src/Layer.h"
#include "src/Events/Event.h"

namespace SulfameEngine {
	class SULFAME_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		float m_Time = 0.0f;
		bool m_BlockEvents = true;
	};
}

