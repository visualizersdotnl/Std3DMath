
#include "Math.h"

/* static */ const Matrix44 Matrix44::Identity()
{
	Matrix44 matrix;
	matrix.rows[0] = Vector4(1.f, 0.f, 0.f, 0.f);
	matrix.rows[1] = Vector4(0.f, 1.f, 0.f, 0.f);
	matrix.rows[2] = Vector4(0.f, 0.f, 1.f, 0.f);
	matrix.rows[3] = Vector4(0.f, 0.f, 0.f, 1.f);
	return matrix;
}

/* static */ const Matrix44 Matrix44::Scaling(const Vector3 &scale)
{
	Matrix44 matrix;
	matrix.rows[0] = Vector4(scale.x,     0.f,     0.f, 0.f);
	matrix.rows[1] = Vector4(    0.f, scale.y,     0.f, 0.f);
	matrix.rows[2] = Vector4(    0.f,     0.f, scale.z, 0.f);
	matrix.rows[3] = Vector4(    0.f,     0.f,     0.f, 1.f);
	return matrix;
}

/* static */ const Matrix44 Matrix44::Translation(const Vector3 &translation)
{
	Matrix44 matrix = Identity();
	matrix.SetTranslation(translation);
	return matrix;
}

/* static */ const Matrix44 Matrix44::RotationX(float angle)
{
	Matrix44 matrix;
	matrix.rows[0] = Vector4(1.f, 0.f, 0.f, 0.f);
	matrix.rows[1] = Vector4(0.f, cosf(angle), sinf(angle), 0.f);
	matrix.rows[2] = Vector4(0.f, -sinf(angle), cosf(angle), 0.f);
	matrix.rows[3] = Vector4(0.f, 0.f, 0.f, 1.f);
	return matrix;
}

/* static */ const Matrix44 Matrix44::RotationY(float angle)
{
	Matrix44 matrix;
	matrix.rows[0] = Vector4(cosf(angle), 0.f, -sinf(angle), 0.f);
	matrix.rows[1] = Vector4(0.f, 1.f, 0.f, 0.f);
	matrix.rows[2] = Vector4(sinf(angle), 0.f, cosf(angle), 0.f);	
	matrix.rows[3] = Vector4(0.f, 0.f, 0.f, 1.f);
	return matrix;
}

/* static */ const Matrix44 Matrix44::RotationZ(float angle)
{
	Matrix44 matrix;
	matrix.rows[0] = Vector4(cosf(angle), sinf(angle), 0.f, 0.f);
	matrix.rows[1] = Vector4(-sinf(angle), cosf(angle), 0.f, 0.f);
	matrix.rows[2] = Vector4(0.f, 0.f, 1.f, 0.f);
	matrix.rows[3] = Vector4(0.f, 0.f, 0.f, 1.f);
	return matrix;
}

/* static */ const Matrix44 Matrix44::RotationYawPitchRoll(float yaw, float pitch, float roll)
{
	return RotationX(yaw)*RotationY(pitch)*RotationZ(roll);
}

/* static */ const Matrix44 Matrix44::RotationAxis(const Vector3 &axis, float angle)
{
	const Vector3 unitAxis = axis.Normalized();

	angle *= 0.5f;
	const Vector4 Quat(unitAxis*sinf(angle), cosf(angle));

	const float XX = Quat.x*Quat.x;
	const float YY = Quat.y*Quat.y;
	const float ZZ = Quat.z*Quat.z;
	const float XY = Quat.x*Quat.y;
	const float XZ = Quat.x*Quat.z;
	const float YZ = Quat.y*Quat.z;
	const float XW = Quat.x*Quat.w;
	const float YW = Quat.y*Quat.w;
	const float ZW = Quat.z*Quat.w;

	Matrix44 matrix;
	matrix.rows[0] = Vector4(1.f - 2.f*(YY+ZZ),       2.f*(XY+ZW),       2.f*(XZ-YW), 0.f);
	matrix.rows[1] = Vector4(      2.f*(XY-ZW), 1.f - 2.f*(XX+ZZ),       2.f*(YZ+XW), 0.f);
	matrix.rows[2] = Vector4(      2.f*(XZ+YW),       2.f*(YZ-XW), 1.f - 2.f*(XX+YY), 0.f);
	matrix.rows[3] = Vector4(              0.f,               0.f,               0.f, 1.f);
	return matrix;
}

