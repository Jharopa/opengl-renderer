/**
 * @file oglr_math.h
 * @author Alexander Burns (jharopa@gmail.com)
 * @brief Mathematics library for graphics applications
 * including data strutures and functions for column ordered vectors and matricies,
 * along with other relevant/useful constants and funtions.
 * Based upon the math library GLM: 
 * https://github.com/g-truc/glm
 * as well as the math library mu_glm in the rendering engine Granite by Themaister: 
 * https://github.com/Themaister/Granite/tree/master/math/muglm 
 * 
 * @version 0.1
 * @date 2022-07-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <cmath>
#include <iostream>
#include <iomanip>

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
    inline f32 sin(f32 v) { return std::sin(v); }
    inline f32 cos(f32 v) { return std::cos(v); }
    inline f32 tan(f32 v) { return std::tan(v); }
    inline f32 sqrt(f32 v) { return std::sqrt(v); }
    inline f32 abs(f32 v) { return std::abs(v); }
    
    inline f32 inv(f32 v) { return 1.0f / v; }
    inline f32 radians(f32 d) { return d * OGLR_DEG2RAD_MULTI; }
    inline f32 degrees(f32 r) { return r * OGLR_RAD2DEG_MULTI; }
    inline f32 half_tan(f32 v) { return tan(v * 0.5f); }

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

    inline std::ostream& operator<<(std::ostream& os, const vec2 v)
    {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }

    inline std::ostream& operator<<(std::ostream& os, const vec3 v)
    {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }

    inline std::ostream& operator<<(std::ostream& os, const vec4 v)
    {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
        return os;
    }

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

    struct mat4
    {
        mat4() = default;

        inline mat4(f32 v) noexcept
        {
            col[0] = vec4(v, 0.0f, 0.0f, 0.0f);
            col[1] = vec4(0.0f, v, 0.0f, 0.0f);
            col[2] = vec4(0.0f, 0.0f, v, 0.0f);
            col[3] = vec4(0.0f, 0.0f, 0.0f, v);
        }

        inline mat4(const vec4& a, const vec4& b, const vec4& c, const vec4& d) noexcept
        {
            col[0] = a;
            col[1] = b;
            col[2] = c;
            col[3] = d;
        }

        inline vec4& operator[](i32 i)
        {
            OGLR_ASSERT_MSG(i >= 0 && i < 4, "Index out of range");
            return col[i];
        }

        inline const vec4& operator[](i32 i) const
        {
            OGLR_ASSERT_MSG(i >= 0 && i < 4, "Index out of range");
            return col[i];
        }

        union 
        {
            f32 elements[16];
            vec4 col[4];
        };
    };

    inline mat4 operator+(const mat4& a, const mat4& b) {
        return mat4(
            a[0] + b[0],
            a[1] + b[1],
            a[2] + b[2],
            a[3] + b[3]
        );
    }

    inline mat4 operator-(const mat4& a, const mat4& b) {
        return mat4(
            a[0] - b[0],
            a[1] - b[1],
            a[2] - b[2],
            a[3] - b[3]
        );
    }

    inline vec4 operator*(const mat4& m, const vec4& v)
    {
        return m[0] * v.x + m[1] * v.y + m[2] * v.z + m[3] * v.w;
    }

    inline mat4 operator*(const mat4& a, const mat4& b)
    {
        return mat4(a * b[0], a * b[1], a * b[2], a * b[3]);
    }

    inline std::ostream& operator<<(std::ostream& os, const mat4 m)
    {
        os << "(" << m[0] << ", " << m[1] << ", " << m[2] << ", " << m[3] << ")";
        return os;
    }

    inline mat4 identity(){ return mat4(1.0f); }

    inline mat4 transpose(const mat4& m)
    {
        return mat4(
            vec4(m[0].x, m[1].x, m[2].x, m[3].x),
            vec4(m[0].y, m[1].y, m[2].y, m[3].y),
            vec4(m[0].z, m[1].z, m[2].z, m[3].z),
            vec4(m[0].w, m[1].w, m[2].w, m[3].w)
        );
    }

    inline mat4 inverse(const mat4& m)
    {
        vec3 a = vec3(m[0].x, m[1].x, m[2].x);
        vec3 b = vec3(m[0].y, m[1].y, m[2].y);
        vec3 c = vec3(m[0].z, m[1].z, m[2].z);
        vec3 d = vec3(m[0].w, m[1].w, m[2].w);

        f32 x = m[3].x;
        f32 y = m[3].y;
        f32 z = m[3].z;
        f32 w = m[3].w;

        vec3 s = cross(a, b);
        vec3 t = cross(c, d);
        vec3 u = a * y - b * x;
        vec3 v = c * w - d * z;

        f32 inverse_determinant = inv((dot(s, v) + dot(t, u)));

        s = s * inverse_determinant;
        t = t * inverse_determinant;
        u = u * inverse_determinant;
        v = v * inverse_determinant;

        vec3 r0 = cross(b, v) + t * y;
        vec3 r1 = cross(v, a) - t * x;
        vec3 r2 = cross(d, u) + s * w;
        vec3 r3 = cross(u, c) - s * z;

        return mat4(
            vec4(r0.x, r0.y, r0.z, -dot(b, t)),
            vec4(r1.x, r1.y, r1.z, dot(a, t)),
            vec4(r2.x, r2.y, r2.z, -dot(d, s)),
            vec4(r3.x, r3.y, r3.z,  dot(c, s))
        );
    }

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
        return mat4(
            vec4(v.x, 0.0f, 0.0f, 0.0f),
            vec4(0.0f, v.y, 0.0f, 0.0f),
            vec4(0.0f, 0.0f, v.z, 0.0f),
            vec4(0.0f, 0.0f, 0.0f, 1.0f)
        );
    }

    inline mat4 perspective(f32 fov_y, f32 aspect_ratio, f32 z_near, f32 z_far)
    {
        f32 half_tan_fov_y = half_tan(fov_y);
        mat4 m = mat4(0.0f);

        m[0][0] = inv(aspect_ratio * half_tan_fov_y);
        m[1][1] = inv(half_tan_fov_y);
        m[2][2] = -((z_far + z_near) / (z_far - z_near));
        m[2][3] = -1.0f;
        m[3][2] = -((2.0f * z_far * z_near) / (z_far - z_near));

        return m;
    }

    inline mat4 look_at(const vec3& from, const vec3& to, const vec3& up)
    {
        mat4 m(1.0f);
        vec3 z_axis = normalize(to - from);
        vec3 x_axis = normalize(cross(z_axis, up));
        vec3 y_axis = cross(x_axis, z_axis);

        m[0][0] = x_axis.x;
        m[0][1] = y_axis.x;
        m[0][2] = -z_axis.x;
        m[1][0] = x_axis.y;
        m[1][1] = y_axis.y;
        m[1][2] = -z_axis.y;
        m[2][0] = x_axis.z;
        m[2][1] = y_axis.z;
        m[2][2] = -z_axis.z;
        m[3][0] = -dot(x_axis ,from);
        m[3][1] = -dot(y_axis ,from); 
        m[3][2] = dot(z_axis ,from); 

        return m;
    }
} // namespace math
