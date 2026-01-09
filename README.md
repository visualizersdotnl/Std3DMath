# Std3DMath

A long time ago I used to, every now and then, write a new "math library" (read: stuff you'd use for computer graphics usually).
This one is the last time I decided to do it, for private use initially; ever since I upgrade it or usse the issue list (I love that!) to procrastinate things I should add or fix.
When I use this in a project I usually just dump it in my '/third-party' folder instead of using a submodule (or nested fork).

Anyway I digress...

WARNING/FIXME: has a few SIMD/inlining related dependencies on _WIN32!

Standard math for 3D rendering (C++).

- Aligned with Intel SIMD primitives for practical convenience (Vector3, Vector4).
- Not very complete nor intended to be; I add & refactor on demand.
- Resides in global namespace (change if necessary).
- All angles are in radians (unless explicitly stated otherwise).
- Library uses standard assert() where necessary.

