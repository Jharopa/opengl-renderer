#pragma once

// Renderer includes
#include "window.h"
#include "utils/utils.h"
#include "input/input.h"
#include "application.h"

class WindowWin32 : public Window
{
    private:
        HINSTANCE m_hInstance;
        HWND m_hWND;

    public:
        WindowWin32(const u32& width, const u32& height, const std::string& title);
        virtual ~WindowWin32();
        
        void update() override;

        [[nodiscard]] void* getWindow() const noexcept override { return m_hWND; }

    private:
        void processInput() override;
};
