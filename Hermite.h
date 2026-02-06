
/*
    Hermite spline functions.

    Hermite splines are a variation on Bezier splines:
    - They use and always pass through 2 control points (each with a corresponding direction or tangent, if you will), whereas
      in bezier splines the 4 control points more or less act like attractors.
    - The mathematical basis is more or less identical.

    Two excellent resources on the matter:
    - A proper Youtube video on Quadratric/Cubic Bezier splines by Freya Holmer: https://youtu.be/aVwxzDHniEw
    - Article on implementing these for use with unit quaternions: https://theorangeduck.com/page/cubic-interpolation-quaternions
*/

#pragma once

namespace Std3DMath
{
}
