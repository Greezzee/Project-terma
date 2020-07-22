#include <stdio.h>
#include "MainMenuScene.h"
#include "GameplayScene.h"
#include "../../Engine/Time/TimeManager.h"
#include "../../Engine/Graphics/GraphicManager.h"
#include "../../Engine/SceneManagment/SceneManager.h"
#include "../../Engine/SceneManagment/Scene.h"


MainMenuScene::MainMenuScene() :
	counter(0), started(true) {}

void MainMenuScene::Init()
{
	//printf("MainMenu Created\n");
	counter = 0;
	started = true;
}

void MainMenuScene::Update()
{
	counter += TimeManager::GetDeltaTime();
	if (counter >= 3 * 600000 && started) {
		SceneManager::CreateScene(new GameplayScene);
		started = false;
		SceneManager::CloseScene(this);
	}
}

void MainMenuScene::Destroy()
{
	//printf("MainMenu Destroyed\n");
}
