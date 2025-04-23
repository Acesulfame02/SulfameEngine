#pragma once

#ifdef SE_PLATFORM_WINDOWS

extern SulfameEngine::Application* SulfameEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = SulfameEngine::CreateApplication(); // Create an instance of the application
	app->Run();
	delete app;
	return 0; // Return 0 to indicate successful execution
}
#endif // SE_PLATFORM_WINDOWS