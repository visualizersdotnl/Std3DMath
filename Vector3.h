
#pragma once

class Vector3
{
private:
	static const Vector3 Add(const Vector3 &A, const Vector3 &B) { return Vector3(A.x+B.x, A.y+B.y, A.z+B.z); }
	static const Vector3 Sub(const Vector3 &A, const Vector3 &B) { return Vector3(A.x-B.x, A.y-B.y, A.z-B.z); }
	static const Vector3 Mul(const Vector3 &A, const Vector3 &B) { return Vector3(A.x*B.x, A.y*B.y, A.z*B.z); }
	static const Vector3 Div(const Vector3 &A, const Vector3 &B) { return Vector3(A.x/B.x, A.y/B.y, A.z/B.z); }

	static const Vector3 Scale(const Vector3 &A, float B)
	{
		return Vector3(A.x*B, A.y*B, A.z*B);
	}

	static float Dot(const Vector3 &A, const Vector3 &B)
	{
		return A.x*B.x + A.y*B.y + A.z*B.z;
	}

	static const Vector3 Cross(const Vector3 &A, const Vector3 &B)
	{
		return Vector3(
			A.y*B.z - A.z*B.y,
			A.z*B.x - A.x*B.z,
			A.x*B.y - A.y*B.x);
	}

public:
	// Components are public since these are not performance primitives.
	float x, y, z;

	Vector3() {}
	~Vector3() {}
	
	explicit Vector3(float scalar) : 
		x(scalar), y(scalar), z(scalar) {}

	Vector3(float x, float y, float z) :
		x(x), y(y), z(z) {}

 	Vector3(const Vector2 &vec2D, float z = 1.f) :
		x(vec2D.x), y(vec2D.y), z(z) {}

	const Vector3 operator +(const Vector3 &B) const { return Add(*this, B); }
	const Vector3 operator +(float B)          const { return Add(*this, Vector3(B)); }
	const Vector3 operator -(const Vector3 &B) const { return Sub(*this, B); }
	const Vector3 operator -(float B)          const { return Sub(*this, Vector3(B)); }
	const float   operator *(const Vector3 &B) const { return Dot(*this, B); }
	const Vector3 operator *(float B)          const { return Mul(*this, Vector3(B)); }
	const Vector3 operator /(const Vector3 &B) const { return Div(*this, B); }
	const Vector3 operator /(float B)          const { return Div(*this, Vector3(B)); }
	const Vector3 operator %(const Vector3 &B) const { return Cross(*this, B); }

	Vector3& operator +=(const Vector3 &B) { return *this = *this + B; }
	Vector3& operator +=(float B)          { return *this = *this + B; }
	Vector3& operator -=(const Vector3 &B) { return *this = *this - B; }
	Vector3& operator -=(float B)          { return *this = *this - B; }
	Vector3& operator *=(float B)          { return *this = *this * B; }
	Vector3& operator /=(const Vector3 &B) { return *this = *this / B; }
	Vector3& operator /=(float B)          { return *this = *this / B; }

	bool operator ==(const Vector3 &B) const
	{
		return comparef(x, B.x) && comparef(y, B.y) && comparef(z, B.z);
	}

	bool operator !=(const Vector3 &B) const
	{
		return false == (*this == B);
	}

	bool operator <(const Vector3 &B) const
	{
		return Length() < B.Length();
	}

	float Length() const
	{
		return sqrtf(Dot(*this, *this));
	}
	
	const Vector3 Normalize() const
	{
		return *this * 1.f/Length();
	}

	float Angle(const Vector3 &B) const
	{
		return acosf(Dot(*this, B));
	}

	const Vector3 Project(const Vector3 &B) const
	{
		return *this * Dot(*this, B);
	}

	const Vector3 Reflect(const Vector3 &normal) const
	{
		const float R = 2.f*Dot(*this, normal);
		return *this - normal*R;
	}

	const Vector3 Perpendicular(const Vector3 &B) const
	{
		return Cross(*this, B);
	}
};