/* static */ const Matrix44 Matrix44::Rotation(const Quaternion &quaternion)
{
	// Quaternions *should* be unit!
	const Quaternion unit = quaternion.Normalized();

	const float XX = unit.x*unit.x;
	const float YY = unit.y*unit.y;
	const float ZZ = unit.z*unit.z;
	const float XY = unit.x*unit.y;
	const float XZ = unit.x*unit.z;
	const float YZ = unit.y*unit.z;
	const float XW = unit.x*unit.w;
	const float YW = unit.y*unit.w;
	const float ZW = unit.z*unit.w;

	Matrix44 matrix;
	matrix.rows[0] = Vector4(1.f - 2.f*(YY+ZZ),       2.f*(XY+ZW),       2.f*(XZ-YW), 0.f);
	matrix.rows[1] = Vector4(      2.f*(XY-ZW), 1.f - 2.f*(XX+ZZ),       2.f*(YZ+XW), 0.f);
	matrix.rows[2] = Vector4(      2.f*(XZ+YW),       2.f*(YZ-XW), 1.f - 2.f*(XX+YY), 0.f);
	matrix.rows[3] = Vector4(              0.f,               0.f,               0.f, 1.f);
	return matrix;
}

/* static */ const Matrix44 Matrix44::View(const Vector3 &from, const Vector3 &to, const Vector3 &up)
{
	assert(true == comparef(1.f, up.Length()));
	const Vector3 zAxis = (to-from).Normalized();
	const Vector3 xAxis = (up % zAxis).Normalized();	
	const Vector3 yAxis = zAxis % xAxis;

	Matrix44 matrix;
	matrix.rows[0] = Vector4(xAxis, -(xAxis*from));
	matrix.rows[1] = Vector4(yAxis, -(yAxis*from));
	matrix.rows[2] = Vector4(zAxis, -(zAxis*from));
	matrix.rows[3] = Vector4(0.f, 0.f, 0.f, 1.f);
	return matrix;
}

/* static */ const Matrix44 Matrix44::Perspective(float yFOV, float aspectRatio, float zNear /* = 0.1f */, float zFar /* = 10000.f */)
{
	const float yScale = 1.f/tanf(yFOV*0.5f);
	const float xScale = yScale/aspectRatio;

	Matrix44 matrix;
	matrix.rows[0] = Vector4(xScale, 0.f, 0.f, 0.f);
	matrix.rows[1] = Vector4(0.f, yScale, 0.f, 0.f);
	matrix.rows[2] = Vector4(0.f, 0.f, zFar / (zFar-zNear), -zNear * zFar / (zFar-zNear));
	matrix.rows[3] = Vector4(0.f, 0.f, 1.f, 0.f);
	return matrix;
}

/* static */ const Matrix44 Matrix44::Orthographic(const Vector2 &topLeft, const Vector2 &bottomRight, float zNear, float zFar)
{
    Matrix44 matrix;
    matrix.rows[0] = Vector4(2.f / (bottomRight.x-topLeft.x), 0.f, 0.f, -(bottomRight.x+topLeft.x) / (bottomRight.x-topLeft.x));
    matrix.rows[1] = Vector4(0.f, 2.f / (topLeft.y-bottomRight.y), 0.f, -(topLeft.y+bottomRight.y) / (topLeft.y-bottomRight.y));
    matrix.rows[2] = Vector4(0.f, 0.f, 2.f / (zFar-zNear), -(zFar+zNear) / (zFar-zNear));
    matrix.rows[3] = Vector4(0.f, 0.f, 0.f, 1.f);
    return matrix;
}

/* static */ const Matrix44 Matrix44::FromArray(const float floats[16])
{
	Matrix44 matrix;
	memcpy(&matrix.rows[0], floats, 16*sizeof(float));
	return matrix;
}

const Matrix44 Matrix44::Transpose() const
{
	Matrix44 matrix;
	matrix.rows[0] = Vector4(rows[0].x, rows[1].x, rows[2].x, rows[3].x);
	matrix.rows[1] = Vector4(rows[0].y, rows[1].y, rows[2].y, rows[3].y);
	matrix.rows[2] = Vector4(rows[0].z, rows[1].z, rows[2].z, rows[3].z);
	matrix.rows[3] = Vector4(rows[0].w, rows[1].w, rows[2].w, rows[3].w);
	return matrix;
}

