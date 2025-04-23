#pragma once

#ifdef SE_PLATFORM_WINDOWS
	#ifdef SE_BUILD_DLL
		#define SULFAME_API __declspec(dllexport)
	#else
		#define SULFAME_API __declspec(dllimport)
	#endif
#else
	#error Sulfame only supports Windows!
#endif // SE_PLATFORM_WINDOWS
