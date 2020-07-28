#pragma once

const double EPS = 1E-9;

/*!
* �������� ���������: ��������� ������� ��������� �����.
* 
* ������������ � �������� ���������� ������ ��� float, �� � ������ ������� ������� � ���������.
* 
* ����� ������ ���������� � SFML ��������, ����� �������� ��������� ���������� �� sfml ���� ���, ��� �� �� ���������
*/

struct Vector2I
{
	int x, y;
};

struct Vector2F
{
	//! ����������� �� ���������, ������ (0, 0)
	Vector2F();

	//! ����������� ������� (a, b)
	Vector2F(float a, float b);

	//! ����������� �����������
	Vector2F(const Vector2F& that);
	float x, y;

	//! ����� ����� �������
	float Magnitude();

	//! ����� ������� ����� �������. �������, ��� ������� �����
	float SqrMagnitude();

	//! ����� ��������� ������, �������������� � ������
	Vector2F Normalized();

	//! �������� �������� �������� � ��������� �� ����� ��������� � ������������� ���������� ����������
	/*!
	* ������� �������� ��������� � ������� ������� �� ������
	* (a, b) * (c, d) = (a * c, b * d)
	* (a, b) / (c, d) = (a / c, b / d)
	*/
	const Vector2F& operator=(const Vector2F& that);
	const Vector2F& operator+=(const Vector2F& that);
	const Vector2F& operator-=(const Vector2F& that);

	const bool operator< (const Vector2F& that);

	friend const Vector2F& operator+(const Vector2F& that);
	friend const Vector2F operator-(const Vector2F& that);
	friend const Vector2F operator+(const Vector2F& a, const Vector2F& b);
	friend const Vector2F operator*(const Vector2F& a, const Vector2F& b);
	friend const Vector2F operator/(const Vector2F& a, const Vector2F& b);
	friend const Vector2F operator-(const Vector2F& a, const Vector2F& b);
	friend const Vector2F operator*(float a, const Vector2F& b);
	friend const Vector2F operator*(const Vector2F& a, float b);
	friend const Vector2F operator/(const Vector2F& a, float b);
	friend const bool operator==(const Vector2F& a, const Vector2F& b);
	friend const bool operator!=(const Vector2F& a, const Vector2F& b);
};

struct Vector2U
{
	unsigned x, y;
};

struct Vector2D
{
	double x, y;
};
