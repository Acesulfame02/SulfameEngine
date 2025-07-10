#include <Sulfame.h>

class ExampleLayer : public SulfameEngine::Layer 
{
public:
	ExampleLayer()
		:Layer("Example")
	{ }

	void OnUpdate() override
	{
		SE_INFO("ExampleLayer::Update");
	}

	void OnEvent(SulfameEngine::Event& event) override
	{
		SE_TRACE("{0}", event);
	}
};

class SandBox : public SulfameEngine::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new SulfameEngine::ImGuiLayer());
	}
	~SandBox()
	{

	}
};

SulfameEngine::Application* SulfameEngine::CreateApplication()
{
	return new SandBox();
}