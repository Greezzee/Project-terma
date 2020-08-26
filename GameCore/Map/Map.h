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

//! Максимальная длинна сетки блоков и блоков стен
const int MAX_LEVEL_SIZE = 500;
const int BLOCK_SIZE = 20;
//! размер экрана как бы увеличивается на это число во время прорисовки мультиблоков
const int MULTIBLOCK_STRUCTURE_SEARCH_RADIUS = 20;
const int BLOCKS_UPDATE_SEARCH_RADIUS = 5;

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
	bool placeMultiblock(Vector2I pos, Multiblock *block); //! Ставит мультиблочную структуру в слой блоков в предположении, что пространство для блока ПУСТОЕ. Иначе не ставит и возвращает 0.
	bool placeWallblock(Vector2I pos, Block *block); //! Ставит блок в слой блоков в предположении, что ячейка для этого блока ПУСТАЯ. Иначе не ставит и возвращает 0.
	bool placeBlock(Vector2I pos, Block *block); //! Ставит блок стены в слой блоков стен в предположении, что ячейка для этого блока стены ПУСТАЯ. Иначе не ставит и возвращает 0.

	bool replaceWithBlock(Vector2I pos, Block *block); //! Ставит блок на данные коодинаты в слой блоков, если там есть другой блок, удаляет его.
	bool replaceWithMultiblock(Vector2I pos, Multiblock *block); //! Ставит блок структуры на данные коодинаты и генерирует все его блоки структуры, если там есть другие блоки, удаляет их.
	bool replaceWithWallBlock(Vector2I pos, Block * block); //! Ставит блок на данные коодинаты в слой блоков стены, если там есть другой блок, удаляет его.

	bool removeBlock(Vector2I pos); //! Правильно удаляет блок из слоя блоков, если это был блок структуры - удаляет структуру.
	bool removeWallBlock(Vector2I pos); //! Правильно удаляет блок из слоя блоков.

	void addEntity(Vector2F pos, Entity *entity); //! Добавляет сущность на соответсвующие координаты
	void removeEntity(Entity *entity); //! Удаляет соответсвующую сущность с карты.
	Vector2I getGridCoords(Vector2F pos); //! Конвертирует координаты в мировых координатах в координаты в сетке.
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
	bool ensureInGrid(Vector2I pos);//! Вернет 0, если координаты не похдодят этой сетке блоков.
	bool flushMutliblockStructure(Vector2I pos); //! Удаляет мультиблок и все его структурые блоки по заданным координатам МУЛЬТИБЛОКА.
	Vector2I findStructureblockParent(Vector2I pos); //! Находит родительский мультиблок для данного структурного блока.
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
	Level *level;//! Это вещь отвечает за начальную генерацию карты, метод generated будет запущен единственный раз в начале.
	//------------------------

	// PLAYER
	//------------------------
	Player *player;
	//------------------------
};
