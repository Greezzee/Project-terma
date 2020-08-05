#pragma once

#include "../../Engine/SceneManagment/Scene.h"

class GameField;
class Map;

class GameplayScene: public Scene {
	Map *gamefield;
public:
	GameplayScene();

	void Init();
	void Update();
	void Destroy();
};
