# Std3DMath

A long time ago I used to, every now and then, write a new "math library" (read: stuff you'd use for computer graphics usually).
It is of age by now but I just patch and upgrade (or pracrastinate through the issue list) as I see fit.

When I use this in a project I usually just dump it in my '/third-party' folder instead of using a submodule.

Standard math for 3D rendering (C++).

- Aligned with Intel SIMD primitives for practical convenience (Vector3, Vector4).
- Not very complete nor intended to be; I add & refactor on demand.
- Resides in global namespace (change if necessary).
- All angles are in radians (unless explicitly stated otherwise).
- Library uses standard assert() where necessary.
- Warning: may have some _WIN32 specific SIMD dependencies.

