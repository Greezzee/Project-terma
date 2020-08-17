#pragma once

#include <map>
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

//! Максимальная длинна сетки блоков и блоков стен
const int MAX_LEVEL_SIZE = 500;
const int BLOCK_SIZE = 40;
//! размер экрана как бы увеличивается на это число во время прорисовки мультиблоков
const int MULTIBLOCK_STRUCTURE_SEARCH_RADIUS = 20;
const int LIGHT_SOURCE_SEARCH_RADIUS = 20;

/*
 * Сей класс наследуется от GameField, тут будет вся инфа о текущих объектах в игре
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
	//! Возвращает блок по координатам В СЕТКЕ!!!
	Block* getBlockFromMesh(Vector2I pos);
	Block* getBlock(Vector2F pos);
	Block* getWallblock(Vector2F pos);
	//! This function may invoke given function with every entity on map that is unasledovana from T
	template<typename T> void collectEntities(void inv(T * ent));
	bool isIgnoreLight() const;
	void setIgnoreLight(bool ignoreLight = 0);
	bool isMayDrawGrid() const;
	void setMayDrawGrid(bool mayDrawGrid = 0);
	//------------------------

	// MAP EDITOR
	//------------------------
	void addMultiblock(Vector2I pos, Multiblock * block);
	void addWallblock(Vector2I pos, Block* block);
	void addBlock(Vector2I pos, Block * block);
	void addEntity(Vector2F pos, Entity * entity);
	void removeEntity(Entity * entity);
	void addBlock(Vector2F pos, Block * block);
	Vector2I getGridCoords(Vector2F pos);
	//------------------------

	// TEST
	//------------------------
	void genTestStuff();
	//------------------------

	// COLLISIONS
	//------------------------
	float testCollision(SquareCollider * col, Vector2F dir);
	//------------------------

	// LIGHT
	//------------------------
	bool isMayDrawBackground() const;
	void setMayDrawBackground(bool mayDrawBackground = 0);
	//------------------------

	friend class InventoryScene;
	friend class ItemButton;
private:

	// DRAW
	//------------------------
	void drawBlocks();
	void drawEntities();
	void drawBackground();
	void drawMultiblocks();
	void drawWallblocks();
	void drawGrid();
	void drawLight();
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
	SmoothLightShader currentShader = {};
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
	//------------------------

	// INIT blocks and entities (Level)
	//------------------------
	Level *level;//! Это вещь отвечает за начальную генерацию карты, метод generated будет запущен единственный раз в начале.
	//------------------------

	// PLAYER
	//------------------------
	Player * player;
	//------------------------
};
