project "Glad"
    kind "StaticLib"
    language "C"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "include/glad/glad.h",
        "include/KHR/khrplatform.h",
        "src/glad.c"
    }

    includedirs {
        "include"
    }

    filter "system:windows"
        systemversion "latest"
        staticruntime "On"

    filter { "system:windows", "configurations:Release" }
        buildoptions "/MT"
    
    filter "system:linux"
        pic "On"
        staticruntime "On"
        systemversion "latest"

    filter { "system:linux", "configurations:Release" }
        buildoptions { "-DNDEBUG" }
        links { "pthread" }
