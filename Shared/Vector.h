#ifndef _VECTOR_H
#define _VECTOR_H

class Vector
{
public:
	float x, y;

	Vector();
	Vector(const float x, const float y);
	Vector(const Vector &Copy);

	float Magnitude() const;
	float Angle() const;

	Vector Unit() const;

	Vector operator +(const Vector &Right) const;
	Vector operator -(const Vector &Right) const;

	Vector operator *(const float Right) const;
	Vector operator /(const float Right) const;

	float operator *(const Vector &Right) const; // Actually the dot product
};

#endif