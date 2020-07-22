#pragma once
#include "Coordinate.h"
#include <cmath>
Vector2F::Vector2F()
{
	x = 0;
	y = 0;
}

Vector2F::Vector2F(float a, float b)
{
	x = a;
	y = b;
}

Vector2F::Vector2F(const Vector2F& that)
{
	x = that.x;
	y = that.y;
}

float Vector2F::SqrMagnitude()
{
	return x * x + y * y;
}

float Vector2F::Magnitude()
{
	return sqrtf(SqrMagnitude());
}

const Vector2F operator/(const Vector2F& a, float b)
{
	return Vector2F(a.x / b, a.y / b);
}

Vector2F Vector2F::Normalized()
{
	float len = Magnitude();
	if (len == 0)
		return *this;
	return *this / len;
}

const Vector2F& Vector2F::operator=(const Vector2F& that)
{
	x = that.x;
	y = that.y;
	return *this;
}

const Vector2F& operator+(const Vector2F& that)
{
	return that;
}
const Vector2F operator-(const Vector2F& that)
{
	return Vector2F(-that.x, -that.y);
}

const Vector2F& Vector2F::operator+=(const Vector2F& that)
{
	x += that.x;
	y += that.y;
	return *this;
}

const Vector2F& Vector2F::operator-=(const Vector2F& that)
{
	x -= that.x;
	y -= that.y;
	return *this;
}

const Vector2F operator+(const Vector2F& a, const Vector2F& b)
{
	return Vector2F(a.x + b.x, a.y + b.y);
}

const Vector2F operator*(const Vector2F& a, const Vector2F& b)
{
	return Vector2F(a.x * b.x, a.y * b.y);
}

const Vector2F operator/(const Vector2F& a, const Vector2F& b)
{
	return Vector2F(a.x / b.x, a.y / b.y);
}

const Vector2F operator-(const Vector2F& a, const Vector2F& b)
{
	return Vector2F(a.x - b.x, a.y - b.y);
}

const Vector2F operator*(float a, const Vector2F& b)
{
	return Vector2F(a * b.x, a * b.y);
}

const Vector2F operator*(const Vector2F& a, float b)
{
	return Vector2F(a.x * b, a.y * b);
}

const bool operator==(const Vector2F& a, const Vector2F& b)
{
	return a.x == b.x && a.y == b.y;
}

const bool operator!=(const Vector2F& a, const Vector2F& b)
{
	return !(a == b);
}