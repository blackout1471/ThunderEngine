workspace "ThunderEngine"
	location "..\\"
	architecture "x86_64"
	startproject "Sandbox2D"

	configurations
	{
		"Debug",
		"Release",
		"Distribution"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "../vendor/glfw/include"

group "Dependencies"
	include "glfw.lua"

group ""

project "ThunderEngine"
	location "..\\"
	kind "StaticLib"
	language "C++"
	cppdialect "c++17"
	staticruntime "on"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "tepch.h"
	pchsource "../src/tepch.cpp"

	files 
	{
		"../src/**.h",	
		"../src/**.cpp",
	}

	includedirs 
	{
		"../src",
		"%{IncludeDir.GLFW}"
	}

	links 
	{
		"opengl32.lib",
		"glfw"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "TE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "TE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Distribution"
		defines "TE_DISTRIBUTION"
		runtime "Release"
		optimize "on"

project "Sandbox2D"
	location "..\\Sandbox2D"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"../%{prj.name}/**.h",
		"../%{prj.name}/**.cpp"
	}

	includedirs
	{
		"../src",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"ThunderEngine"
	}

	filter "system:windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		defines "TE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "TE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "TE_DIST"
		runtime "Release"
		optimize "on"