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
};