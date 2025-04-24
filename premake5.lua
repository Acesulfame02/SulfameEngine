workspace "SulfameEngine"
	architecture "x64"
	startproject "SandBox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "SulfameEngine"
	location "SulfameEngine"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outdir .. "/%{prj.name}")
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
        "%{prj.name}/Sulfame.h"
	}
	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
	}

	filter "system:windows"
		systemversion "latest"
		cppdialect "C++latest"
		staticruntime "On"
		defines
		{
			"SE_PLATFORM_WINDOWS",
			"SE_BUILD_DLL"
		}

		buildoptions { "/utf-8" }

		postbuildcommands 
        { 
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outdir .. "/SandBox/\"") 
        }

	filter "configurations:Debug"
		defines "SE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SE_DIST"
		optimize "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outdir .. "/%{prj.name}")
	files
	{
		"%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"SulfameEngine",
		"SulfameEngine/vendor/spdlog/include"
	}

	links
	{
		"SulfameEngine"
	}

	filter "system:windows"
		systemversion "latest"
		cppdialect "C++latest"
		staticruntime "On"
		defines
		{
			"SE_PLATFORM_WINDOWS"
		}

		buildoptions { "/utf-8" }

	filter "configurations:Debug"
		defines "SE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SE_DIST"
		optimize "On"