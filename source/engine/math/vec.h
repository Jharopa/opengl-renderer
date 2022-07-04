#pragma once

#include "asserts.h"

template<typename T>
struct tvec2
{
    tvec2() noexcept : x(0), y(0) {}

    tvec2(T v) noexcept : x(v), y(v) {}

    tvec2(T _x, T _y) noexcept : x(_x), y(_y) {}

    T& operator[](i32 i)
	{
        OGLR_ASSERT_MSG(i >= 0 && i < 2, "Index out of range");
		return ((&x)[i]);
	}

    const T& operator[](i32 i) const 
    {
        OGLR_ASSERT_MSG(i >= 0 && i < 2, "Index out of range");
        return ((&x)[i]);
    }

    union
    {
        struct{ T x, y; };
		struct{ T r, g; };
		struct{ T s, t; };
        T data[2];
    };
    
};

template<typename T>
struct tvec3
{
    tvec3() noexcept : x(0), y(0), z(0) {}

    tvec3(T v) noexcept : x(v), y(v), z(v) {}

    tvec3(T _x, T _y, T _z) noexcept : x(_x), y(_y), z(_z) {}

    T& operator[](i32 i)
    {
        OGLR_ASSERT_MSG(i >= 0 && i < 3, "Index out of range");
        return ((&x)[i]);
    }

    const T& operator[](i32 i) const
    {
        OGLR_ASSERT_MSG(i >= 0 && i < 3, "Index out of range");
        return ((&x)[i]);
    }

    union
    {
        struct{ T x, y, z; };
        struct{ T r, g, b; };
        struct{ T s, t, u; };
        T data[3];
    };
};

template<typename T>
struct tvec4
{
    tvec4() noexcept : x(0), y(0), z(0), w(0) {}

    tvec4(T v) noexcept : x(v), y(v), z(v), w(v) {}

    tvec4(T _x, T _y, T _z, T _w) noexcept : x(_x), y(_y), z(_z), w(_w) {}

    T& operator[](i32 i)
    {
        OGLR_ASSERT_MSG(i >= 0 && i < 4, "Index out of range");
        return ((&x)[i]);
    }

    const T& operator[](i32 i) const
    {
        OGLR_ASSERT_MSG(i >= 0 && i < 4, "Index out of range");
        return ((&x)[i]);
    }

    union
    {
        struct{ T x, y, z, w; };
        struct{ T r, g, b, a; };
        struct{ T s, t, u, v; };
        T data[4];
    };
};

using vec2 = tvec2<f32>;
using vec3 = tvec3<f32>;
using vec4 = tvec4<f32>;

using dvec2 = tvec2<f64>;
using dvec3 = tvec3<f64>;
using dvec4 = tvec4<f64>;

using uvec2 = tvec2<u32>;
using uvec3 = tvec3<u32>;
using uvec4 = tvec4<u32>;

using ivec2 = tvec2<i32>;
using ivec3 = tvec3<i32>;
using ivec4 = tvec4<i32>;
