#pragma once

#include <stddef.h>

#include "../../Engine/AllEngine.h"

class Level;

class GameField;
class Map;

class GameplayScene: public Scene {
	Map *gamefield = NULL;
	Level* currentLevel = NULL;
public:
	GameplayScene();

	void Init();
	void Update();
	void Destroy();
};
