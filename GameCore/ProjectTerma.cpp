#include <iostream>
#include "ProjectTerma.h"
#include "../Engine/GameManagment/GameManager.h"
#include "Scenes/MainMenuScene.h"
#include "../Engine/SceneManagment/SceneManager.h"
#include "../Engine/Graphics/GraphicManager.h"
#include "../Engine/Graphics/DrawData.h"
#include "../Engine/Colliders/SquareCollider.h"
#include "../Engine/Colliders/EllipseCollider.h"
#include "../Engine/Time/TimeManager.h"

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
