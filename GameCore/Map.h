#pragma once

#include <vector>

#include "entities/Entity.h"

class Player;

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
	void addBlock(Vector2I pos, Block * block);
	void addEntity(Vector2F pos, Entity * entity);
	//! ���������� ���� �� ����������� � �����!!!
	Block* getBlockFromMesh(Vector2I pos);
	void removeEntity(Entity * entity);
private:
	Block *blocks[MAX_LEVEL_SIZE][MAX_LEVEL_SIZE];
	std::vector<Entity*> entities;

	//! ��� ���� �������� �� ��������� ��������� �����, ����� generated ����� ������� ������������ ��� � ������.
	Level *level;
	Player * player;
};
