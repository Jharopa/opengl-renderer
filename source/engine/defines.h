#pragma once

#ifdef _WIN32
    #define PLATFORM_WINDOWS
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

// Preprocessor utilites

// Concatenates two tokens/macros
#define OGLR_CONCAT(x, y) OGR_CONCAT_H1(x, y)
#define OGLR_CONCAT_H1(x, y) OGR_CONCAT_H2(x, y)
#define OGLR_CONCAT_H2(x, y) x##y

// Converts tokens/macros to string
#define OGLR_STRINGIZE(str) OGR_STRINGIZE_H(str)
#define OGLR_STRINGIZE_H(str) #str

// Sets the n-th bit for bit masking
#define OGLR_BIT(n) (1ull << (n))

