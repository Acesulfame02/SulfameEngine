#pragma once

#ifdef SE_PLATFORM_WINDOWS

extern SulfameEngine::Application* SulfameEngine::CreateApplication();

int main(int argc, char** argv)
{
	SulfameEngine::Log::Init(); // Initialize the logging system
	SE_CORE_WARN("Initialized Log!");
	SE_INFO("Welcome to Sulfame!");
	int a = 1;
	SE_FATAL("Sulfame Engine Version: {0}", a);
	auto app = SulfameEngine::CreateApplication(); // Create an instance of the application
	app->Run();
	delete app;
	return 0; // Return 0 to indicate successful execution
}
#endif // SE_PLATFORM_WINDOWS