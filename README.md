# Std3DMath - Standard math for but not limited to 3D rendering (C++).

A long time ago I used to, every now and then, write a new "math library" (read: stuff you'd use for computer graphics usually).
It is of age by now but I just patch and upgrade (or procrastinate through the issue list) as I see fit.

For specific, often optimized tasks (think batch vertex processing, clipping et cetera) generic solutions tend to be impractical.

Please take heed:
- Aligned with Intel SIMD primitives for practical convenience (Vector3, Vector4).
- Not very complete nor intended to be; I add & refactor on demand.
- Resides in global namespace (change if necessary).
  + Except for separate functions and such which are (to be) in the Std3DMath namespace.
  + For brevity basic primitives remain in global namespace (for ex. Vector3).
- All angles are in radians (unless explicitly stated otherwise).
- Direction vectors are *assumed* unit as they should be, though I may throw in a superfluous normalization here and there.
- Library uses standard assert() where necessary.
- Warning: may have some _WIN32 specific SIMD dependencies.
- When I use this in a project I usually just dump it in my '/third-party' folder instead of using a submodule.

Jan/Feb 2026: I've started to flesh it out with a few more basics I've seen/needed throughout the years.
