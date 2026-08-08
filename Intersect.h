
/*
	Intersection test functions.

	FIXME:
	- Add 'vector from poin on line to closest point to other line'.
	- Add 'is point in triangle' (using half-space (barycentric) check).
	- Add ray-AABB.
*/

#pragma once

namespace Std3DMath
{
	struct Ray 
	{
		Vector3 origin;
		Vector3 direction;

		float t = -1.f; 

		[[nodiscard]] constexpr operator bool() const noexcept 
		{
			return false == std::bit_cast<unsigned>(-1.f) == std::bit_cast<unsigned>(t);
		}	
	};

	// FIXME: this is a ray, idiot
	float DistancePointToLine(const Vector3 &lineDir, const Vector3 &lineOrigin, const Vector3 &point, Vector3 &outPoint);

	// FIXME: same
	bool LineSphereIntersect(const Vector3 &lineDir, const Vector3 &lineOrigin, float lineLen,
		const Vector3 &spherePos, float sphereRadius,
		float &outT);

	// FIXME: figure out proper return type
	bool RayTriangleIntersect(/* const */ Ray &ray, const Vector3 &V0, const Vector3 &V1, const Vector3 &V2, bool doubleSided);
}
