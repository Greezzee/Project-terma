#include <iostream>
#include "ProjectTerma.h"
#include "../Engine/GameManagment/GameManager.h"
#include "Scenes/MainMenuScene.h"
#include "../Engine/SceneManagment/SceneManager.h"
#include "../Engine/Graphics/GraphicManager.h"
#include "../Engine/Graphics/DrawData.h"

void ProjectTerma::Init()
{
	printf("Game started!\n");
	GraphicManager::SetSpritesMaxCount(1);
	if (GraphicManager::LoadSprite("basic square.png") == -1) {
		printf("failed to load");
		SceneManager::CloseScene(this);
	}
}

void ProjectTerma::Update()
{
	DrawData new_sprite;
	new_sprite.spriteID = 0;
	new_sprite.scale = { 10, 10 };
	new_sprite.layer = 0;
	new_sprite.origin = { 0, 0 };
	new_sprite.position = { 400, 400 };
	new_sprite.rotation = 0;
	if (!GraphicManager::Draw(new_sprite)) {
		printf("NO\n");
		SceneManager::CloseScene(this);
	}
}

void ProjectTerma::Destroy()
{
	printf("Game ended!\n");
}
