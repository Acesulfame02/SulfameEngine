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
-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "SulfameEngine/vendor/GLFW/include"
IncludeDir["GLAD"] = "SulfameEngine/vendor/GLAD/include"
IncludeDir["ImGui"] = "SulfameEngine/vendor/ImGui"

include "SulfameEngine/vendor/GLFW"
include "SulfameEngine/vendor/GLAD"
include "SulfameEngine/vendor/ImGui"

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
        "%{prj.name}/Sulfame.h",
        "%{prj.name}/sepch.h",
        "%{prj.name}/sepch.cpp",
		"%{prj.name}/src/Events/**.**"
	}

	pchheader "sepch.h"
	pchsource "SulfameEngine/sepch.cpp"

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"GLAD",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"
		cppdialect "C++latest"
		staticruntime "Off"
		defines
		{
			"SE_PLATFORM_WINDOWS",
			"SE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		buildoptions { "/utf-8" }

		postbuildcommands 
        { 
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outdir .. "/SandBox/\"") 
        }

	filter "configurations:Debug"
		defines "SE_DEBUG"
		runtime "Debug"
		symbols "On"
		
	filter "configurations:Release"
		defines "SE_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SE_DIST"
		runtime "Release"
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
		"SulfameEngine",
		"GLFW",
		"GLAD",
		"ImGui",
	}

	filter "system:windows"
		systemversion "latest"
		cppdialect "C++latest"
		staticruntime "Off"
		defines
		{
			"SE_PLATFORM_WINDOWS"
		}

		buildoptions { "/utf-8" }

	filter "configurations:Debug"
		defines "SE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "SE_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SE_DIST"
		runtime "Release"
		optimize "On"