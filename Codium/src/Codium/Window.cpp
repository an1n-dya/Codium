#include "cepch.h"
#include "Window.h"

#ifdef CE_PLATFORM_WINDOWS
    #include "Platform/Windows/WindowsWindow.h"
#elif defined(CE_PLATFORM_LINUX)
    #include "Platform/Linux/LinuxWindow.h"
#endif

namespace Codium {
    Window* Window::Create(const WindowProps& props) {
        #ifdef CE_PLATFORM_WINDOWS
            return new WindowsWindow(props);
        #elif defined(CE_PLATFORM_LINUX)
            return new LinuxWindow(props);
        #else
            CE_CORE_ASSERT(false, "Unknown platform!");
            return nullptr;
        #endif
    }
}
