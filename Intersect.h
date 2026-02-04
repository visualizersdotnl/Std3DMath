
/*
	Intersection test functions (WIP: start moving ones used in various projects over here).

	FIXME:
	- Add ray-AABB.
	- Add ray-triangle.
*/

#pragma once

namespace Std3DMath
{
	float DistancePointToLine(const Vector3 &lineDir, const Vector3 &lineOrigin, const Vector3 &point, Vector3 &pointOnLine);

	bool LineSphereIntersect(const Vector3 &lineDir, const Vector3 &lineOrigin, float lineLen,
		const Vector3 &spherePos, float sphereRadius,
		float &outT);
}
