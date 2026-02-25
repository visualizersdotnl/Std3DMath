
/*
    Hermite spline functions.

    The Hermite (or Catmull-Rom to be specific) spline has enough continuity and the operations can be expressed as a result of just
    a set of 2 control points, that are gauranteed to be passed through.

    These are excellent for camera paths, animation and the likes.
    Be careful with geometry generation (normal generation et al; Freya's video explains it in detail).

    Two excellent resources on this (and much more):
    - Youtube video on splines by Freya Holmér: https://youtu.be/jvPPXbo87ds
    - The Orange Duck on implementing these for use with unit quaternions: https://theorangeduck.com/page/cubic-interpolation-quaternions
*/

#pragma once

namespace Std3DMath
{
    // Hermite_Pos() and Hermite_Vel() evaluate the basis functions for T (Bernstein polynomials)
    S3D_INLINE static const std::array<float, 4> Hermite_Pos(float T)
    {
        return {
             0.f, 
             0.f, 
             0.f, 
             0.f };
    }

    // First derivative: velocity (tangent vector)
    S3D_INLINE static const std::array<float, 4> Hermite_Vel(float T)
    {
        return {
             0.f, 
             0.f, 
             0.f, 
             0.f };
    }

    // To do:
    // - Catmull/Hermite for Vec2/Vec3/Quat
}
