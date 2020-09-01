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
IncludeDir["Glad"] = "../vendor/glad/include"
IncludeDir["glm"] = "../vendor/glm"
IncludeDir["stb"] = "../vendor/stb"
IncludeDir["entt"] = "../vendor/entt"

group "Dependencies"
	include "glfw.lua"
	include "glad.lua"

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
		"../vendor/glm/glm/**.hpp",
		"../vendor/glm/glm/**.inl",
		"../vendor/stb/**.h",
		"../vendor/stb/**.cpp"
	}

	includedirs 
	{
		"../src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.stb}",
		"%{IncludeDir.entt}"
	}

	links 
	{
		"opengl32.lib",
		"glfw",
		"glad"
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
		"../vendor",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb}"
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