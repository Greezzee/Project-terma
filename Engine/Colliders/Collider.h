#pragma once
#include "EllipseCollider.h"
#include "SquareCollider.h"


class Collider
{
public:
	/*!
	* �������� ��������� �� 2 ������������� ����������
	* ����� false, ���� ������ ������� �� ������������
	* ����� true, ����� ������������
	*
	* ������� �� 100% ������, ���������� �����������. ������� �������� ���������� COLLIDE_ITERATIONS
	*/
	static bool IsCollide(EllipseCollider* a, EllipseCollider* b);

	//! ���������, ������������ �� 2 ������ ����������
	static bool IsCollide(SquareCollider* a, SquareCollider* b);

	//! ��������� �� ������ ���������� a ������ � ����������� direction
	//! ����������, ������� ������ ������ ��������� a � ����������� ������� �������, ����� ����������� � b
	//! ����� ������� ���������� � ��� �� ��������, � ������� ������ ����������
	//! ����� NAN, ���� ��� �������� � ������ �����������, a ������� �� �������� b
	static float DistanceBetween(SquareCollider* a, SquareCollider* b, const Vector2F& direction);
	

private:
	
	//! ��������� ����������� ���� ����������� �� ��� norm
	static bool AxisIntersect(SquareCollider* a, SquareCollider* b, const Vector2F& norm);

	//! ����� �� �����������... � ������� �� ��������
	static Vector2F AxisDistance(SquareCollider* a, SquareCollider* b, const Vector2F& norm, const Vector2F& dir);
};