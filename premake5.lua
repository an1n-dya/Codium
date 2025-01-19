workspace "Codium"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

startproject "Sandbox"

project "Codium"
	location "Codium"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include"
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

		postbuildcommands {
			"{MKDIR} ../bin/" .. outputdir .. "/Sandbox",
    		"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/"
		}

	filter "configurations:Debug"
		defines "CE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CE_DIST"
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

	filter "configurations:Debug"
		defines "CE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CE_DIST"
		optimize "On"
        