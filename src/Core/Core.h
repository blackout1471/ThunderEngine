#pragma once
#include <Application/Log.h>

#if TE_DEBUG
#define TE_ASSERT(x, ...) { if(!(x)) { TE_LOG_ERROR(__VA_ARGS__); __debugbreak(); } }
#elif TE_RELEASE
#define TE_ASSERT(x, ...) { if(!(x)) { TE_LOG_ERROR(__VA_ARGS__); } }
#else
#define TE_ASSERT(x, ...) {x;}
#endif