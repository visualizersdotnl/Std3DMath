
/*
	About this particular implementation:
	- It's single goal is to provide gimbal lock free interpolation of rotation.
	- Multiplying quaternions is not commutative, ergo, A*B does not equal B*A.
*/

#pragma once

class Quaternion
{
public:
	Vector4 V;

	static const Quaternion RotationAxisAngle(const Vector3 &axis, float angle);

	Quaternion() : V(0.f, 0.f, 0.f, 1.f) {} // Initialize as stationary unit.
	~Quaternion() {}

	explicit Quaternion(const Vector4 &V) : V(V) 
	{
	}

	float Length() const
	{
		return V.Length();
	}

	const Quaternion Normalized() const
	{
		return Quaternion(V.Normalized());
	}

	void Normalize()
	{
		*this = Normalized();
	}

	const Quaternion Conjugate() const
	{
		return Quaternion(Vector4(-V.x, -V.y, -V.z, V.w));
	}

	const Quaternion Inverse() const
	{
		return Normalized().Conjugate();
	}

	// Your silver bullet for gimbal-lock free interpolation between rotations.
	const Quaternion Slerp(const Quaternion &B, float lambda);

	const Quaternion operator *(const Quaternion &B) const
	{
		Quaternion quaternion;
		quaternion.V.x = B.V.w*V.x + B.V.x*V.w + B.V.y*V.z - B.V.z*V.y;
		quaternion.V.y = B.V.w*V.y - B.V.x*V.z + B.V.y*V.w + B.V.z*V.x;
		quaternion.V.z = B.V.w*V.z + B.V.x*V.y - B.V.y*V.x + B.V.z*V.w;
		quaternion.V.w = B.V.w*V.w - B.V.x*V.x - B.V.y*V.y - B.V.z*V.z;
		return quaternion;		
	}

	Quaternion& operator *=(const Quaternion &B)
	{
		*this = *this * B;
	}

	const Vector3 Quaternion::GetEulerAngles() const;
};
