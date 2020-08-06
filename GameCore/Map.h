#pragma once

#include <vector>

#include "entities/Entity.h"

class Multiblock;

class SquareCollider;

class Player;

class Block;

class Level;

//! ������������ ������ ����� ������ � ������ ����
const int MAX_LEVEL_SIZE = 500;
const int BLOCK_SIZE = 40;
//! ������ ������ ��� �� ������������� �� ��� ����� �� ����� ���������� ������������
const int MAX_MULTIBLOCK_STRUCTURE_SEARCH_RADIUS = 20;

/*
 * ��� ����� ����������� �� GameField, ��� ����� ��� ���� � ������� �������� � ����
 */
class Map {
	// Shows if the game is paused or not
	bool is_paused;
public:
	// BASE
	//------------------------
	void Init();
	void Update();
	void Destroy();
	//------------------------
	// PAUSE GAME
	void pauseGame();
	void unpauseGame();
	bool isPaused();
	//
	// GETTERS|SETTERS
	//------------------------
	void setLevel(Level *level);
	Level* getLevel();
	//! ���������� ���� �� ����������� � �����!!!
	Block* getBlockFromMesh(Vector2I pos);
	//! This function may invoke given function with every entity on map that is unasledovana from T
	template<typename T> void collectEntities(void inv(T * ent));
	//------------------------

	// MAP EDITOR
	//------------------------
	void addMultiblock(Vector2I pos, Multiblock * block);
	void addBlock(Vector2I pos, Block * block);
	void addEntity(Vector2F pos, Entity * entity);
	void removeEntity(Entity * entity);
	//------------------------

	// TEST
	//------------------------
	void genTestStuff();
	//------------------------

	// COLLISIONS
	//------------------------
	float testCollision(SquareCollider * col, Vector2F dir);
	//------------------------

private:
	// UTILS
	//------------------------
	template<typename Base, typename T> inline bool instanceof(const T*);
	//------------------------

	// DRAW
	//------------------------
	void drawBlocks();
	void drawEntities();
	void drawBackground();
	void drawMultiblocks();
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
	SquareCollider *colliders_wireframe[MAX_LEVEL_SIZE][MAX_LEVEL_SIZE];
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
