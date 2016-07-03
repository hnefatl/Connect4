#include "Vector.h"

#define _USE_MATH_DEFINES
#include <math.h>

Vector::Vector()
	:x(0), y(0)
{
}
Vector::Vector(const float x, const float y)
	: x(x), y(y)
{
}
Vector::Vector(const Vector &Copy)
	: x(Copy.x), y(Copy.y)
{
}

float Vector::Magnitude() const
{
	return sqrtf(x * x + y * y);
}
float Vector::Angle() const
{
	return atan2f(y, x);
}

Vector Vector::Unit() const
{
	return *this / Magnitude();
}

Vector Vector::operator +(const Vector &Right) const
{
	return Vector(x + Right.x, y + Right.y);
}
Vector Vector::operator -(const Vector &Right) const
{
	return Vector(x - Right.x, y - Right.y);
}

Vector Vector::operator*(const float Right) const
{
	return Vector(x * Right, y * Right);
}
Vector Vector::operator/(const float Right) const
{
	return Vector(x / Right, y / Right);
}

float Vector::operator*(const Vector & Right) const // Dot product
{
	return x * Right.x + y * Right.y;
}