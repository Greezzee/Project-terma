#include "../Engine/AllEngine.h"

#include "ProjectTerma.h"

#include <cstdio>

#include "Scenes/MainMenuScene.h"
#include "Views.h"
#include "Controls.h"

class MainMenuScene;

void ProjectTerma::Init()
{
	printf("Game started!\n");
	printf("Loading resources!\n");
	Textures::LOAD_ALL_TEXTURES();
	printf("Textures loaded!\n");
	printf("Loading views!\n");
	Views::LOAD_ALL_VIEWS();
	printf("Views loaded!\n");
	printf("Loading controls!\n");
	Controls::LOAD_ALL_GAMEKEYS();
	printf("Controls loaded!\n");

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
