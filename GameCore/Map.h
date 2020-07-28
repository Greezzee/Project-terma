#pragma once

#include <vector>

#include "../Engine/Gameplay/GameField.h"
#include "entities/Entity.h"

class Block;

class Level;

//! ������������ ������ ����� ������ � ������ ����
const int MAX_LEVEL_SIZE = 500;

/*
 * ��� ����� ����������� �� GameField, ��� ����� ��� ���� � ������� �������� � ����
 */
class Map: public GameField {
public:
	void Init();
	void Update();
	void Destroy();
	void setLevel(Level *level);
	Level* getLevel();
private:
	Block *blocks[MAX_LEVEL_SIZE][MAX_LEVEL_SIZE];
	std::vector<Entity*> entities;

	//! ��� ���� �������� �� ��������� ��������� �����, ����� generated ����� ������� ������������ ��� � ������.
	Level *level;
};
