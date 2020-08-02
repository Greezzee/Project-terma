#pragma once
#include "../Utility/Coordinate.h"
#include "../Gameplay/GameObject.h"

const float PI = 3.1415926f;

class SquareCollider {
public:
	//! ����� ������� ���������, ������ �� �������������
	void Init();

	//! ����� ������� ���������, ������������� obj
	void Init(GameObject *obj);

	//! ����� ������������� ���������, ������������� obj
	//! ������ ������ size, ��������� � ������������ pos
	//! ������������� �� ���������, ������������� ���� ���������
	//! ����� - ������ ����� ����������� ����������
	void Init(GameObject *obj, const Vector2F &pos, const Vector2F &size);

	//! ����� ������������� ���������, ������������� obj
	//! ������ ������ size, ��������� � ������������ pos
	//! �������������. ������ ������� ��������� ��� ����� angle (� ��������) � ��� x, ������ �������
	//! ����� (������������ ������ ���������� ����������� ���������� � ��������) - ������ ����� ����������� ����������
	void Init(GameObject *obj, const Vector2F &pos, const Vector2F &size,
			float angle);

	//! ����� ������������� ���������, ������������� obj
	//! ������ ������ size, ��������� � ������������ pos
	//! ��������������. ������ ����� ���� (�� ������ ���������) - shape_angle (� ��������). shape_angle = PI/2 - ����� �������������
	//! ������ ������� ��������� ��� ����� angle (� ��������) � ��� x, ������ �������
	//! ����� (������������ ������ ���������� ����������� ���������� � ��������) - ������ ����� ����������� ����������
	void Init(GameObject *obj, const Vector2F &pos, const Vector2F &size,
			float angle, float shape_angle);

	float getAngle() const;
	void setAngle(float angle);
	GameObject* getMyObj() const;
	void setMyObj(GameObject *myObj);
	Vector2F getPos() const;
	void setPos(Vector2F pos);
	Vector2F getSize() const;
	void setSize(Vector2F size);

protected:

	void SetPoints(); //! ������ � ��������� ������� ����� ����������

	GameObject *_my_obj; //! ������, � �������� �������� ���������

	Vector2F _size; //! �������� ���� ������
	Vector2F _pos; //! ������� ������ � ������������ (����� - ����� ����������� ����������)
	float _angle; //! ���� �������� ���������� � �������� ������ �������. ��� _angle = 0 ������ ����� ����������� ��� x
	float _shape_angle; //! ������ ����� ���� ���������� � ��������. �� ��������� pi/2 (�������������)

	Vector2F _points[4]; //! ���������� ������/������, ������/�������, �����/�������, �����/������ ����� � ������ �������

	friend class Collider;
};

