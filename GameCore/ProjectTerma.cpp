#include "ProjectTerma.h"

#include <cstdio>

#include "../Engine/SceneManagment/SceneManager.h"

#include "Scenes/GameplayScene.h"
#include "Scenes/MenuScene.h"
#include "../Engine/Graphics/GraphicManager.h"
#include "../Engine/Graphics/DrawData.h"
#include "../Engine/Colliders/SquareCollider.h"
#include "../Engine/Colliders/EllipseCollider.h"
#include "../Engine/Time/TimeManager.h"

void ProjectTerma::Init()
{
	printf("Game started!\n");
	printf("Loading resources!\n");
	Textures::LOAD_ALL_TEXTURES();
	printf("Loading is OK!\n");
}

void ProjectTerma::Update()
{
	SceneManager::CreateScene(new MenuScene());
	SceneManager::CloseScene(this);
}

void ProjectTerma::Destroy()
{
	printf("Start scene is terminated!\n");
}
