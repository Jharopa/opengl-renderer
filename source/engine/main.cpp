#include "application.h"
#include "asserts.h"

int main()
{
    OGLR_ASSERT(sizeof(b8) == 1);
    OGLR_ASSERT(sizeof(b32) == 4);

    Application::getInstance().init();

    Application::getInstance().run();

    return 0;
}
