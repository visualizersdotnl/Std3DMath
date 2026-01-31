

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
		
		// And this is literally how far we're removed from it (FIXME: a lot of practical cases can work with the squared disance)
		return (toLine-projected).Length();
	}
}
