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
class Map {
public:
	void Init();
	void Update();
	void Destroy();
	void setLevel(Level *level);
	Level* getLevel();
	void addBlock(int x, int y, Block * block);
	void addEntity(int x, int y, Entity * entity);
	Block* getBlock(int x, int y);
	void removeEntity(Entity * entity);
private:
	Block *blocks[MAX_LEVEL_SIZE][MAX_LEVEL_SIZE];
	std::vector<Entity*> entities;

	//! ��� ���� �������� �� ��������� ��������� �����, ����� generated ����� ������� ������������ ��� � ������.
	Level *level;
};
