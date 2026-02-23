
#pragma once

// Modify/expand to fit
#define S3D_INLINE __inline

// CRT & STL:
#include <cmath>     // std::truncf()
#include <assert.h>
#include <string.h>  // memcpy()
#include <math.h>    // sinf(), cosf(), et cetera
#include <algorithm> // std::min(), std::max()
#include <float.h>   // FLT_EPSILON

// Some primitives have a SIMD register (FIXME: solve properly for SSE, NEON et cetera)
#include <xmmintrin.h>
