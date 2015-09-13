
/*
	Row-major 4x4 matrix (left-handed).

	** Consider using Quaternion to store & multiply rotation! **

	To do:
	- Use float array instead of Vector4, or try a union with a 'float4' type?
	- Implement general and affine inverse.
	- Add more in-place operations (scale, translate, rotate).
*/

#pragma once

class Matrix44
{
public:
	static const Matrix44 Identity();
	static const Matrix44 Scaling(const Vector3 &scale);
	static const Matrix44 Translation(const Vector3 &translation);
	static const Matrix44 Rotation(const Quaternion &quaternion);
	static const Matrix44 RotationX(float angle);
	static const Matrix44 RotationY(float angle);
	static const Matrix44 RotationZ(float angle);
	static const Matrix44 RotationAxis(const Vector3 &axis, float angle);
	static const Matrix44 View(const Vector3 &from, const Vector3 &to, const Vector3 &up);
	static const Matrix44 Perspective(float yFOV, float aspectRatio, float zNear = 0.1f, float zFar = 10000.f);
	static const Matrix44 Orthographic(const Vector2 &topLeft, const Vector2 &bottomRight, float zNear, float zFar);
	static const Matrix44 FromArray(const float floats[16]);

public:
	Vector4 rows[4];

	~Matrix44() {}

//	void Scale(const Vector3 &scale);
//	void Translate(const Vector3 &translation);
//	void Rotate(...);
	
	const Matrix44 Transpose() const;
	const Matrix44 Multiply(const Matrix44 &B) const;

	const Vector3 Transform3(const Vector3 &B) const;
	const Vector4 Transform4(const Vector4 &B) const;

	// Invert orthogonal matrix (euclidian transform; may rotate, translate, reflect).
	const Matrix44 OrthoInverse() const;

	// Invert affine matrix (may also scale, shear).
	const Matrix44 AffineInverse() const;

	// General inverse (prefixed to encourage use of specific inverse).
	const Matrix44 GeneralInverse() const;

	void SetTranslation(const Vector3 &translation);
	
	// V' = M*V
	const Vector3 operator *(const Vector3 &B) const { return Transform3(B); }
	const Vector4 operator *(const Vector4 &B) const { return Transform4(B); }

	// M'= M*M (non-commutative!)
	const Matrix44 operator *(const Matrix44 &B) const { return Multiply(B); }
	Matrix44& operator *=(const Matrix44 &B) { return *this = *this * B; }

private:
	// You can't have an uninitialized matrix.
	Matrix44() {}
};
