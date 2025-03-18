workspace "Codium"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

startproject "Sandbox"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Codium/vendor/GLFW/include"

include "Codium/vendor/GLFW"

project "Codium"
	location "Codium"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "cepch.h"
	pchsource "Codium/src/cepch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links {
		"GLFW"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		buildoptions { "/utf-8" }

		defines {
			"CE_PLATFORM_WINDOWS",
			"CE_BUILD_DLL"
		}

		links {
			"opengl32.lib"
		}

		postbuildcommands {
			"{MKDIR} ../bin/" .. outputdir .. "/Sandbox",
    		"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/"
		}
		
	filter "system:linux"
		cppdialect "C++17"
		staticruntime "On"
		pic "On"
		
		defines {
			"CE_PLATFORM_LINUX",
			"CE_BUILD_DLL"
		}
		
		links {
			"GLFW",
			"GL",
			"X11",
			"pthread",
			"dl"
		}
		
		postbuildcommands {
			"{MKDIR} ../bin/" .. outputdir .. "/Sandbox",
			"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/"
		}

	filter "configurations:Debug"
		defines "CE_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "CE_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "CE_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Codium/vendor/spdlog/include",
		"Codium/src"
	}

	links {
		"Codium"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		buildoptions { "/utf-8" }

		defines {
			"CE_PLATFORM_WINDOWS"
		}
		
	filter "system:linux"
		cppdialect "C++17"
		staticruntime "On"
		
		defines {
			"CE_PLATFORM_LINUX"
		}

	filter "configurations:Debug"
		defines "CE_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "CE_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "CE_DIST"
		buildoptions "/MD"
		optimize "On"
