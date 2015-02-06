
#include "../Platform.h"
// #include "Quaternion.h"

/* static */ const Quaternion Quaternion::RotationAxisAngle(const Vector3 &axis, float angle)
{
	// Opting for both an assertion and Normalize() here.
 	ASSERT(true == comparef(1.f, axis.Length()));
	const Vector3 axisNormalized = axis.Normalized();

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
	const float dot = V*B.V;

	lambda *= 0.5f;
	const float theta = fabsf(acosf(dot));

	const float sinT = sinf(theta);
	const float sinLT = sinf(lambda*theta);
	const float sinRevLT = sinf((1.f-lambda) * theta);

	const float coEff1 = sinRevLT/sinT;
	const float coEff2 = sinLT/sinT;

	return Quaternion((Vector4(V)*coEff1 + Vector4(B.V)*coEff2).Normalized());
}
