
#pragma once

// CRT & STL:
#include <string.h>  // memcpy()
#include <math.h>    // sinf(), cosf(), et cetera
#include <algorithm> // std::min, std::max

// ** Please specify your own ASSERT macro here! **
#if !defined(ASSERT)
	#define ASSERT(condition)
#endif
