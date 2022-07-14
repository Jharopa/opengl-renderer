#pragma once

#include <cmath>

#include "defines.h"
#include "asserts.h"

#define OGLR_PI 3.14159265358979323846f
#define OGLR_TAU 2.0f * OGLR_PI
#define OGLR_HALF_PI 0.5f * OGLR_PI
#define OGLR_QUART_PI 0.25f * OGLR_PI
#define OGLR_INV_PI 1.0f / OGLR_PI
#define OGLR_INV_TAU 1.0f / OGLR_TAU
#define OGLR_SQRT_TWO 1.41421356237309504880f
#define OGLR_SQRT_THREE 1.73205080756887729352f
#define OGLR_INV_SQRT_TWO 0.70710678118654752440f
#define OGLR_INV_SQRT_THREE 0.57735026918962576450f
#define OGLR_DEG2RAD_MULTI OGLR_PI / 180.0f
#define OGLR_RAD2DEG_MULTI 180.0f / OGLR_PI

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
            f32 elements[2];
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
            f32 elements[3];
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
            f32 elements[4];
        };
    };

    struct mat4
    {
        mat4() = default;

        inline mat4(f32 v) noexcept
        {
            vec[0] = vec4(v, 0.0f, 0.0f, 0.0f);
            vec[1] = vec4(0.0f, v, 0.0f, 0.0f);
            vec[2] = vec4(0.0f, 0.0f, v, 0.0f);
            vec[3] = vec4(0.0f, 0.0f, 0.0f, v);
        }

        inline mat4(const vec4& a, const vec4& b, const vec4& c, const vec4& d) noexcept
        {
            vec[0] = a;
            vec[1] = b;
            vec[2] = c;
            vec[3] = d;
        }

        inline vec4& operator[](i32 i)
        {
            OGLR_ASSERT_MSG(i >= 0 && i < 4, "Index out of range");
            return vec[i];
        }

        inline const vec4& operator[](i32 i) const
        {
            OGLR_ASSERT_MSG(i >= 0 && i < 4, "Index out of range");
            return vec[i];
        }
        
        union
        {
            vec4 vec[4];
            f32 elements[16];
        };
    };

    inline f32 sin(f32 v) { return std::sin(v); }
    inline f32 cos(f32 v) { return std::cos(v); }
    inline f32 tan(f32 v) { return std::tan(v); }
    inline f32 sqrt(f32 v) { return std::sqrt(v); }
    inline f32 abs(f32 v) { return std::abs(v); }
    inline f32 inv(f32 v) { return 1.0f / v; }

    inline f32 radians(f32 d) { return d * OGLR_DEG2RAD_MULTI; }
    inline f32 degrees(f32 r) { return r * OGLR_RAD2DEG_MULTI; }
    inline f32 half_tan(f32 v) { return tan(v * 0.5f); }

    // vector-vector, vector-scalar, scalar-vector addition operator
    inline vec2 operator+(const vec2& a, const vec2& b) { return vec2(a.x + b.x, a.y + b.y); }
    inline vec3 operator+(const vec3& a, const vec3& b) { return vec3(a.x + b.x, a.y + b.y, a.z + b.z); }
    inline vec4 operator+(const vec4& a, const vec4& b) { return vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
    inline vec2 operator+(const vec2& a, const f32& b) { return vec2(a.x + b, a.y + b); }
    inline vec3 operator+(const vec3& a, const f32& b) { return vec3(a.x + b, a.y + b, a.z + b); }
    inline vec4 operator+(const vec4& a, const f32& b) { return vec4(a.x + b, a.y + b, a.z + b, a.w + b); }
    inline vec2 operator+(const f32& a, const vec2& b) { return vec2(a + b.x, a + b.y); }
    inline vec3 operator+(const f32& a, const vec3& b) { return vec3(a + b.x, a + b.y, a + b.z); }
    inline vec4 operator+(const f32& a, const vec4& b) { return vec4(a + b.x, a + b.y, a + b.z, a + b.w); }

    // vector-vector, vector-scalar, scalar-vector subtraction operator
    inline vec2 operator-(const vec2& a, const vec2& b) { return vec2(a.x - b.x, a.y - b.y); }
    inline vec3 operator-(const vec3& a, const vec3& b) { return vec3(a.x - b.x, a.y - b.y, a.z - b.z); }
    inline vec4 operator-(const vec4& a, const vec4& b) { return vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }
    inline vec2 operator-(const vec2& a, const f32& b) { return vec2(a.x - b, a.y - b); }
    inline vec3 operator-(const vec3& a, const f32& b) { return vec3(a.x - b, a.y - b, a.z - b); }
    inline vec4 operator-(const vec4& a, const f32& b) { return vec4(a.x - b, a.y - b, a.z - b, a.w - b); }
    inline vec2 operator-(const f32& a, const vec2& b) { return vec2(a - b.x, a - b.y); }
    inline vec3 operator-(const f32& a, const vec3& b) { return vec3(a - b.x, a - b.y, a - b.z); }
    inline vec4 operator-(const f32& a, const vec4& b) { return vec4(a - b.x, a - b.y, a - b.z, a - b.w); }

    // vector-vector, vector-scalar, scalar-vector multiplication operator
    inline vec2 operator*(const vec2& a, const vec2& b) { return vec2(a.x * b.x, a.y * b.y); }
    inline vec3 operator*(const vec3& a, const vec3& b) { return vec3(a.x * b.x, a.y * b.y, a.z * b.z); }
    inline vec4 operator*(const vec4& a, const vec4& b) { return vec4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }
    inline vec2 operator*(const vec2& a, const f32& b) { return vec2(a.x * b, a.y * b); }
    inline vec3 operator*(const vec3& a, const f32& b) { return vec3(a.x * b, a.y * b, a.z * b); }
    inline vec4 operator*(const vec4& a, const f32& b) { return vec4(a.x * b, a.y * b, a.z * b, a.w * b); }
    inline vec2 operator*(const f32& a, const vec2& b) { return vec2(a * b.x, a * b.y); }
    inline vec3 operator*(const f32& a, const vec3& b) { return vec3(a * b.x, a * b.y, a * b.z); }
    inline vec4 operator*(const f32& a, const vec4& b) { return vec4(a * b.x, a * b.y, a * b.z, a * b.w); }

    // vector-vector, vector-scalar, scalar-vector division operator
    inline vec2 operator/(const vec2& a, const vec2& b) { return vec2(a.x / b.x, a.y / b.y); }
    inline vec3 operator/(const vec3& a, const vec3& b) { return vec3(a.x / b.x, a.y / b.y, a.z / b.z); }
    inline vec4 operator/(const vec4& a, const vec4& b) { return vec4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); }
    inline vec2 operator/(const vec2& a, const f32& b) { return vec2(a.x / b, a.y / b); }
    inline vec3 operator/(const vec3& a, const f32& b) { return vec3(a.x / b, a.y / b, a.z / b); }
    inline vec4 operator/(const vec4& a, const f32& b) { return vec4(a.x / b, a.y / b, a.z / b, a.w / b); }
    inline vec2 operator/(const f32& a, const vec2& b) { return vec2(a / b.x, a / b.y); }
    inline vec3 operator/(const f32& a, const vec3& b) { return vec3(a / b.x, a / b.y, a / b.z); }
    inline vec4 operator/(const f32& a, const vec4& b) { return vec4(a / b.x, a / b.y, a / b.z, a / b.w); }

    // Dot product of 2D, 3D, and 4D vectors
    inline f32 dot(const vec2& a, const vec2& b) { return a.x * b.x + a.y * b.y; }
    inline f32 dot(const vec3& a, const vec3& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
    inline f32 dot(const vec4& a, const vec4& b) { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }

    // Cross product of 3D vector
    inline vec3 cross(const vec3& a, const vec3& b) { return vec3((a.y * b.z - a.z * b.y), (a.z * b.x - a.x * b.z), (a.x * b.y - a.y * b.x)); }

    // Magnitude of 2D, 3D, and 4D vectors
    inline f32 magnitude(const vec2& v) { return sqrt(dot(v, v)); }
    inline f32 magnitude(const vec3& v) { return sqrt(dot(v, v)); }
    inline f32 magnitude(const vec4& v) { return sqrt(dot(v, v)); }

    // Normalization of 2D, 3D, and 4D vectors
    inline vec2 normalize(const vec2& v) { return v * inv(magnitude(v)); }
    inline vec3 normalize(const vec3& v) { return v * inv(magnitude(v)); }
    inline vec4 normalize(const vec4& v) { return v * inv(magnitude(v)); }

    // 3D vectors up, down, left, right, forward, and backward
    inline vec3 up() { return vec3(0.0f, 1.0f, 0.0f); }
    inline vec3 down() { return vec3(0.0f, -1.0f, 0.0f); }
    inline vec3 left() { return vec3(-1.0f, 0.0f, 0.0f); }
    inline vec3 right() { return vec3(1.0f, 0.0f, 0.0f); }
    inline vec3 froward() { return vec3(0.0f, 0.0f, -1.0f); }
    inline vec3 backward() { return vec3(0.0f, 0.0f, 1.0f); }

    inline vec4 operator*(const vec4& v, const mat4& m)
    {
        return vec4(
            v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0] + v.w * m[3][0],
            v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1] + v.w * m[3][1],
            v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2] + v.w * m[3][2],
            v.x * m[0][3] + v.y * m[1][3] + v.z * m[2][3] + v.w * m[3][3]
        );
    }

    inline mat4 operator*(const mat4& a, const mat4& b)
    {
        mat4 m;

        for (u8 i = 0; i < 4; i++)
        {
            for (u8 j = 0; j < 4; j++)
            {
                m[i][j] = a[i][0] * b[0][j] +
                          a[i][1] * b[1][j] +
                          a[i][2] * b[2][j] +
                          a[i][3] * b[3][j];
            }
        }

        return m;
    }

    inline mat4 identity(){ return mat4(1.0f); }

    inline mat4 translate(const vec3& v)
    {
        return mat4(
            vec4(1.0f, 0.0f, 0.0f, 0.0f),
            vec4(0.0f, 1.0f, 0.0f, 0.0f),
            vec4(0.0f, 0.0f, 1.0f, 0.0f),
            vec4(v.x, v.y, v.z, 1.0f)
        );
    }

    inline mat4 scale(const vec3& v)
    {
        mat4 m = identity();

        m.elements[0] = v.x;
        m.elements[5] = v.y;
        m.elements[10] = v.z;

        return m;
    }

    inline mat4 perspective(f32 fov_y, f32 aspect_ratio, f32 z_near, f32 z_far)
    {
        f32 half_tan_fov_y = half_tan(fov_y);
        mat4 m = mat4(0.0f);

        m.elements[0] = inv(aspect_ratio * half_tan_fov_y);
        m.elements[5] = inv(half_tan_fov_y);
        m.elements[10] = -((z_far + z_near) / (z_far - z_near));
        m.elements[11] = -1.0f;
        m.elements[14] = -((2.0f * z_far * z_near) / (z_far - z_near));

        return m;
    }

    inline mat4 look_at(const vec3& from, const vec3& to, const vec3& up)
    {
        mat4 m(1.0f);
        vec3 z_axis = normalize(to - from);
        vec3 x_axis = normalize(cross(z_axis, up));
        vec3 y_axis = cross(x_axis, z_axis);

        m.elements[0] = x_axis.x;
        m.elements[1] = y_axis.x;
        m.elements[2] = -z_axis.x;
        m.elements[4] = x_axis.y;
        m.elements[5] = y_axis.y;
        m.elements[6] = -z_axis.y;
        m.elements[8] = x_axis.z;
        m.elements[9] = y_axis.z;
        m.elements[10] = -z_axis.z;
        m.elements[12] = -dot(x_axis ,from);
        m.elements[13] = -dot(y_axis ,from); 
        m.elements[14] = dot(z_axis ,from); 

        return m;
    }
}
