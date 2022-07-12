#pragma once

#include "asserts.h"
#include "math_functions.h"
#include "vec.h"

namespace math
{
    struct mat4
    {
        mat4() = default;

        inline mat4(f32 v) noexcept
        {
            rows[0] = vec4(v, 0.0f, 0.0f, 0.0f);
            rows[1] = vec4(0.0f, v, 0.0f, 0.0f);
            rows[2] = vec4(0.0f, 0.0f, v, 0.0f);
            rows[3] = vec4(0.0f, 0.0f, 0.0f, v);
        }

        inline mat4(const vec4& a, const vec4& b, const vec4& c, const vec4& d) noexcept
        {
            rows[0] = a;
            rows[1] = b;
            rows[2] = c;
            rows[3] = d;
        }

        inline vec4& operator[](i32 i)
        {
            OGLR_ASSERT_MSG(i >= 0 && i < 4, "Index out of range");
            return rows[i];
        }

        inline const vec4& operator[](i32 i) const
        {
            OGLR_ASSERT_MSG(i >= 0 && i < 4, "Index out of range");
            return rows[i];
        }

        union
        {
            vec4 rows[4];
            f32 elements[16];
        };
    };

    inline vec4 operator*(const mat4& m, const vec4& v)
    {
        return vec4(
            m[0].x * v.x + m[0].y * v.y + m[0].z * v.z + m[0].w * v.w,
            m[1].x * v.x + m[1].y * v.y + m[1].z * v.z + m[1].w * v.w,
            m[2].x * v.x + m[2].y * v.y + m[2].z * v.z + m[2].w * v.w,
            m[3].x * v.x + m[3].y * v.y + m[3].z * v.z + m[3].w * v.w
        );
    }

    inline mat4 operator*(const mat4& a, const mat4& b)
    {
        vec4 v_a(
            a[0].x * b[0].x + a[0].y * b[1].x + a[0].z * b[2].x + a[0].w * b[3].x,
            a[0].x * b[0].y + a[0].y * b[1].y + a[0].z * b[2].y + a[0].w * b[3].y,
            a[0].x * b[0].z + a[0].y * b[1].z + a[0].z * b[2].z + a[0].w * b[3].z,
            a[0].x * b[0].w + a[0].y * b[1].w + a[0].z * b[2].w + a[0].w * b[3].w
        );

        vec4 v_b(
            a[1].x * b[0].x + a[1].y * b[1].x + a[1].z * b[2].x + a[1].w * b[3].x,
            a[1].x * b[0].y + a[1].y * b[1].y + a[1].z * b[2].y + a[1].w * b[3].y,
            a[1].x * b[0].z + a[1].y * b[1].z + a[1].z * b[2].z + a[1].w * b[3].z,
            a[1].x * b[0].w + a[1].y * b[1].w + a[1].z * b[2].w + a[1].w * b[3].w
        );

        vec4 v_c(
            a[2].x * b[0].x + a[2].y * b[1].x + a[2].z * b[2].x + a[2].w * b[3].x,
            a[2].x * b[0].y + a[2].y * b[1].y + a[2].z * b[2].y + a[2].w * b[3].y,
            a[2].x * b[0].z + a[2].y * b[1].z + a[2].z * b[2].z + a[2].w * b[3].z,
            a[2].x * b[0].w + a[2].y * b[1].w + a[2].z * b[2].w + a[2].w * b[3].w
        );

        vec4 v_d(
            a[3].x * b[0].x + a[3].y * b[1].x + a[3].z * b[2].x + a[3].w * b[3].x,
            a[3].x * b[0].y + a[3].y * b[1].y + a[3].z * b[2].y + a[3].w * b[3].y,
            a[3].x * b[0].z + a[3].y * b[1].z + a[3].z * b[2].z + a[3].w * b[3].z,
            a[3].x * b[0].w + a[3].y * b[1].w + a[3].z * b[2].w + a[3].w * b[3].w
        );

        return mat4(v_a, v_b, v_c, v_d);
    }

    inline mat4 identity(){ return mat4(1.0f); }

    inline mat4 perspective(f32 fov_y, f32 aspect_ratio, f32 z_near, f32 z_far)
    {
        f32 half_tan_fov_y = half_tan(fov_y);
        mat4 m = mat4(0.0f);

        m.elements[0] = 1.0f / (aspect_ratio * half_tan_fov_y);
        m.elements[5] = 1.0f / half_tan_fov_y;
        m.elements[10] = -((z_far + z_near) / (z_far - z_near));
        m.elements[11] = -1.0f;
        m.elements[14] = -((2.0f * z_far * z_near) / (z_far - z_near));

        return m;
    }

    inline mat4 look_at(vec3 from, vec3 to, vec3 up)
    {
        mat4 m(0.0f);
        vec3 z_axis = normalize(to - from);
        vec3 x_axis = cross(normalize(up), z_axis);
        vec3 y_axis = cross(z_axis, x_axis)

        m.elements[0] = x_axis.x;
        m.elements[1] = x_axis.y;
        m.elements[2] = x_axis.z;
        m.elements[4] = y_axis.x;
        m.elements[5] = y_axis.y;
        m.elements[6] = y_axis.z;
        m.elements[8] = z_axis.x;
        m.elements[9] = z_axis.y;
        m.elements[10] = z_axis.z;
        m.elements[12] = from.x;
        m.elements[13] = from.y; 
        m.elements[14] = from.z; 

        return m;
    }
}
