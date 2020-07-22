#pragma once
#include <stdio.h>
#include "GameplayScene.h"

#include "../../GameCore/Map.h"
#include "../../Engine/Time/TimeManager.h"
#include "../../Engine/Control/InputManager.h"
#include "../../Engine/Graphics/GraphicManager.h"
#include "../../Engine/SceneManagment/SceneManager.h"

GameplayScene::GameplayScene(){}

void GameplayScene::Init()
{
	printf("GameplayScene Created\n");
	gamefield = new Map();
	gamefield->Init();
}

void GameplayScene::Update()
{
	gamefield->Update();
}

void GameplayScene::Destroy()
{
	gamefield->Destroy();
	delete gamefield;
	printf("GameplayScene Destroyed\n");
}

void GameplayScene::setGamefield(GameField * new_field) {
	this->gamefield = new_field;
}
