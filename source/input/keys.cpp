#include "keys.h"

std::ostream& operator <<(std::ostream& os, Key key)
{
    switch (key)
    {
        case KEY_UNKNOWN: os << "Unknown"; break;

        case KEY_BACKSPACE: os << "Backspace"; break;
        case KEY_ENTER: os << "Enter"; break;
        case KEY_SHIFT: os << "Shift"; break;
        case KEY_CONTROL: os << "Control"; break;
        case KEY_PAUSE: os << "Pause"; break;
        case KEY_CAPS: os << "Caps"; break;
        case KEY_ESCAPE: os << "Escape"; break;
        case KEY_SPACE: os << "Space"; break;
        case KEY_INSERT: os << "Insert"; break;
        case KEY_HOME: os << "Home"; break;
        case KEY_DELETE: os << "Delete"; break;
        case KEY_END: os << "End"; break;
        
        case KEY_UP: os << "Up"; break;
        case KEY_DOWN: os << "Down"; break;
        case KEY_LEFT: os << "Left"; break;
        case KEY_RIGHT: os << "Right"; break;

        case KEY_0: os << "0"; break;
        case KEY_1: os << "1"; break;
        case KEY_2: os << "2"; break;
        case KEY_3: os << "3"; break;
        case KEY_4: os << "4"; break;
        case KEY_5: os << "5"; break;
        case KEY_6: os << "6"; break;
        case KEY_7: os << "7"; break;
        case KEY_8: os << "8"; break;
        case KEY_9: os << "9"; break;

        case KEY_A: os << "A"; break;
        case KEY_B: os << "B"; break;
        case KEY_C: os << "C"; break;
        case KEY_D: os << "D"; break;
        case KEY_E: os << "E"; break;
        case KEY_F: os << "F"; break;
        case KEY_G: os << "G"; break;
        case KEY_H: os << "H"; break;
        case KEY_I: os << "I"; break;
        case KEY_J: os << "J"; break;
        case KEY_K: os << "K"; break;
        case KEY_L: os << "L"; break;
        case KEY_M: os << "M"; break;
        case KEY_N: os << "N"; break;
        case KEY_O: os << "O"; break;
        case KEY_P: os << "P"; break;
        case KEY_Q: os << "Q"; break;
        case KEY_R: os << "R"; break;
        case KEY_S: os << "S"; break;
        case KEY_T: os << "T"; break;
        case KEY_U: os << "U"; break;
        case KEY_V: os << "V"; break;
        case KEY_W: os << "W"; break;
        case KEY_X: os << "X"; break;
        case KEY_Y: os << "Y"; break;
        case KEY_Z: os << "Z"; break;

        case KEY_F1: os << "F1"; break;
        case KEY_F2: os << "F2"; break;
        case KEY_F3: os << "F3"; break;
        case KEY_F4: os << "F4"; break;
        case KEY_F5: os << "F5"; break;
        case KEY_F6: os << "F6"; break;
        case KEY_F7: os << "F7"; break;
        case KEY_F8: os << "F8"; break;
        case KEY_F9: os << "F9"; break;
        case KEY_F10: os << "F10"; break;
        case KEY_F11: os << "F11"; break;
        case KEY_F12: os << "F12"; break;

        case KEY_MAX: os << "Max"; break;

        default: os << "Error!"; break;
    };

    return os;
}
