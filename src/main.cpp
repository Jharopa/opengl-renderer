// STD library includes
#include <iostream>

// My includes
#include "window.h"

int main()
{
    Window window = Window{ 800, 600, "Window" };

    while(!window.shouldClose())
    {
        window.update();
    }

    return 0;
}
