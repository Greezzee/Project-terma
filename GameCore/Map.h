#pragma once
#include "../Engine/Gameplay/GameField.h"

/*
 * ��� ����� ����������� �� GameField, ��� ����� ��� ���� � ������� �������� � ����
 */
class Map : public GameField {
	void Init();
	void Update();
	void Destroy();
};
