#pragma once

#include <Windows.h>

#include "Common/Common.h"

#pragma comment(lib, "BlackBone")

auto __forceinline PrintMessage( const char* fmt , ... ) -> void;

#define DEV_LOG( fmt , ... ) \
{\
PrintMessage( fmt , __VA_ARGS__ );\
}
