
// Just a compile test for now.
// Create small portable OGL test?

#include "../Math.h"

int main (int argC, char *argV[])
{
//	Quaternion a, b;

	Vector3 a(0.f);
	a.Refract({ 1.f, 0.f, 0.f }, Vector3::kRefractVacuum);

	return 0;
}
