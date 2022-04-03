#pragma once

#include "defines.h"

typedef enum class MouseButtons : u8
{
    Unknown,

    MouseLeft,
    MouseRight,
    MouseMiddle,

    Max
} MouseButton;

#define MOUSE_UKNOWN MouseButton::Unknown

#define MOUSE_LEFT MouseButton::MouseLeft
#define MOUSE_RIGHT MouseButton::MouseRight
#define MOUSE_MIDDLE MouseButton::MouseMiddle

#define MOUSE_MAX MouseButton::Max
