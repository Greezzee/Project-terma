#pragma once
#include <string>

#include "../Utility/Coordinate.h"
class GameField;

/*!
* ����������� �����, �� �������� ������ ������������� ��� ������� ������� (��������, ����, ������� ���������, �������, ����� � ��)
* ��� �������� ������� ���������� ������� �������� ������� Init, ���� ��� ����������
* ������� Update � Draw ���������� ������������� ������ ����
* Destroy ���������� ������������� ��� �������� �������
* 
* ���������
*/
class GameObject
{
public:
	/*!
	* ������������� �������, ���������� ������� � �������� �������.
	* ��������� ��������� �� ������������ ������ owner, �� �� �������� ����� �������������!!!
	* ������� ��� �� ������� ���������� �������� ������, ���� ������� ������-�������� ����� ���������,
	* � ��� �������� ������� ������ �� ���� �� ������. ������ owner �������� ������ � ���� Init.
	* ������ ������� owner � ���������� �������� ��������, ���� ������ ������� � ����� ��������� ������������.
	*/
	virtual void Init(GameObject* owner) = 0;

	//! ���������� �������. ���������� ������ ���� (�� ������ ������. � ������� �������� ����� � ������ ������� ���������� � ��� �� �����)
	virtual void Update() = 0;

	//! ��������� �������. ��������������� �������! ���������� ������ ������ ���� (���� �� �����)
	virtual void Draw() = 0;

	//! ����������� �������. ���������� 1 ���, ����� ������� ���� ���������� ������
	virtual void Destroy() = 0;

	//! �������� ��������� ������ ������� ����� ����
	virtual GameObject* clone() const = 0;

	Vector2F GetPos();
	void SetPos(Vector2F pos);
	Vector2F GetDirection();
	void SetDirection(Vector2F dir);
	float GetRotation();
	void SetRotation(float angle);

	//! ������������ ������� �� ������� ��� ������� ������ �������
	void SetID(unsigned new_id);
	unsigned GetID();

	//! ������������ ������� �� ������� ��� ������� ������ �������
	void SetGamefield(GameField* field);
	GameField* GetGamefield();

	void SetTag(const std::string& new_tag);
	const std::string& GetTag();
	const std::string& getName() const;
	void setName(const std::string &name = "unnamed block");

protected:
	unsigned _ID; //! ������������ ����� ������� � ������� ���� ��������. �� ������� ��� � �� ������ ���
	std::string _tag; //! ������, � ������� ����� ���� �������� ��, ��� ������. ����� �� ������������ ������� �����

	Vector2F _pos; //! ������� �������� ������� � ������������
	Vector2F _basic_direction; //! WIP, ������ ������������� �������� �� ���������! (1, 0)
	float _angle = 0; //! ���� �������� ������� � �������� ������ ������� �������

	GameField* gamefield; //! ��������� �� ������� ����, � ������� ���� ������ ������� ������

	std::string name = "unnamed block";

	friend class Collider;
};

