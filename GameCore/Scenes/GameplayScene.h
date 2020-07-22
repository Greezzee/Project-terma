#pragma once
#include "../../Engine/Gameplay/GameField.h"
#include "../../Engine/SceneManagment/Scene.h"
class GameplayScene : public Scene
{
public:
	GameplayScene();
	void Init();
	void Update();
	void Destroy();
	void setGamefield(GameField * new_field);
private:
	GameField * gamefield;
};
