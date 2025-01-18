#pragma once

#ifdef CE_PLATFORM_WINDOWS
	#ifdef CE_BUILD_DLL
		#define CODIUM_API __declspec(dllexport)
	#else
		#define CODIUM_API __declspec(dllimport)
	#endif
#else
	#error Codium only supports Windows!
#endif
