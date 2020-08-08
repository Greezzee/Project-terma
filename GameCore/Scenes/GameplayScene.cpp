#include "GameplayScene.h"

#include <cstdio>
#include <iostream>

#include "../../Engine/Control/InputManager.h"
#include "../../Engine/SceneManagment/SceneManager.h"
#include "../Map.h"
#include "../testing/TestLevel.h"
#include "MainMenuScene.h"
#include "InventoryScene.h"

GameplayScene::GameplayScene() {
}

void GameplayScene::Init() {
	printf("GameplayScene Created\n");
	gamefield = new Map();

	// TODO � ������� �����, ����� �������� ����� ���� ��������� �� gui (����� ������ �������)
	gamefield->setLevel(currentLevel = new TestLevel());//TODO fix mem
	//

	gamefield->Init();
}

void GameplayScene::Update() {
	if (!gamefield->isPaused()) {
		if (InputManager::IsPressed(KeyboardKey::BACK)) {
			SceneManager::CreateScene(new MainMenuScene());
			SceneManager::CloseScene(this);
			return;
		}

		if (InputManager::IsPressed(KeyboardKey::OPEN_INV)) {
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
	printf("GameplayScene Destroyed\n");
	std::cout.flush();
}

