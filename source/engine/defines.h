#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
    #define PLATFORM_WINDOWS
    #ifndef _WIN64
        #error "32-bit Windows is an unsupported platform!"
    #endif
#elif
    #error "Unsupported platform!"
#endif

#ifdef _MSC_VER
    #define STATIC_ASSERT static_assert
#else
    #error "Unsupported compiler!"
#endif

// Unsinged integer types
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// Signed integer types
typedef char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

// Floating point types
typedef float f32;
typedef double f64;

// Boolean types
typedef bool b8;
typedef int b32;

// Ensure typedefed aliases are of the right size.
STATIC_ASSERT(sizeof(u8) == 1, "Type u8 was not expected size of 1 byte.");
STATIC_ASSERT(sizeof(u16) == 2, "Type u8 was not expected size of 2 bytes.");
STATIC_ASSERT(sizeof(u32) == 4, "Type u8 was not expected size of 4 bytes.");
STATIC_ASSERT(sizeof(u64) == 8, "Type u8 was not expected size of 8 bytes.");

STATIC_ASSERT(sizeof(i8) == 1, "Type u8 was not expected size of 1 byte.");
STATIC_ASSERT(sizeof(i16) == 2, "Type u8 was not expected size of 2 bytes.");
STATIC_ASSERT(sizeof(i32) == 4, "Type u8 was not expected size of 4 bytes.");
STATIC_ASSERT(sizeof(i64) == 8, "Type u8 was not expected size of 8 bytes.");

STATIC_ASSERT(sizeof(f32) == 4, "Type u8 was not expected size of 4 bytes.");
STATIC_ASSERT(sizeof(f64) == 8, "Type u8 was not expected size of 8 bytes.");

STATIC_ASSERT(sizeof(b8) == 1, "Type u8 was not expected size of 1 byte.");
STATIC_ASSERT(sizeof(b32) == 4, "Type u8 was not expected size of 4 bytes.");

// Preprocessor utilites

// Concatenates two tokens
#define OGLR_CONCAT(x, y) OGLR_CONCAT_INNER(x, y)
#define OGLR_CONCAT_INNER(x, y) x##y

// Converts token to string
#define OGLR_STRINGIZE(str) #str

// Sets the n-th bit for bit masking
#define OGLR_BIT(n) (1ull << (n))

// Hardcoded marco switches <-- This is bad >:(
#define ASSERTIONS_ENABLED 1
#define PROFILER_ENABLED 1
