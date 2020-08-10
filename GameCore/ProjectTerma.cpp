#include "../Engine/AllEngine.h"
#include "ProjectTerma.h"

#include <cstdio>

#include "Scenes/MainMenuScene.h"

class MainMenuScene;

void ProjectTerma::Init()
{
	printf("Game started!\n");
	printf("Loading resources!\n");
	Textures::LOAD_ALL_TEXTURES();
	printf("Loading is OK!\n");
}

void ProjectTerma::Update()
{
	SceneManager::CreateScene(new MainMenuScene());
	SceneManager::CloseScene(this);
}

void ProjectTerma::Destroy()
{
	printf("Start scene is terminated!\n");
}
