

/*
	Intersection test functions (WIP: start moving ones used in various projects over here).
*/

#include "Math.h"

namespace Std3DMath
{
	const Vector3 DistanceToLine(const Vector3 &line, const Vector3 &origin, const Vector3 &point)
	{
//		assert(line.LengthSq() == 1.f);

		// Normalize line.
		const Vector3 direction = line.Normalized();

		// Calculating this side gives us the second side of the triangle.
		const Vector3 side = origin-point;

		/*
			Dot product of said side and the direction equals the distance
			between the origin and the point on the line we're looking for.

			Can also be expressed as 'cos(angle)*|side|', where angle is the angle between
			the 2 vectors we have and the length of our freshly calculated side.
		*/

		const float distance = side*direction;
		return origin + direction*distance;
	}
}
