
/*
	Standard C++ math primitives for 3D rendering.

	Use these whenever specific (SIMD) optimization is not necessary and ease of use is favored.
	So, about 90% of your calculations if not more.

	Notes:
	- Use either SIMD intrinsics or DirectXMath for anything that needs specific optimization.
	- This module does not reside in the Pimp namespace.
	- All angles are in radians unless explicitly stated otherwise.
*/

#if !defined(CORE_MATH)
#define CORE_MATH

const float kPI = 3.1415926535897932384626433832795f;
const float kHalfPI = kPI*0.5f;
const float kEpsilon = 5.96e-08f; // Max. error for single precision (32-bit).

// Generic floating point random.
// Has poor distribution due to rand() being 16-bit, so don't use it when proper distribution counts.
inline float randf(float range)
{
	return range*((float) rand() / RAND_MAX);
}

// Single precision compare.
inline bool comparef(float A, float B)
{
	return fabsf(A-B) < kEpsilon;
}

// GLSL copy.
inline float clampf(float min, float max, float value)
{
	return std::max<float>(max, std::min<float>(min, value));
}

// HLSL copy.
inline float saturatef(float value)
{
	return std::max<float>(0.f, std::min<float>(1.f, value));
}

// Linear interpolate.
template<typename T>
inline const T lerpf(const T &A, const T &B, float C)
{
	return A*(1.f-C) + B*C;
}

// Smooth step, Ken Perlin's take on it.
// Source: http://en.wikipedia.org/wiki/Smoothstep
float smoothstepf(float A, float B, float X)
{
	X = clampf((X-A)/(B-A), 0.f, 1.f);
	return X*X*X*(X*(X*6.f - 15.f) + 10.f);
}

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Quaternion.h"
#include "Matrix44.h"

#endif // CORE_MATH
