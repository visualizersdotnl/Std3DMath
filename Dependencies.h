
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

// Firstly to align Vector3/Vector4, and enable SIMD on some of these primitives.
#include <xmmintrin.h>
