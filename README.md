# Std3DMath

Standard C++ math primitives for 3D rendering.
(c) visualizers.nl

Use these whenever specific (SIMD) optimization is not necessary and ease of use is favored.
So, about 90% of your calculations if not more.

Notes:
- Please supply your own ASSERT macro (see Dependencies.h).
- Resides in the global namespace; change if necessary.
- All angles are in radians unless expliticly stated otherwise.
