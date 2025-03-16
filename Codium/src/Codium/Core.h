#pragma once

#ifdef CE_PLATFORM_WINDOWS
    #ifdef CE_BUILD_DLL
        #define CODIUM_API __declspec(dllexport)
    #else
        #define CODIUM_API __declspec(dllimport)
    #endif
#elif defined(CE_PLATFORM_LINUX)
    #define CODIUM_API __attribute__((visibility("default")))
#else
    #error Codium only supports Windows and Linux!
#endif

#define BIT(x) (1 << x)
