#pragma once

#include <vector>

#include "entities/Entity.h"

class SquareCollider;

class Player;

class Block;

class Level;

//! ������������ ������ ����� ������ � ������ ����
const int MAX_LEVEL_SIZE = 500;
const int BLOCK_SIZE = 40;

/*
 * ��� ����� ����������� �� GameField, ��� ����� ��� ���� � ������� �������� � ����
 */
class Map {
public:
	// BASE
	//------------------------
	void Init();
	void Update();
	void Destroy();
	//------------------------

	// GETTERS|SETTERS
	//------------------------
	void setLevel(Level *level);
	Level* getLevel();
	Block* getBlockFromMesh(Vector2I pos);//! ���������� ���� �� ����������� � �����!!!
	//------------------------

	// MAP EDITOR
	//------------------------
	void addBlock(Vector2I pos, Block * block);
	void addEntity(Vector2F pos, Entity * entity);
	void removeEntity(Entity * entity);
	//------------------------

	// TEST
	//------------------------
	void genTestGround();
	//------------------------

	// COLLISIONS
	//------------------------
	bool testCollision(SquareCollider * col);
	//------------------------

private:
	// DRAW
	//------------------------
	void drawBlocks();
	void drawEntities();
	void drawBackground();
	//------------------------

	// UPDATE
	//------------------------
	void updateBlocks();
	void updateEntities();
	//------------------------

	// MAP STUFF
	//------------------------
	Block *blocks[MAX_LEVEL_SIZE][MAX_LEVEL_SIZE];
	std::vector<Entity*> entities;
	//------------------------

	// INIT blocks and entities (Level)
	//------------------------
	Level *level;//! ��� ���� �������� �� ��������� ��������� �����, ����� generated ����� ������� ������������ ��� � ������.
	//------------------------

	// PLAYER
	//------------------------
	Player * player;
	//------------------------
};
