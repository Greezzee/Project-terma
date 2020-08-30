#include "GameplayScene.h"

#include "../../Engine/Control/InputManager.h"
#include "../../Engine/SceneManagment/SceneManager.h"
#include "../Controls.h"
#include "../Map/LoadableLevel.h"
#include "../Map/Map.h"
#include "../PTC.h"
#include "../Testing/TestLevel.h"
#include "InventoryScene.h"
#include "MainMenuScene.h"

GameplayScene::GameplayScene() {
}

void GameplayScene::Init() {
	gamefield = new Map();

	LoadableLevel* _level = new LoadableLevel("TestLevel");
	// TODO в будущем нужно, чтобы значение этого поля приходило из gui (после выбора игроком)
	gamefield->setLevel((Level*) _level);//TODO fix mem

	gamefield->Init();

	PTC::sayCreated("GameplayScene");
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
	PTC::sayDestroyed("GameplayScene");
}

