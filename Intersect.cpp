

/*
	Intersection test functions (WIP: start moving ones used in various projects over here).
*/

#include "Math.h"

namespace Std3DMath
{
	float DistancePointToLine(const Vector3 &lineDir, const Vector3 &lineOrigin, const Vector3 &point, Vector3 &pointOnLine)
	{
		const Vector3 toLine = point - lineOrigin;
		const Vector3 projected  = toLine.Project(lineDir); // Will normalize lineDir, which I'd rather assert on top since the name infers it

		// This is what you're usually after: closest point on the actual line
		pointOnLine = lineOrigin + projected;
		
		// And this is literally how far we're removed from it (FIXME: a lot of practical cases can work with the squared distance)
		return (toLine-projected).Length();
	}

	bool LineSphereIntersect(
		const Vector3 &lineDir,
    	const Vector3 &lineOrigin,
	    float lineLen,
    	const Vector3 &spherePos,
    	float sphereRadius,
    	float &outT)
	{
		const Vector3 toSphere = spherePos - lineOrigin;

		// Scalar projection gives us the component (magnitude), which is all we need
		const float projLen = toSphere*lineDir;
		
		// Early rejection (behind or beyond)
		if (projLen < 0.f || projLen > lineLen)
			return false;		

		// Distance from sphere center to line
		const float distSq =
			toSphere.LengthSq() - projLen*projLen;

		const float radiusSq = sphereRadius*sphereRadius;
		if (distSq > radiusSq)
			return false;
		
		const float offset = sqrtf(radiusSq - distSq); // To sphere surface along line
		outT = projLen-offset;

		return true;
	}
}
