#include "GameplayScene.h"

#include <cstdio>
#include <iostream>

#include "../../Engine/Control/InputManager.h"
#include "../../Engine/SceneManagment/SceneManager.h"
#include "../Controls.h"
#include "../Map/Map.h"
#include "../Testing/TestLevel.h"
#include "InventoryScene.h"
#include "MainMenuScene.h"

GameplayScene::GameplayScene() {
}

void GameplayScene::Init() {
	printf("GameplayScene Created\n");
	gamefield = new Map();

	// TODO в будущем нужно, чтобы значение этого поля приходило из gui (после выбора игроком)
	gamefield->setLevel(currentLevel = new TestLevel());//TODO fix mem
	//

	gamefield->Init();
}

void GameplayScene::Update() {
	if (!gamefield->isPaused()) {
		if (InputManager::IsPressed(Controls::BACK)) {
			SceneManager::CreateScene(new MainMenuScene());
			SceneManager::CloseScene(this);
			return;
		}

		if (InputManager::IsPressed(Controls::OPEN_INV)) {
			gamefield->pauseGame();
			SceneManager::CreateScene(new InventoryScene(gamefield));
		}
	}

	gamefield->Update();
}

void GameplayScene::Destroy() {
	gamefield->Destroy();
	delete gamefield;
	delete currentLevel;
	gamefield = NULL;
	currentLevel = NULL;
	printf("GameplayScene Destroyed\n");
	std::cout.flush();
}

