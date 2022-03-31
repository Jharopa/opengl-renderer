#include "pch.h"

#include "windowwin32.h"

// Win32 window event/input procedure callback function
LRESULT CALLBACK wndPrc(HWND hWND, UINT msg, WPARAM wParam, LPARAM lParam)
{
    std::shared_ptr<Window> window = Application::getInstance().getWindow();
    std::function<void(Event&)>& callback = window->getEventCallback();

    switch (msg)
	{
	    case WM_DESTROY:
	    {
	    	WindowWin32* window = (WindowWin32*)GetWindowLongPtr(hWND, GWLP_USERDATA);
	    	break;
	    }

	    case WM_CLOSE:
	    {
	    	PostQuitMessage(0);
	    	break;
	    }
        
        case WM_SYSKEYDOWN:
        case WM_SYSKEYUP:
        case WM_KEYDOWN:
        case WM_KEYUP:
        {   
            b8 pressed = msg == WM_KEYDOWN || msg == WM_SYSKEYDOWN;
            b8 repeat = (lParam >> 30);

            if(pressed)
            {
                KeyPressedEvent event((Key)wParam, repeat);
                callback(event);
            }
            else
            {
                KeyReleasedEvent event((Key)wParam);
                callback(event);
            }

            break;
        }

	    default:
	    	return DefWindowProcA(hWND, msg, wParam, lParam);
	}
    
	return NULL;
}

WindowWin32::WindowWin32(const u32& width, const u32& height, const std::string& title)
 : Window(width, height, title)
{
    m_hInstance = GetModuleHandleA(0);

    HICON icon = LoadIcon(m_hInstance, IDI_APPLICATION);

    WNDCLASSEXA wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_DBLCLKS;
    wc.lpfnWndProc = &wndPrc;
    //wc.cbClsExtra = 0;
    //wc.cbWndExtra = 0;
    wc.hInstance = m_hInstance;
    wc.hIcon = icon;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    //wc.lpszMenuName = NULL
    wc.lpszClassName = m_title.c_str();
    //wc.hIconSm = NULL;

    ATOM classID = RegisterClassExA(&wc);
    assert(classID);

    DWORD style = WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_THICKFRAME;
    DWORD exStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
    RECT rc = { 0, 0, (LONG)m_width, (LONG)m_height };

    AdjustWindowRectEx(&rc, style, false, exStyle);
    
    m_hWND = CreateWindowExA(exStyle, wc.lpszClassName, m_title.c_str(), style, CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, m_hInstance, NULL);

    assert(m_hWND);

    SetWindowLongPtrA(m_hWND, GWLP_USERDATA, (LONG_PTR)this);

    ShowWindow(m_hWND, SW_SHOW);
    UpdateWindow(m_hWND);
}

WindowWin32::~WindowWin32()
{
    DestroyWindow(m_hWND);
}

void WindowWin32::update()
{
    processInput();
}

void WindowWin32::processInput()
{
    MSG msg;

    RtlSecureZeroMemory(&msg, sizeof(MSG));

    while (PeekMessageA(&msg, NULL, NULL, NULL, PM_REMOVE))
    {
        if(msg.message == WM_QUIT)
        {
            m_shouldClose = true;
            return;
        }

        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
}
