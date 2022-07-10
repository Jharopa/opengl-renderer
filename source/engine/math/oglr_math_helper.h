#pragma once

#include <cmath>

#include "defines.h"

#include "vec.h"

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
#define OGLR_RAD2DEG_MULTI OGLR_PI / 180.0f

namespace math
{
    f32 sin(f32 v) { return std::sin(v); }
    f32 cos(f32 v) { return std::cos(v); }
    f32 tan(f32 v) { return std::tan(v); }
    f32 sqrt(f32 v) { return std::sqrt(v); }
    f32 abs(f32 v) { return std::abs(v); }
}
