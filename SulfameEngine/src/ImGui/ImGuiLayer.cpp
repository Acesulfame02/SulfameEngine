#include "sepch.h"
#include "ImGuiLayer.h"
#include "imgui.h"
#include "src/Platform/OpenGL/imgui_opengl_renderer.h"
#include "GLFW/glfw3.h"
#include "src/Application.h"
#include <src/Events/KeyEvent.h>
#include <src/Events/MouseEvent.h>

namespace SulfameEngine {

	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::OnAttach()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGui::StyleColorsDark(); // or ImGui::StyleColorsLight();

		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;         // We can honor GetMouseCursor() values (optional)
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;          // We can honor io.WantSetMousePos requests (optional, rarely used)
		
		// Modern key mapping
		io.AddKeyEvent(ImGuiKey_Tab, GLFW_KEY_TAB);
		io.AddKeyEvent(ImGuiKey_LeftArrow, GLFW_KEY_LEFT);
		io.AddKeyEvent(ImGuiKey_RightArrow, GLFW_KEY_RIGHT);
		io.AddKeyEvent(ImGuiKey_UpArrow, GLFW_KEY_UP);
		io.AddKeyEvent(ImGuiKey_DownArrow, GLFW_KEY_DOWN);
		io.AddKeyEvent(ImGuiKey_PageUp, GLFW_KEY_PAGE_UP);
		io.AddKeyEvent(ImGuiKey_PageDown, GLFW_KEY_PAGE_DOWN);
		io.AddKeyEvent(ImGuiKey_Home, GLFW_KEY_HOME);
		io.AddKeyEvent(ImGuiKey_End, GLFW_KEY_END);
		io.AddKeyEvent(ImGuiKey_Insert, GLFW_KEY_INSERT);
		io.AddKeyEvent(ImGuiKey_Delete, GLFW_KEY_DELETE);
		io.AddKeyEvent(ImGuiKey_Backspace, GLFW_KEY_BACKSPACE);
		io.AddKeyEvent(ImGuiKey_Space, GLFW_KEY_SPACE);
		io.AddKeyEvent(ImGuiKey_Enter, GLFW_KEY_ENTER);
		io.AddKeyEvent(ImGuiKey_Escape, GLFW_KEY_ESCAPE);
		io.AddKeyEvent(ImGuiKey_A, GLFW_KEY_A);
		io.AddKeyEvent(ImGuiKey_C, GLFW_KEY_C);
		io.AddKeyEvent(ImGuiKey_V, GLFW_KEY_V);
		io.AddKeyEvent(ImGuiKey_X, GLFW_KEY_X);
		io.AddKeyEvent(ImGuiKey_Y, GLFW_KEY_Y);
		io.AddKeyEvent(ImGuiKey_Z, GLFW_KEY_Z);

		ImGui_ImplOpenGL3_Init("#version 410 core"); // Initialize OpenGL renderer with version 330 core
	}

	void ImGuiLayer::OnDetach()
	{
		// Cleanup ImGui context and settings here
	}

	void ImGuiLayer::OnUpdate()
	{

		ImGuiIO& io = ImGui::GetIO(); (void)io;
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f); // Set delta time for ImGui
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();
		static bool show_demo_window = true;
		if (show_demo_window)
			ImGui::ShowDemoWindow(&show_demo_window);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		ImGuiIO& io = ImGui::GetIO();

		if (m_BlockEvents)
		{
			if (event.IsInCategory(EventCategoryMouse) && io.WantCaptureMouse)
				event.Handled = true;

			if (event.IsInCategory(EventCategoryKeyboard) && io.WantCaptureKeyboard)
				event.Handled = true;
		}

		EventDispatcher dispatcher(event);

		dispatcher.Dispatch<KeyPressedEvent>([&](KeyPressedEvent& e)
			{
				io.AddKeyEvent(static_cast<ImGuiKey>(e.GetKeyCode()), true);
				return false;
			});

		dispatcher.Dispatch<KeyReleasedEvent>([&](KeyReleasedEvent& e)
			{
				io.AddKeyEvent(static_cast<ImGuiKey>(e.GetKeyCode()), false);
				return false;
			});

		dispatcher.Dispatch<MouseButtonPressedEvent>([&](MouseButtonPressedEvent& e)
			{
				io.AddMouseButtonEvent(e.GetMouseButton(), true);
				return false;
			});

		dispatcher.Dispatch<MouseButtonReleasedEvent>([&](MouseButtonReleasedEvent& e)
			{
				io.AddMouseButtonEvent(e.GetMouseButton(), false);
				return false;
			});

		dispatcher.Dispatch<MouseMovedEvent>([&](MouseMovedEvent& e)
			{
				io.AddMousePosEvent(e.GetX(), e.GetY());
				return false;
			});

		dispatcher.Dispatch<MouseScrolledEvent>([&](MouseScrolledEvent& e)
			{
				io.AddMouseWheelEvent(e.GetXOffset(), e.GetYOffset());
				return false;
			});
	}


};