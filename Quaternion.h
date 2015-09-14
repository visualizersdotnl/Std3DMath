
/*
	Basic (unit) quaternion implementation to describe & manipulate 3D rotation.

	- It's primary use, of course, is gimbal lock free interpolation with Slerp().
	- Multiplying quaternions (or rotations) isn't commutative, ergo A*B != B*A.
	- Vector4's operator overloads are *not* directly accessible (due to redefinitions).
	  For now, just use functions like Vector4::Dot() or cast.

	To do:
	- Deriving from Vector4 wasn't the brightest plan: undo this.
	- Create from Euler angles.
	- Create from matrix.
*/
 
#pragma once

class Quaternion : public Vector4
{
public:
	static const Quaternion Identity();
	static const Quaternion AxisAngle(const Vector3 &axis, float angle);
	static const Quaternion Slerp(const Quaternion &from, const Quaternion &to, float T);

public:
	Quaternion() 
	{
		*this = Identity();
	}

	~Quaternion() {}

	explicit Quaternion(const Vector4 &V) : Vector4(V) {}

	const Quaternion Normalized() const
	{
		Quaternion normalized = *this;
		normalized.Normalize();
		return normalized;
	}

	const Quaternion Conjugate() const
	{
		return Quaternion(Vector4(-x, -y, -z, w));
	}

	const Quaternion Inverse() const
	{
		return Normalized().Conjugate();
	}

	const Quaternion operator *(const Quaternion &B) const
	{
		return Quaternion(Vector4(
			 x*B.w + y*B.z - z*B.y + w*B.x,
			-x*B.z + y*B.w + z*B.x + w*B.y,
			 x*B.y - y*B.x + z*B.w + w*B.z,
			-x*B.x - y*B.y - z*B.z + w*B.w));
	}

	Quaternion& operator *=(const Quaternion &B)
	{
		return *this = *this * B;
	}
};
