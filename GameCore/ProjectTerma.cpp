#include "ProjectTerma.h"

#include <cstdio>

#include "../Engine/SceneManagment/SceneManager.h"

#include "Scenes/GameplayScene.h"
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
	//SceneManager::CreateScene(new GameplayScene());
	//SceneManager::CloseScene(this);
	DrawData new_data;
	new_data.layer = 0;
	new_data.frame = 0;
	new_data.origin = { 0, 0 };
	new_data.position = { 250, 300 };
	new_data.rotation = 0;
	new_data.scale = { 10, 10 };
	new_data.spriteID = Textures::DIRT_BLOCK_TEXTURE;

	GraphicManager::Draw(new_data, Views::TEST);

}

void ProjectTerma::Destroy()
{
	printf("Start scene is terminated!\n");
}
