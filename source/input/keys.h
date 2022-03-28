#pragma once

#include <iostream>

#include "../defines.h"

// TODO: Need to add symbol keys and all the other keys that are on my keyboard in the future!

enum class Key : u8
{
    // Uknown key
    Unknown = 0x00,

    // Control keys
    BackSpace = 0x08,
    Tab = 0x09,
    Enter = 0x0D,
    Shift = 0x10,
    Control = 0x011,
    Pause = 0x13,
    Caps = 0x14,
    Escape = 0x1B,
    Space = 0x20,
    Insert = 0x2D,
    Home = 0x24,
    Delete = 0x2E,
    End = 0x23,

    // Directional keys
    Up = 0x26,
    Down = 0x28,
    Left = 0x25,
    Right = 0x27,

    // Alpha-numeric keys 0 - 9
    AN0 = 0x30,
    AN1 = 0x31,
    AN2 = 0x32,
    AN3 = 0x33,
    AN4 = 0x34,
    AN5 = 0x35,
    AN6 = 0x36,
    AN7 = 0x37,
    AN8 = 0x38,
    AN9 = 0x39,

    // Alpha-numeric keys A - Z
    A = 0x41,
    B = 0x42,
    C = 0x43,
    D = 0x44,
    E = 0x45,
    F = 0x46,
    G = 0x47,
    H = 0x48,
    I = 0x49,
    J = 0x4A,
    K = 0x4B,
    L = 0x4C,
    M = 0x4D,
    N = 0x4E,
    O = 0x4F,
    P = 0x50,
    Q = 0x51,
    R = 0x52,
    S = 0x53,
    T = 0x54,
    U = 0x55,
    V = 0x56,
    W = 0x57,
    X = 0x58,
    Y = 0x59,
    Z = 0x5A,

    // Function keys
    F1 = 0x70,
    F2 = 0x71,
    F3 = 0x72,
    F4 = 0x73,
    F5 = 0x74,
    F6 = 0x75,
    F7 = 0x76,
    F8 = 0x77,
    F9 = 0x78,
    F10 = 0x79,
    F11 = 0x7A,
    F12 = 0x7B,

    // Maximum value of keys enum (used for setting array size)
    Max
};

#define KEY_UNKNOWN Key::Unknown

#define KEY_BACKSPACE Key::BackSpace
#define KEY_ENTER Key::Enter
#define KEY_SHIFT Key::Shift
#define KEY_CONTROL Key::Control
#define KEY_PAUSE Key::Pause
#define KEY_CAPS Key::Caps
#define KEY_ESCAPE Key::Escape
#define KEY_SPACE Key::Space
#define KEY_INSERT Key::Insert
#define KEY_HOME Key::Home
#define KEY_DELETE Key::Delete
#define KEY_END Key::End

#define KEY_UP Key::Up
#define KEY_DOWN Key::Down
#define KEY_LEFT Key::Left
#define KEY_RIGHT Key::Right

#define KEY_0 Key::AN0
#define KEY_1 Key::AN1
#define KEY_2 Key::AN2
#define KEY_3 Key::AN3
#define KEY_4 Key::AN4
#define KEY_5 Key::AN5
#define KEY_6 Key::AN6
#define KEY_7 Key::AN7
#define KEY_8 Key::AN8
#define KEY_9 Key::AN9

#define KEY_A Key::A
#define KEY_B Key::B
#define KEY_C Key::C
#define KEY_D Key::D
#define KEY_E Key::E
#define KEY_F Key::F
#define KEY_G Key::G
#define KEY_H Key::H
#define KEY_I Key::I
#define KEY_J Key::J
#define KEY_K Key::K
#define KEY_L Key::L
#define KEY_M Key::M
#define KEY_N Key::N
#define KEY_O Key::O
#define KEY_P Key::P
#define KEY_Q Key::Q
#define KEY_R Key::R
#define KEY_S Key::S
#define KEY_T Key::T
#define KEY_U Key::U
#define KEY_V Key::V
#define KEY_W Key::W
#define KEY_X Key::X
#define KEY_Y Key::Y
#define KEY_Z Key::Z

#define KEY_F1 Key::F1
#define KEY_F2 Key::F2
#define KEY_F3 Key::F3
#define KEY_F4 Key::F4
#define KEY_F5 Key::F5
#define KEY_F6 Key::F6
#define KEY_F7 Key::F7
#define KEY_F8 Key::F8
#define KEY_F9 Key::F9
#define KEY_F10 Key::F10
#define KEY_F11 Key::F11
#define KEY_F12 Key::F12

#define KEY_MAX Key::Max
