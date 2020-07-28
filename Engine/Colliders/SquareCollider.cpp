#include "SquareCollider.h"
#include "../Utility/Line.h"

//! ����� ������� ���������, ������ �� �������������
void SquareCollider::Init()
{
	_my_obj = nullptr;
	_size = { 0, 0 };
	_pos = { 0, 0 };
	_angle = 0;
	_shape_angle = 0;
	SetPoints();
}

//! ����� ������� ���������, ������������� obj
void SquareCollider::Init(GameObject* obj)
{
	_my_obj = obj;
	_size = { 0, 0 };
	_pos = { 0, 0 };
	_angle = 0;
	_shape_angle = 0;
	SetPoints();
}

//! ����� ������������� ���������, ������������� obj
//! ������ ������ size, ��������� � ������������ pos
//! ������������� �� ���������, ������������� ���� ���������
//! ����� - ������ ����� ����������� ����������
void SquareCollider::Init(GameObject* obj, const Vector2F& pos, const Vector2F& size)
{
	_my_obj = obj;
	_size = size;
	_pos = pos;
	_angle = 0;
	_shape_angle = PI / 2;
	SetPoints();
}

//! ����� ������������� ���������, ������������� obj
//! ������ ������ size, ��������� � ������������ pos
//! �������������. ������ ������� ��������� ��� ����� angle (� ��������) � ��� x, ������ �������
//! ����� (������������ ������ ���������� ����������� ���������� � ��������) - ������ ����� ����������� ����������
void SquareCollider::Init(GameObject* obj, const Vector2F& pos, const Vector2F& size, float angle)
{
	_my_obj = obj;
	_size = size;
	_pos = pos;
	_angle = angle;
	_shape_angle = PI / 2;
	SetPoints();
}

//! ����� ������������� ���������, ������������� obj
//! ������ ������ size, ��������� � ������������ pos
//! ��������������. ������ ����� ���� (�� ������ ���������) - shape_angle (� ��������). shape_angle = PI/2 - ����� �������������
//! ������ ������� ��������� ��� ����� angle (� ��������) � ��� x, ������ �������
//! ����� (������������ ������ ���������� ����������� ���������� � ��������) - ������ ����� ����������� ����������
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