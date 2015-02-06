
/*
	A few notes on this particular implementation:
	- Multiplying quaternions is not commutative, ergo, A*B does not equal B*A.
	- The main reason these exist in this library is for gimbal-lock free interpolation, or "slerp", useful in about any 3D scene player.
	- I'm keeping this object rather minimal and strict so as to prevent any error through assumption.
*/

#pragma once

class Quaternion
{
public:
	Vector4 V;

	static const Quaternion RotationAxisAngle(const Vector3 &axis, float angle);

	Quaternion() : V(0.f, 0.f, 0.f, 1.f) {} // Initialize as stationary unit.
	~Quaternion();

	explicit Quaternion(const Vector4 &V) : V(V) 
	{ 
		ASSERT(true == comparef(1.f, V.Length())); 
	}

	float Length() const
	{
		return V.Length();
	}

	const Quaternion Normalized() const
	{
		return Quaternion(V.Normalized());
	}

	void Conjugate()
	{
		// Invert imaginary part.
		V *= -1.f;
	}

	const Quaternion Inverse() const
	{
		Quaternion quaternion = *this;
		quaternion.V.Normalized();
		quaternion.Conjugate();
		return quaternion;
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
