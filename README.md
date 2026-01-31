# Std3DMath - Standard math for but not limited to 3D rendering (C++).

A long time ago I used to, every now and then, write a new "math library" (read: stuff you'd use for computer graphics usually).
It is of age by now but I just patch and upgrade (or procrastinate through the issue list) as I see fit.

When I use this in a project I usually just dump it in my '/third-party' folder instead of using a submodule.

Please take heed of:
- Aligned with Intel SIMD primitives for practical convenience (Vector3, Vector4).
- Not very complete nor intended to be; I add & refactor on demand.
- Resides in global namespace (change if necessary).
  + Except for separate functions and such which are (to be) in the Std3DMath namespace.
  + For brevity basic primitives remain in global namespace (for ex. Vector3).
- All angles are in radians (unless explicitly stated otherwise).
- Library uses standard assert() where necessary.
- Warning: may have some _WIN32 specific SIMD dependencies.

