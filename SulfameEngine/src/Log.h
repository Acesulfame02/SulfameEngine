#pragma once
#include <memory>
#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"
#include "Core.h"

namespace SulfameEngine {

	class SULFAME_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define SE_CORE_TRACE(...) ::SulfameEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SE_CORE_INFO(...)  ::SulfameEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SE_CORE_WARN(...)  ::SulfameEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SE_CORE_ERROR(...) ::SulfameEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SE_CORE_FATAL(...) ::SulfameEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define SE_TRACE(...)      ::SulfameEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SE_INFO(...)       ::SulfameEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define SE_WARN(...)       ::SulfameEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SE_ERROR(...)      ::SulfameEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define SE_FATAL(...)      ::SulfameEngine::Log::GetClientLogger()->critical(__VA_ARGS__)