const Matrix44 Matrix44::Multiply(const Matrix44 &B) const
{
	Matrix44 matrix;
	matrix.rows[0].x = rows[0].x*B.rows[0].x + rows[0].y*B.rows[1].x + rows[0].z*B.rows[2].x + rows[0].w*B.rows[3].x;
	matrix.rows[0].y = rows[0].x*B.rows[0].y + rows[0].y*B.rows[1].y + rows[0].z*B.rows[2].y + rows[0].w*B.rows[3].y;
	matrix.rows[0].z = rows[0].x*B.rows[0].z + rows[0].y*B.rows[1].z + rows[0].z*B.rows[2].z + rows[0].w*B.rows[3].z;
	matrix.rows[0].w = rows[0].x*B.rows[0].w + rows[0].y*B.rows[1].w + rows[0].z*B.rows[2].w + rows[0].w*B.rows[3].w;
	matrix.rows[1].x = rows[1].x*B.rows[0].x + rows[1].y*B.rows[1].x + rows[1].z*B.rows[2].x + rows[1].w*B.rows[3].x;
	matrix.rows[1].y = rows[1].x*B.rows[0].y + rows[1].y*B.rows[1].y + rows[1].z*B.rows[2].y + rows[1].w*B.rows[3].y;
	matrix.rows[1].z = rows[1].x*B.rows[0].z + rows[1].y*B.rows[1].z + rows[1].z*B.rows[2].z + rows[1].w*B.rows[3].z;
	matrix.rows[1].w = rows[1].x*B.rows[0].w + rows[1].y*B.rows[1].w + rows[1].z*B.rows[2].w + rows[1].w*B.rows[3].w;
	matrix.rows[2].x = rows[2].x*B.rows[0].x + rows[2].y*B.rows[1].x + rows[2].z*B.rows[2].x + rows[2].w*B.rows[3].x;
	matrix.rows[2].y = rows[2].x*B.rows[0].y + rows[2].y*B.rows[1].y + rows[2].z*B.rows[2].y + rows[2].w*B.rows[3].y;
	matrix.rows[2].z = rows[2].x*B.rows[0].z + rows[2].y*B.rows[1].z + rows[2].z*B.rows[2].z + rows[2].w*B.rows[3].z;
	matrix.rows[2].w = rows[2].x*B.rows[0].w + rows[2].y*B.rows[1].w + rows[2].z*B.rows[2].w + rows[2].w*B.rows[3].w;
	matrix.rows[3].x = rows[3].x*B.rows[0].x + rows[3].y*B.rows[1].x + rows[3].z*B.rows[2].x + rows[3].w*B.rows[3].x;
	matrix.rows[3].y = rows[3].x*B.rows[0].y + rows[3].y*B.rows[1].y + rows[3].z*B.rows[2].y + rows[3].w*B.rows[3].y;
	matrix.rows[3].z = rows[3].x*B.rows[0].z + rows[3].y*B.rows[1].z + rows[3].z*B.rows[2].z + rows[3].w*B.rows[3].z;
	matrix.rows[3].w = rows[3].x*B.rows[0].w + rows[3].y*B.rows[1].w + rows[3].z*B.rows[2].w + rows[3].w*B.rows[3].w;
	return matrix;
}

const Vector3 Matrix44::Transform3(const Vector3 &B) const
{
	return Vector3(
		rows[0].x*B.x + rows[0].y*B.y + rows[0].z*B.z + rows[0].w,
		rows[1].x*B.x + rows[1].y*B.y + rows[1].z*B.z + rows[1].w,
		rows[2].x*B.x + rows[2].y*B.y + rows[2].z*B.z + rows[2].w);
}

const Vector4 Matrix44::Transform4(const Vector4 &B) const
{
	return Vector4(
		rows[0]*B,
		rows[1]*B,
		rows[2]*B,
		rows[3]*B);
}

const Matrix44 Matrix44::OrthoInverse() const
{
	Matrix44 matrix;
	matrix.rows[0] = Vector4(rows[0].x, rows[1].x, rows[2].x, -rows[0].w);
	matrix.rows[1] = Vector4(rows[0].y, rows[1].y, rows[2].y, -rows[1].w);
	matrix.rows[2] = Vector4(rows[0].z, rows[1].z, rows[2].z, -rows[2].w);
	matrix.rows[3] = Vector4(0.f, 0.f, 0.f, rows[3].w);
	return matrix;
}

void Matrix44::SetTranslation(const Vector3 &V)
{
	rows[0].w = V.x;
	rows[1].w = V.y;
	rows[2].w = V.z;
}
