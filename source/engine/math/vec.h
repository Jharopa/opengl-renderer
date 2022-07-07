#pragma once

#include "asserts.h"

namespace math 
{
    template<typename T>
    struct tvec2
    {
        tvec2() = default;

        inline tvec2(T v) noexcept : x(v), y(v) {}

        inline tvec2(T _x, T _y) noexcept : x(_x), y(_y) {}

        inline T& operator[](i32 i)
    	{
            OGLR_ASSERT_MSG(i >= 0 && i < 2, "Index out of range");
    		return ((&x)[i]);
    	}

        inline const T& operator[](i32 i) const 
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
        tvec3() = default;

        inline tvec3(T v) noexcept : x(v), y(v), z(v) {}

        inline tvec3(T _x, T _y, T _z) noexcept : x(_x), y(_y), z(_z) {}

        inline T& operator[](i32 i)
        {
            OGLR_ASSERT_MSG(i >= 0 && i < 3, "Index out of range");
            return ((&x)[i]);
        }

        inline const T& operator[](i32 i) const
        {
            OGLR_ASSERT_MSG(i >= 0 && i < 3, "Index out of range");
            return ((&x)[i]);
        }

        union
        {
            struct{ T x, y, z; };
            struct{ T r, g, b; };
            struct{ T s, t, p; };
            T data[3];
        };
    };

    template<typename T>
    struct tvec4
    {
        tvec4() = default;

        inline tvec4(T v) noexcept : x(v), y(v), z(v), w(v) {}

        inline tvec4(T _x, T _y, T _z, T _w) noexcept : x(_x), y(_y), z(_z), w(_w) {}

        inline T& operator[](i32 i)
        {
            OGLR_ASSERT_MSG(i >= 0 && i < 4, "Index out of range");
            return ((&x)[i]);
        }

        inline const T& operator[](i32 i) const
        {
            OGLR_ASSERT_MSG(i >= 0 && i < 4, "Index out of range");
            return ((&x)[i]);
        }

        union
        {
            struct{ T x, y, z, w; };
            struct{ T r, g, b, a; };
            struct{ T s, t, p, q; };
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

    inline f32 dot(const vec2& a, const vec2& b) { return a.x * b.x + a.y * b.y; }
    inline f32 dot(const vec3& a, const vec3& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
    inline f32 dot(const vec4& a, const vec4& b) { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }

    inline vec3 cross(const vec3& a, vec3& b) { return vec3((a.y * b.z - a.z * b.y), (a.z * b.x - a.x * b.z), (a.x * b.y - a.y * b.x)); }
}
