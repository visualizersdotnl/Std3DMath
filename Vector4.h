
/*
	Vector4 implementation is rather limited, mostly because it often does not serve as much more than 
	a container for shader constants, axis-angle pairs or a quaternion.
*/

#pragma once

class Vector4
{
private:
	static const Vector4 Add(const Vector4 &A, const Vector4 &B) { return Vector4(A.x+B.x, A.y+B.y, A.z+B.z, A.w+B.w); }
	static const Vector4 Sub(const Vector4 &A, const Vector4 &B) { return Vector4(A.x-B.x, A.y-B.y, A.z-B.z, A.w-B.w); }
	static const Vector4 Mul(const Vector4 &A, const Vector4 &B) { return Vector4(A.x*B.x, A.y*B.y, A.z*B.z, A.w*B.w); }
	static const Vector4 Div(const Vector4 &A, const Vector4 &B) { return Vector4(A.x/B.x, A.y/B.y, A.z/B.z, A.w/B.w); }

	static const Vector4 Scale(const Vector4 &A, float B)
	{
		return Vector4(A.x*B, A.y*B, A.z*B, A.w*B);
	}

	static float Dot(const Vector4 &A, const Vector4 &B)
	{
		return A.x*B.x + A.y*B.y + A.z*B.z + A.w*B.w;
	}

public:
	// Components are public since these are not performance primitives.
	float x, y, z, w;

	Vector4() {}
	virtual ~Vector4() {}
	
	explicit Vector4(float scalar) : 
		x(scalar), y(scalar), z(scalar), w(scalar) {}

	explicit Vector4(float x, float y, float z) :
		x(x), y(y), z(z), w(1.f) {}

	Vector4(float x, float y, float z, float w) :
		x(x), y(y), z(z), w(w) {}

	Vector4(const Vector3 &vec3D, float w = 1.f) :
		x(vec3D.x), y(vec3D.y), z(vec3D.z), w(w) {}

	const Vector4 operator +(const Vector4 &B) const { return Add(*this, B); }
	const Vector4 operator +(float B)          const { return Add(*this, Vector4(B)); }
	const Vector4 operator -(const Vector4 &B) const { return Sub(*this, B); }
	const Vector4 operator -(float B)          const { return Sub(*this, Vector4(B)); }
	const Vector4 operator *(float B)          const { return Mul(*this, Vector4(B)); }
	const Vector4 operator /(const Vector4 &B) const { return Div(*this, B); }
	const Vector4 operator /(float B)          const { return Div(*this, Vector4(B)); }

	Vector4& operator +=(const Vector4 &B) { return *this = *this + B; }
	Vector4& operator +=(float B)          { return *this = *this + B; }
	Vector4& operator -=(const Vector4 &B) { return *this = *this - B; }
	Vector4& operator -=(float B)          { return *this = *this - B; }
	Vector4& operator *=(float B)          { return *this = *this * B; }
	Vector4& operator /=(const Vector4 &B) { return *this = *this / B; }
	Vector4& operator /=(float B)          { return *this = *this / B; }

	bool operator ==(const Vector4 &B) const
	{
		return comparef(x, B.x) && comparef(y, B.y) && comparef(z, B.z) && comparef(w, B.w);
	}

	bool operator !=(const Vector4 &B) const
	{
		return false == (*this == B);
	}

	bool operator <(const Vector4 &B) const
	{
		return Length() < B.Length();
	}

	float Length() const
	{
		return sqrtf(Dot(*this, *this));
	}
	
	const Vector4 Normalize() const
	{
		return *this * 1.f/Length();
	}

	// Chiefly meant for constant vector uploads and the likes.
	const float *GetData() const { return &x; }
};
