#pragma once
#include "../Utility/Coordinate.h"

const unsigned VIEWS_COUNT = 4;
enum Views {
	BASIC,
	TEST,
	PLAYER_CAM,
	MAIN_MENU
};

/*!
* ������� "����� ������" View �������� ���������� ������� �����.
* 
* real_size - ������ ���� � ��������, �� ������� ����� ���������� �������, � �������� ��������� ������ View
* real_position - ������� �������� ������ ���� ���� � ��������. 
* ���, ���� real_position = (100, 200), �� ��� ��������� ������� � �������� (0, 0) � ����������� ������� View, ��� �������� �������
* �������� � (100, 200) �������� ������������ �������� ������ ���� ����
* virtual_size ���� ������ ��������� ������� ��������� � ������� ������������.
* 
* virtual_size - ������ ����, � ������� ��������� ������� �� ���������� � ��� ������� View.
* ���, ���� real_position = (0, 0), real_size = (1600, 900), � virtual_size = (1, 1), �� ���� �� �������� ������
* � ������������ (0.5, 0.5), �� ��� ����������� ������ � ����� (800, 450) �� ���� (� ��������)
* 
* ��������, � ������� ���� �������, ����� �� ���������� � ������������ ������� �������� ����, ���� � ����� ������ �� � ��������,
* � � ����� ������� ��������. � ��� ��������� ��������� ������ View, ����� ���������� ��� ���������� � ������� �� �������� ������
* 
* unit_vector ����� ����������� ���� ���������. �� ��������� {1, 1} - ��� ��������� �� ��������� � ������� SFML.
* {1, -1} - ����������� ��������� ������� ���������
* ����� ���������� ��� x ��� ��� y, �������� 1 �� -1
* ��������, �������� �� ������ �� 1, �����������
* 
*/
struct View
{
	Vector2F real_position;
	Vector2F real_size;
	Vector2F virtual_position;
	Vector2F virtual_size;
	Vector2F unit_vector = { 1, 1 };
};

/*!
* ���������, ���������� ���������� � ���� ��������������� �������, ������� ����� ���������� �� ������.
* ����� ������������ ��� ����� ������� �������������
*/
struct DrawData
{
	DrawData();
	DrawData(unsigned id, unsigned lr, Vector2F& pos);
	DrawData(unsigned id, unsigned lr, float x, float y);
	DrawData(unsigned id, unsigned lr, Vector2F& pos, float rot);
	DrawData(unsigned id, unsigned lr, float x, float y, float rot);
	DrawData(unsigned id, unsigned lr, Vector2F& pos, unsigned fr);
	DrawData(unsigned id, unsigned lr, float x, float y, unsigned fr);
	DrawData(unsigned id, unsigned lr, Vector2F& pos, float rot, unsigned fr);
	DrawData(unsigned id, unsigned lr, float x, float y, float rot, unsigned fr);

	unsigned spriteID; //! ID �������, ����������� enum Sprites
	unsigned layer; //! ����� ����. ��� ������ ��������, ��� "����" ������ (��������� �� ��� ����� ������� ����)

	Vector2F position; //! ������� ������ ������� � ������������
	Vector2F origin; //! ��� ��������� ����� ������� ������������ ��� ������ �������� ����. ���������� �� 0 �� 1. {0, 0} - ������� ����� ����, (0.5, 0.5) - ����� �������
	Vector2F size; //! ������ ������� � �������� ����� �������� ����
	float rotation; //! ���� �������� ������� � ��������, ������ ������� �������
	int frame; //! ���� ����� �� ������������. ���� ��������
};
