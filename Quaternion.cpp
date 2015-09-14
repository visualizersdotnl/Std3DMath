
#include "Math.h"

/* static */ const Quaternion Quaternion::Identity()
{
	return Quaternion(Vector4(0.f, 0.f, 0.f, 1.f));
}

/* static */ const Quaternion Quaternion::AxisAngle(const Vector3 &axis, float angle)
{
	const Vector3 unitAxis = axis.Normalized();
	angle *= 0.5f;
	return Quaternion(Vector4(unitAxis*sinf(angle), cosf(angle)));
}

/* static */ const Quaternion Quaternion::Slerp(const Quaternion &A, const Quaternion &B, float T)
{
	float dot = Dot(A, B);
	if (dot > 0.9995f)
	{
		// Very small angle: interpolate linearly.
		return Quaternion(lerpf<Vector4>(A, B, T).Normalized());
	}

	// Clamp to acos() domain.
	dot = clampf(-1.f, 1.f, dot);

	float theta = acosf(dot);
	float phi = theta*T;

	// Orthonormal basis.
	Vector4 basis = (B - Scale(A, dot)).Normalized();

	return Quaternion(Vector4::Scale(A, cosf(theta)) + basis*sinf(theta));
}
