#pragma once

#include <vector>

#include "entities/Entity.h"

class Player;

class Block;

class Level;

//! Максимальная длинна сетки блоков и блоков стен
const int MAX_LEVEL_SIZE = 500;

/*
 * Сей класс наследуется от GameField, тут будет вся инфа о текущих объектах в игре
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
	//! Возвращает блок по координатам В СЕТКЕ!!!
	Block* getBlockFromMesh(Vector2I pos);
	void removeEntity(Entity * entity);
private:
	Block *blocks[MAX_LEVEL_SIZE][MAX_LEVEL_SIZE];
	std::vector<Entity*> entities;

	//! Это вещь отвечает за начальную генерацию карты, метод generated будет запущен единственный раз в начале.
	Level *level;
	Player * player;
};
