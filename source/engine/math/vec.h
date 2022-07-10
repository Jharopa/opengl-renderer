#pragma once

#include "asserts.h"
#include "oglr_math_helper.h"

namespace math 
{
    struct vec2
    {
        vec2() = default;

        inline vec2(f32 v) noexcept : x(v), y(v) {}

        inline vec2(f32 _x, f32 _y) noexcept : x(_x), y(_y) {}

        inline f32& operator[](i32 i)
    	{
            OGLR_ASSERT_MSG(i >= 0 && i < 2, "Index out of range");
    		return ((&x)[i]);
    	}

        inline const f32& operator[](i32 i) const 
        {
            OGLR_ASSERT_MSG(i >= 0 && i < 2, "Index out of range");
            return ((&x)[i]);
        }

        union
        {
            struct{ f32 x, y; };
    		struct{ f32 r, g; };
    		struct{ f32 s, t; };
            struct{ f32 u, v; };
            f32 data[2];
        };

    };

    struct vec3
    {
        vec3() = default;

        inline vec3(f32 v) noexcept : x(v), y(v), z(v) {}

        inline vec3(f32 _x, f32 _y, f32 _z) noexcept : x(_x), y(_y), z(_z) {}

        inline f32& operator[](i32 i)
        {
            OGLR_ASSERT_MSG(i >= 0 && i < 3, "Index out of range");
            return ((&x)[i]);
        }

        inline const f32& operator[](i32 i) const
        {
            OGLR_ASSERT_MSG(i >= 0 && i < 3, "Index out of range");
            return ((&x)[i]);
        }

        union
        {
            struct{ f32 x, y, z; };
            struct{ f32 r, g, b; };
            struct{ f32 s, t, p; };
            struct{ f32 u, v, w; };
            f32 data[3];
        };
    };

    struct vec4
    {
        vec4() = default;

        inline vec4(f32 v) noexcept : x(v), y(v), z(v), w(v) {}

        inline vec4(f32 _x, f32 _y, f32 _z, f32 _w) noexcept : x(_x), y(_y), z(_z), w(_w) {}

        inline f32& operator[](i32 i)
        {
            OGLR_ASSERT_MSG(i >= 0 && i < 4, "Index out of range");
            return ((&x)[i]);
        }

        inline const f32& operator[](i32 i) const
        {
            OGLR_ASSERT_MSG(i >= 0 && i < 4, "Index out of range");
            return ((&x)[i]);
        }

        union
        {
            struct{ f32 x, y, z, w; };
            struct{ f32 r, g, b, a; };
            struct{ f32 s, t, p, q; };
            f32 data[4];
        };
    };

