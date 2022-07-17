#include "log.h"

#if ASSERTIONS_ENABLED
    #define debugBreak() __debugbreak()

    #define OGLR_ASSERT(expression)                                                                                     \
    {                                                                                                                   \
        if (expression) {}                                                                                              \
        else                                                                                                            \
        {                                                                                                               \
            OGLR_FATAL("Assertion failure: {} - file: {} - line: {}", OGLR_STRINGIZE(expression), __FILE__, __LINE__);  \
            debugBreak();                                                                                               \
        }                                                                                                               \
    }

    #define OGLR_ASSERT_MSG(expression, message)                                                                                        \
    {                                                                                                                                   \
        if (expression) {}                                                                                                              \
        else                                                                                                                            \
        {                                                                                                                               \
            OGLR_FATAL("Assertion failure: {} - message: {} - file: {} - line: {}", OGLR_STRINGIZE(expression), message, __FILE__, __LINE__);    \
            debugBreak();                                                                                                               \
        }                                                                                                                               \
    }
#else
    #define OGLR_ASSERT(expression)
    #define OGLR_ASSERT_MSG(expression, message)
#endif