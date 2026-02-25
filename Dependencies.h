
#pragma once

// Use this one if you want to manhandle functions flagged as 'fit for inlining' to actually *be* inlined
// What's best to do here depends, my first suggestion would be to analyse generated code
// A modern optimzing C++ compiler will make pretty good judgement calls if given the right incentive(s)
#define S3D_INLINE __inline

// CRT & STL:
#include <cmath>     // std::truncf()
#include <assert.h>
#include <string.h>  // memcpy()
#include <math.h>    // sinf(), cosf(), et cetera
#include <algorithm> // std::min(), std::max()
#include <float.h>   // FLT_EPSILON
#include <array>

// Some primitives have a SIMD register (FIXME: solve properly for SSE, NEON et cetera)
#include <xmmintrin.h>