    // vector-vector, vector-scalar, scalar-vector addition operator
    inline vec2 operator+(const vec2& a, vec3& b) { return vec2(a.x + b.x, a.y + b.y); }
    inline vec3 operator+(const vec3& a, vec3& b) { return vec3(a.x + b.x, a.y + b.y, a.z + b.z); }
    inline vec4 operator+(const vec4& a, vec3& b) { return vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
    inline vec2 operator+(const vec2& a, f32 b) { return vec2(a.x + b, a.y + b); }
    inline vec3 operator+(const vec3& a, f32 b) { return vec3(a.x + b, a.y + b, a.z + b); }
    inline vec4 operator+(const vec4& a, f32 b) { return vec4(a.x + b, a.y + b, a.z + b, a.w + b); }
    inline vec2 operator+(const f32 a, vec2& b) { return vec2(a + b.x, a + b.y); }
    inline vec3 operator+(const f32 a, vec3& b) { return vec3(a + b.x, a + b.y, a + b.z); }
    inline vec4 operator+(const f32 a, vec4& b) { return vec4(a + b.x, a + b.y, a + b.z, a + b.w); }

    // vector-vector, vector-scalar, scalar-vector subtraction operator
    inline vec2 operator-(const vec2& a, vec3& b) { return vec2(a.x - b.x, a.y - b.y); }
    inline vec3 operator-(const vec3& a, vec3& b) { return vec3(a.x - b.x, a.y - b.y, a.z - b.z); }
    inline vec4 operator-(const vec4& a, vec3& b) { return vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }
    inline vec2 operator-(const vec2& a, f32 b) { return vec2(a.x - b, a.y - b); }
    inline vec3 operator-(const vec3& a, f32 b) { return vec3(a.x - b, a.y - b, a.z - b); }
    inline vec4 operator-(const vec4& a, f32 b) { return vec4(a.x - b, a.y - b, a.z - b, a.w - b); }
    inline vec2 operator-(const f32 a, vec2& b) { return vec2(a - b.x, a - b.y); }
    inline vec3 operator-(const f32 a, vec3& b) { return vec3(a - b.x, a - b.y, a - b.z); }
    inline vec4 operator-(const f32 a, vec4& b) { return vec4(a - b.x, a - b.y, a - b.z, a - b.w); }

    // vector-vector, vector-scalar, scalar-vector multiplication operator
    inline vec2 operator*(const vec2& a, vec3& b) { return vec2(a.x * b.x, a.y * b.y); }
    inline vec3 operator*(const vec3& a, vec3& b) { return vec3(a.x * b.x, a.y * b.y, a.z * b.z); }
    inline vec4 operator*(const vec4& a, vec3& b) { return vec4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }
    inline vec2 operator*(const vec2& a, f32 b) { return vec2(a.x * b, a.y * b); }
    inline vec3 operator*(const vec3& a, f32 b) { return vec3(a.x * b, a.y * b, a.z * b); }
    inline vec4 operator*(const vec4& a, f32 b) { return vec4(a.x * b, a.y * b, a.z * b, a.w * b); }
    inline vec2 operator*(const f32 a, vec2& b) { return vec2(a * b.x, a * b.y); }
    inline vec3 operator*(const f32 a, vec3& b) { return vec3(a * b.x, a * b.y, a * b.z); }
    inline vec4 operator*(const f32 a, vec4& b) { return vec4(a * b.x, a * b.y, a * b.z, a * b.w); }

    // vector-vector, vector-scalar, scalar-vector division operator
    inline vec2 operator/(const vec2& a, vec3& b) { return vec2(a.x / b.x, a.y / b.y); }
    inline vec3 operator/(const vec3& a, vec3& b) { return vec3(a.x / b.x, a.y / b.y, a.z / b.z); }
    inline vec4 operator/(const vec4& a, vec3& b) { return vec4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); }
    inline vec2 operator/(const vec2& a, f32 b) { return vec2(a.x / b, a.y / b); }
    inline vec3 operator/(const vec3& a, f32 b) { return vec3(a.x / b, a.y / b, a.z / b); }
    inline vec4 operator/(const vec4& a, f32 b) { return vec4(a.x / b, a.y / b, a.z / b, a.w / b); }
    inline vec2 operator/(const f32 a, vec2& b) { return vec2(a / b.x, a / b.y); }
    inline vec3 operator/(const f32 a, vec3& b) { return vec3(a / b.x, a / b.y, a / b.z); }
    inline vec4 operator/(const f32 a, vec4& b) { return vec4(a / b.x, a / b.y, a / b.z, a / b.w); }

    // Dot product of n-dimensional f32 vectors
    inline f32 dot(const vec2& a, const vec2& b) { return a.x * b.x + a.y * b.y; }
    inline f32 dot(const vec3& a, const vec3& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
    inline f32 dot(const vec4& a, const vec4& b) { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }

    // Cross product of 3-dimensional f32 vector
    inline vec3 cross(const vec3& a, vec3& b) { return vec3((a.y * b.z - a.z * b.y), (a.z * b.x - a.x * b.z), (a.x * b.y - a.y * b.x)); }

    // Magnitude of n-dimensional vectors
    inline f32 magnitude(const vec2& v) { return sqrt(dot(v, v)); }
    inline f32 magnitude(const vec3& v) { return sqrt(dot(v, v)); }
    inline f32 magnitude(const vec4& v) { return sqrt(dot(v, v)); }

    // Normalization of n-dimensional vectors
    inline vec2 normalize(const vec2& v) { return v / magnitude(v); }
    inline vec3 normalize(const vec3& v) { return v / magnitude(v); }
    inline vec4 normalize(const vec4& v) { return v / magnitude(v); }
}
