
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
	// FIXME: flesh out further
	struct Ray 
	{
		Vector3 origin;
		Vector3 direction;
		float t = -1.f; 
	};

	// FIXME: what is the wisest thing to do here, or rather, modern C++ way, instead of having 2 closely related structures *or* naive inheritance?
	struct Line 
	{

	};

	float DistancePointToLine(const Vector3 &lineDir, const Vector3 &lineOrigin, const Vector3 &point, Vector3 &outPoint);

	bool LineSphereIntersect(const Vector3 &lineDir, const Vector3 &lineOrigin, float lineLen,
		const Vector3 &spherePos, float sphereRadius,
		float &outT);

	// FIXME: you can see that my need here to feed it a non-const ray more or less suggests something dirty is going on here!
	bool RayTriangleIntersect(/* const */ Ray &ray, const Vector3 &V0, const Vector3 &V1, const Vector3 &V2, bool doubleSided);
}
