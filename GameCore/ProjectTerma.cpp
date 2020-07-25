#include <iostream>
#include "ProjectTerma.h"
#include "../Engine/GameManagment/GameManager.h"
#include "Scenes/MainMenuScene.h"
#include "../Engine/SceneManagment/SceneManager.h"

void ProjectTerma::Init()
{
	printf("Game started!\n");
}

void ProjectTerma::Update()
{
	SceneManager::CloseScene(this);
}

void ProjectTerma::Destroy()
{
	printf("Game ended!\n");
}
