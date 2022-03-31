#pragma once

#include <type_traits>

// Returns value of enums underlying type
// https://stackoverflow.com/questions/11421432/how-can-i-output-the-value-of-an-enum-class-in-c11
template <typename E>
constexpr typename std::underlying_type<E>::type enumCast(E const value)
{
    return static_cast<typename std::underlying_type<E>::type>(value);
}
