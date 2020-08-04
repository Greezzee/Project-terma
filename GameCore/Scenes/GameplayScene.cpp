#include "GameplayScene.h"

#include <cstdio>
#include <iostream>

#include "../../Engine/Control/InputManager.h"
#include "../../Engine/SceneManagment/SceneManager.h"
#include "../Map.h"
#include "../testing/TestLevel.h"
#include "MainMenuScene.h"

GameplayScene::GameplayScene() {
}

void GameplayScene::Init() {
	printf("GameplayScene Created\n");
	gamefield = new Map();

	// TODO в будущем нужно, чтобы значение этого поля приходило из gui (после выбора игроком)
	gamefield->setLevel(new TestLevel());
	//

	gamefield->Init();
}

void GameplayScene::Update() {
	if (InputManager::IsPressed(KeyboardKey::BACK)) {
		SceneManager::CreateScene(new MainMenuScene());
		SceneManager::CloseScene(this);
		return;
	}

	gamefield->Update();
}

void GameplayScene::Destroy() {
	gamefield->Destroy();
	delete gamefield;
	printf("GameplayScene Destroyed\n");
	std::cout.flush();
}
