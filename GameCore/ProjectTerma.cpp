#include "ProjectTerma.h"

#include <cstdio>

#include "../Engine/SceneManagment/SceneManager.h"
#include "Scenes/GameplayScene.h"

void ProjectTerma::Init()
{
	printf("Game started!\n");
	printf("Loading resources!\n");
	Textures::LOAD_ALL_TEXTURES();
	printf("Loading is OK!\n");
}

void ProjectTerma::Update()
{
	SceneManager::CreateScene(new GameplayScene());
	SceneManager::CloseScene(this);
}

void ProjectTerma::Destroy()
{
	printf("Start scene is terminated!\n");
}
