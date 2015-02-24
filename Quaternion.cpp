
#include "Math.h"

/* static */ const Quaternion Quaternion::RotationAxisAngle(const Vector3 &axis, float angle)
{
	const Vector3 axisNormalized = axis.Normalized();
	ASSERT(true == comparef(1.f, axisNormalized.Length()));

	angle *= 0.5f;

	Quaternion quaternion(Vector4(
		axisNormalized.x*sinf(angle),
		axisNormalized.y*sinf(angle),
		axisNormalized.z*sinf(angle),
		cosf(angle)));
	return quaternion;
}

const Vector3 Quaternion::GetEulerAngles() const
{
	const float _11 = 2.f*(V.x*V.y + V.w*V.z);
	const float _12 = V.w*V.w + V.x*V.x - V.y*V.y - V.z*V.z;
	const float _21 = -2.f*(V.x*V.z - V.w*V.y);
	const float _31 = 2.f*(V.y*V.z + V.w*V.x);
	const float _32 = V.w*V.w - V.x*V.x - V.y*V.y + V.z*V.z;

	return Vector3(
		atan2f(_31, _32),
		asinf(_21),
		atan2f(_11, _12));
}

// Stolen from one of my books. Excuse the half-assed variable names.
const Quaternion Quaternion::Slerp(const Quaternion &B, float lambda)
{
	float dot = V*B.V;

	// If smaller than zero we're more than 90 degrees apart, so we can invert one to reduce spinning.
	Quaternion _B = B;
	if (dot < 0.f)
	{
		dot = -1.f;
		_B.V *= -1.f;
	}

	if (dot < 0.95f)
	{
		// Spherical.
		const float angle = acosf(dot);
		return Quaternion((V*sinf(angle*(1.f-lambda)) + _B.V*sinf(angle*lambda)) / sinf(angle));
	}
	else
	{
		// Linear (small angle);
		return Quaternion(lerpf<Vector4>(V, _B.V, lambda));
	}
}
