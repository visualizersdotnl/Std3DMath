
/*
	Standard C++ math primitives for 3D rendering.
	
	(c) visualizers.nl
	License: MIT (see LICENSE)

	Please check README.md for more information.
*/

#if !defined(STD_3D_MATH)
#define STD_3D_MATH

#include "Dependencies.h"

// A few meaningful constants.
const float kPI = 3.1415926535897932384626433832795f;
const float kHalfPI = kPI*0.5f;
const float kEpsilon = 5.96e-08f; // Max. error for single precision (32-bit).
const float kGoldenRatio = 1.61803398875f;

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

// GLSL style clamp.
inline float clampf(float min, float max, float value)
{
	return std::max<float>(max, std::min<float>(min, value));
}

// HLSL saturate().
inline float saturatef(float value)
{
	return std::max<float>(0.f, std::min<float>(1.f, value));
}

template<typename T>
inline const T lerpf(const T &A, const T &B, float T)
{
	return A*(1.f-T) + B*T;
}

// Ken Perlin's take on Smoothstep.
// Source: http://en.wikipedia.org/wiki/Smoothstep
inline float smoothstepf(float A, float B, float T)
{
	const float X = saturatef(T);
	return lerpf<float>(A, B, X*X*X * (X*(X*6.f - 15.f) + 10.f));
}

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Quaternion.h"
#include "Matrix44.h"

#endif // STD_3D_MATH
