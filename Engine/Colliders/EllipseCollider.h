#pragma once
#include "../Gameplay/GameObject.h"
#include "../Utility/Coordinate.h"
/*!
* ��������� � ���� �������
* ������� ����� ���� ��� �������� Gameobject, ���� ������ ��� ��������� ������
* ����� ������ � ������������.
* 
* 
* 
* IsCollide() �� �������
* ��������� ���������
*/
class EllipseCollider
{
public:

	virtual ~EllipseCollider() {};

	/*!
	* ������������� �������� ������� (����� � ������������ (0, 0))
	*/
	void Init();

	/*!
	* ������������� �������
	* pos - ������� ������ �������
	* angle - ���� �������� ������� � �������� ������������ ������ (0 �������� ������������ ���, ������� ������ �������)
	* size - ����� ��������
	*/
	void Init(Vector2F pos, float angle, Vector2F size);
protected:
	Vector2F _pos, _size;//! ������� ������ ������� � ����� ��� ��������
	float _angle;        //! ���� �������� ������� ������������ ������ ������ ������� ������� � ��������

	const static unsigned COLLIDE_ITERATIONS; //! ���������� �������� ��������. ������ �������� - ������, �� ������. �� ������������ ����� ������ 4

	friend class Collider;
};

