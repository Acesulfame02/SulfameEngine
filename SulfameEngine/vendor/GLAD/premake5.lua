project "GLAD"
	location "."
	kind "StaticLib"
	language "C"
	staticruntime "Off"

	targetdir ("bin/" .. outdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outdir .. "/%{prj.name}")

	files
	{
		"include/glad/**.h",
		"include/KHR/**.h",
		"src/**.c",
		"src/**.h",
	}

	includedirs
    {
        "include"
    }

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines { "SE_DEBUG" }
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines { "SE_RELEASE" }
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines { "SE_DIST" }
		runtime "Release"
		optimize "On"
