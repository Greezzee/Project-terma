#include "GameplayScene.h"

#include <cstdio>

#include "../Map.h"
#include "../testing/TestLevel.h"

GameplayScene::GameplayScene() {}

void GameplayScene::Init()
{
	printf("GameplayScene Created\n");
	gamefield = new Map();

	// TODO в будущем нужно, чтобы значение этого поля приходило из gui (после выбора игроком)
	gamefield->setLevel(new TestLevel());
	//

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
