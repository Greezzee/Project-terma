#pragma once

#include <vector>

#include "../Engine/Gameplay/GameField.h"
#include "entities/Entity.h"

class Block;

class Level;

//! Максимальная длинна сетки блоков и блоков стен
const int MAX_LEVEL_SIZE = 500;

/*
 * Сей класс наследуется от GameField, тут будет вся инфа о текущих объектах в игре
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

	//! Это вещь отвечает за начальную генерацию карты, метод generated будет запущен единственный раз в начале.
	Level *level;
};
