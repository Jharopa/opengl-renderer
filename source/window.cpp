#include "pch.h"
#include "window.h"

#ifdef PLATFORM_WINDOWS
    #include "platform/windows/window_win32.h"
#endif

std::shared_ptr<Window> Window::init(const u32& width, const u32& height, const std::string& title)
{
    #ifdef PLATFORM_WINDOWS
        return std::make_shared<WindowWin32>(width, height, title);
    #else
        return nullptr;
    #endif
}
