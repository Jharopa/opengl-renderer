#pragma once

#include <cmath>

#include "defines.h"

#include "math_constants.h"

namespace math
{
    f32 sin(f32 v) { return std::sin(v); }
    f32 cos(f32 v) { return std::cos(v); }
    f32 tan(f32 v) { return std::tan(v); }
    f32 sqrt(f32 v) { return std::sqrt(v); }
    f32 abs(f32 v) { return std::abs(v); }

    f32 radians(f32 d) { return d * OGLR_DEG2RAD_MULTI; }
    f32 degrees(f32 r) { return r * OGLR_RAD2DEG_MULTI; }
    f32 half_tan(f32 v) { return tan(v * 0.5f); }
}
