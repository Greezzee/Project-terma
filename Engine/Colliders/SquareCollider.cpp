#include "SquareCollider.h"
#include "../Utility/Line.h"

//! Задаёт нулевой коллайдер, никому не принадлежащий
void SquareCollider::Init()
{
	_my_obj = nullptr;
	_size = { 0, 0 };
	_pos = { 0, 0 };
	_angle = 0;
	_shape_angle = 0;
	SetPoints();
}

//! Задаёт нулевой коллайдер, принадлежащий obj
void SquareCollider::Init(GameObject* obj)
{
	_my_obj = obj;
	_size = { 0, 0 };
	_pos = { 0, 0 };
	_angle = 0;
	_shape_angle = 0;
	SetPoints();
}

//! Задаёт прямоугольный коллайдер, принадлежащий obj
//! Размер сторон size, положение в пространстве pos
//! Прямоугольник со сторонами, паралелльными осям координат
//! ЦЕНТР - ВСЕГДА ТОЧКА ПЕРЕСЕЧЕНИЯ ДИАГОНАЛЕЙ
void SquareCollider::Init(GameObject* obj, const Vector2F& pos, const Vector2F& size)
{
	_my_obj = obj;
	_size = size;
	_pos = pos;
	_angle = 0;
	_shape_angle = PI / 2;
	SetPoints();
}

//! Задаёт прямоугольный коллайдер, принадлежащий obj
//! Размер сторон size, положение в пространстве pos
//! Прямоугольник. Нижняя сторона наклонена под углом angle (В РАДИАНАХ) к оси x, против часовой
//! ЦЕНТР (относительно центра происходит определение координаты и вращение) - ВСЕГДА ТОЧКА ПЕРЕСЕЧЕНИЯ ДИАГОНАЛЕЙ
void SquareCollider::Init(GameObject* obj, const Vector2F& pos, const Vector2F& size, float angle)
{
	_my_obj = obj;
	_size = size;
	_pos = pos;
	_angle = angle;
	_shape_angle = PI / 2;
	SetPoints();
}

//! Задаёт прямоугольный коллайдер, принадлежащий obj
//! Размер сторон size, положение в пространстве pos
//! Параллелепипед. Нижний левый угол (до прочих поворотов) - shape_angle (в радианах). shape_angle = PI/2 - задаёт прямоугольник
//! Нижняя сторона наклонена под углом angle (В РАДИАНАХ) к оси x, против часовой
//! ЦЕНТР (относительно центра происходит определение координаты и вращение) - ВСЕГДА ТОЧКА ПЕРЕСЕЧЕНИЯ ДИАГОНАЛЕЙ
void SquareCollider::Init(GameObject* obj, const Vector2F& pos, const Vector2F& size, float angle, float shape_angle)
{
	_my_obj = obj;
	_size = size;
	_pos = pos;
	_angle = angle;
	_shape_angle = shape_angle;
	SetPoints();
}

void SquareCollider::SetPoints()
{
	float sum_angle = _angle + _shape_angle;
	Vector2F x_vector = _size.x * Vector2F(cosf(_angle), sinf(_angle));
	Vector2F y_vector = _size.y * Vector2F(cosf(sum_angle), sinf(sum_angle));
	_points[0] = _pos + x_vector - y_vector;
	_points[1] = _pos + x_vector + y_vector;
	_points[2] = _pos - x_vector + y_vector;
	_points[3] = _pos - x_vector - y_vector;
}