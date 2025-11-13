#pragma once

#include <stdint.h>

#if defined(__x86_64__) || defined(_WIN64)
#define X64BITS
#endif

typedef unsigned char uint8;
typedef signed char int8;
typedef float float32;

#if defined( _WIN32 )

typedef __int16 int16;
typedef unsigned __int16 uint16;
typedef __int32 int32;
typedef unsigned __int32 uint32;
typedef __int64 int64;
typedef unsigned __int64 uint64;

typedef uint32 uint;
typedef int64 lint64;
typedef uint64 ulint64;

#ifdef X64BITS
typedef __int64 intp;
typedef unsigned __int64 uintp;
#else
typedef __int32 intp;
typedef unsigned __int32 uintp;
#endif

#endif

struct ResourceBindingBase_t
{
	void* data;
};
