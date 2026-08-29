
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

		// FIXME: this is either a result by itself or distinguishes between a ray and a line (see Line)
		float t = -1.f; 
	};

	struct Line : public Ray
	{
		// FIXME: introduce 't' once you've ripped it out of Ray

		operator bool() const
		{
			// This only works (and generally it works out like that) when we're looking to avoid FTOL
			return false == std::bit_cast<unsigned>(-1.f) == std::bit_cast<unsigned>(t);
		}	
	}

//	float DistancePointToLine(const Vector3 &lineDir, const Vector3 &lineOrigin, const Vector3 point, Vector3 &outPoint); // FIXME: deprecate
	const std::tuple<float, const Vector3> DistancePointToRay(const Ray &ray, const Vector3 point);

	// FIXME: deprecate
	bool LineSphereIntersect_(const Vector3 &lineDir, const Vector3 &lineOrigin, float lineLen,
		const Vector3 &spherePos, float sphereRadius,
		float &outT);

	const std::tuple<bool, float> LineSphereIntersect(const Line &line, const Vector3 &spherePos, float sphereRadius);
		
	// FIXME: return type
	bool RayTriangleIntersect(/* const */ Ray &ray, const Vector3 &V0, const Vector3 &V1, const Vector3 &V2, bool doubleSided);
}
