#pragma once

#include "defines.h"

// types
#include <limits>
#include <string>
#include <cctype>
#include <sstream>
#include <type_traits>

// containers
#include <iterator>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <list>
#include <vector>
#include <array>

// utilities
#include <iostream>
#include <cassert>
#include <cmath>
#include <memory>
#include <functional>
#include <algorithm>
#include <utility>
#include <tuple>

#ifdef PLATFORM_WINDOWS

#include <windows.h>
#define WIN32_LEAN_AND_MEAN

#endif
