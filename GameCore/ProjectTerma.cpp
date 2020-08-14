#include "../Engine/AllEngine.h"

#include "ProjectTerma.h"

#include <cstdio>

#include "Scenes/MainMenuScene.h"
#include "Views.h"
#include "Controls.h"

class MainMenuScene;

void ProjectTerma::Init()
{

	GraphicManager::SetResolution(Vector2U(resolution.x, resolution.y));

	printf("Game started!\n");
	GraphicManager::SetResolution(Vector2U(resolution.x, resolution.y));
	printf("Current resolution is %g x %g\n", resolution.x, resolution.y);
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
