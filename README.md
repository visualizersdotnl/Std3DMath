# Std3DMath

WARNING/FIXME: has a few SIMD/inlining related dependencies on _WIN32!

Standard math for 3D rendering (C++).

- Aligned with Intel SIMD primitives for practical convenience (Vector3, Vector4).
- Not very complete nor intended to be; I add & refactor on demand.
- Resides in global namespace (change if necessary).
- All angles are in radians (unless explicitly stated otherwise).
- Library uses standard assert() where necessary.

