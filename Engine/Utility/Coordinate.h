#pragma once

const double EPS = 1E-9;

/*!
* Полезные структуры: двумерные векторы различных типов.
* 
* Конструкторы и операции определены только для float, но в скором времени добавлю и остальные.
* 
* Введён вместо встроенные в SFML векторов, чтобы избежать появление зависимого от sfml кода там, где он не необходим
*/

struct Vector2I
{
	int x, y;
};

struct Vector2F
{
	//! Конструктор по умолчанию, вектор (0, 0)
	Vector2F();

	//! Конструктор вектора (a, b)
	Vector2F(float a, float b);

	//! Конструктор копирования
	Vector2F(const Vector2F& that);
	float x, y;

	//! Вернёт длину вектора
	float Magnitude();

	//! Вернёт квадрат длины вектора. БЫСТРЕЕ, ЧЕМ ОБЫЧНАЯ ДЛИНА
	float SqrMagnitude();

	//! Вернёт единичный вектор, сонаправленный с данным
	Vector2F Normalized();

	//! Операции сложения векторов и умножения на число совпадают с классическими векторными операциями
	/*!
	* Введены операции умножения и деления вектора на вектор
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
