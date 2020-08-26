#pragma once

#include <map>
#include <type_traits>
#include <vector>

#include "../../Engine/Graphics/ShaderManagment/SmoothLightShader.h"
#include "../Blocks/LightSource.h"
#include "../Entities/Entity.h"

class Block;
class Inventory;
class Level;
class Multiblock;
class Player;

#define FAST_CAST(OBJECT, CAST_TARGET, ACTION) {CAST_TARGET * casted = NULL; if ((casted = dynamic_cast<CAST_TARGET*>(OBJECT)) != NULL) { ACTION } }

//! ������������ ������ ����� ������ � ������ ����
const int MAX_LEVEL_SIZE = 500;
const int BLOCK_SIZE = 20;
//! ������ ������ ��� �� ������������� �� ��� ����� �� ����� ���������� ������������
const int MULTIBLOCK_STRUCTURE_SEARCH_RADIUS = 20;
const int BLOCKS_UPDATE_SEARCH_RADIUS = 5;

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

	// PAUSE GAME
	//------------------------
	void pauseGame();
	void unpauseGame();
	bool isPaused();
	//------------------------

	// GETTERS|SETTERS
	//------------------------
	void setPlayersView(unsigned view);
	void setLevel(Level *level);
	Level* getLevel();
	//! ���������� ���� �� ����������� � �����!!!
	Block* getBlockFromMesh(Vector2I pos);
	Block* getBlock(Vector2F pos);
	Block* getWallblock(Vector2F pos);
	//! This function may invoke given function with every entity on map that is unasledovana from T
	template<typename T> void collectEntities(void inv(T *ent));
	bool isIgnoreLight() const;
	void setIgnoreLight(bool ignoreLight);
	bool isMayDrawGrid() const;
	void setMayDrawGrid(bool mayDrawGrid);
	bool isMayDrawBackground() const;
	void setMayDrawBackground(bool mayDrawBackground);
	bool isMayDrawColliders() const;
	void setMayDrawColliders(bool mayDrawColliders);

	//------------------------

	// MAP EDITOR
	//------------------------
	bool placeMultiblock(Vector2I pos, Multiblock *block); //! ������ ������������� ��������� � ���� ������ � �������������, ��� ������������ ��� ����� ������. ����� �� ������ � ���������� 0.
	bool placeWallblock(Vector2I pos, Block *block); //! ������ ���� � ���� ������ � �������������, ��� ������ ��� ����� ����� ������. ����� �� ������ � ���������� 0.
	bool placeBlock(Vector2I pos, Block *block); //! ������ ���� ����� � ���� ������ ���� � �������������, ��� ������ ��� ����� ����� ����� ������. ����� �� ������ � ���������� 0.

	bool replaceWithBlock(Vector2I pos, Block *block); //! ������ ���� �� ������ ��������� � ���� ������, ���� ��� ���� ������ ����, ������� ���.
	bool replaceWithMultiblock(Vector2I pos, Multiblock *block); //! ������ ���� ��������� �� ������ ��������� � ���������� ��� ��� ����� ���������, ���� ��� ���� ������ �����, ������� ��.
	bool replaceWithWallBlock(Vector2I pos, Block * block); //! ������ ���� �� ������ ��������� � ���� ������ �����, ���� ��� ���� ������ ����, ������� ���.

	bool removeBlock(Vector2I pos); //! ��������� ������� ���� �� ���� ������, ���� ��� ��� ���� ��������� - ������� ���������.
	bool removeWallBlock(Vector2I pos); //! ��������� ������� ���� �� ���� ������.

	void addEntity(Vector2F pos, Entity *entity); //! ��������� �������� �� �������������� ����������
	void removeEntity(Entity *entity); //! ������� �������������� �������� � �����.
	Vector2I getGridCoords(Vector2F pos); //! ������������ ���������� � ������� ����������� � ���������� � �����.
	//------------------------

	// TEST
	//------------------------
	void genTestStuff();
	//------------------------

	// COLLISIONS
	//------------------------
	float testCollision(SquareCollider *col, Vector2F dir);
	//------------------------

	friend class InventoryScene;
	friend class ItemButton;
private:
	// UTILITIES
	//------------------------
	bool ensureInGrid(Vector2I pos);//! ������ 0, ���� ���������� �� �������� ���� ����� ������.
	bool flushMutliblockStructure(Vector2I pos); //! ������� ���������� � ��� ��� ���������� ����� �� �������� ����������� �����������.
	Vector2I findStructureblockParent(Vector2I pos); //! ������� ������������ ���������� ��� ������� ������������ �����.
	//------------------------

	// DRAW
	//------------------------
	void drawBlocks();
	void drawEntities();
	void drawBackground();
	void drawMultiblocks();
	void drawWallblocks();
	void drawGrid();
	//------------------------

	// UPDATE
	//------------------------
	void updateBlocks();
	void updateEntities();
	void updateWallblocks();
	//------------------------

	// MAP STUFF
	//------------------------
	Block *blocks[MAX_LEVEL_SIZE][MAX_LEVEL_SIZE];
	Block *wallblocks[MAX_LEVEL_SIZE][MAX_LEVEL_SIZE];
	std::vector<Entity*> entities;
	SquareCollider *colliders_wireframe[MAX_LEVEL_SIZE][MAX_LEVEL_SIZE];
	std::map<LightSource*, int> allLightSources;
	//------------------------

	// SHADER
	//------------------------
	SmoothLightShader currentShader = { };
	//------------------------

	// PAUSE
	//------------------------
	// Shows if the game is paused or not
	bool is_paused;
	//------------------------

	// DEBUG
	//------------------------
	bool ignoreLight = 0;
	bool mayDrawGrid = 0;
	bool mayDrawBackground = 1;
	bool mayDrawColliders = 0;
	//------------------------

	// INIT blocks and entities (Level)
	//------------------------
	Level *level;//! ��� ���� �������� �� ��������� ��������� �����, ����� generated ����� ������� ������������ ��� � ������.
	//------------------------

	// PLAYER
	//------------------------
	Player *player;
	//------------------------
};
