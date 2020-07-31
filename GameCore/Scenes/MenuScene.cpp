#include "MenuScene.h"

#include "../../GameCore/Textures.h"
#include "../../GameCore/Buttons/PlayButton.h"

#include "../../Engine/SceneManagment/SceneManager.h"


#include <cstdio>

MenuScene::MenuScene()
{
	play_button = nullptr;
}

void MenuScene::Init()
{
	//! Create a play button
	PlayButton* _play_button = new PlayButton(this, Textures::MENU_BUTTON);
	_play_button->Init(nullptr);
	play_button = _play_button;

	printf("MenuScene created!\n");
}

void MenuScene::drawBackground() {
	DrawData info = { };
	info.position.x = 0;
	info.position.y = 0;

	info.size.x = 2000;
	info.size.y = 1000;

	info.origin = { 0, 1 };

	info.frame = 0;
	info.layer = 0;

	info.spriteID = Textures::TEST_BACKGROUND;
	GraphicManager::Draw(info, Views::PLAYER_CAM);
}

void MenuScene::Update()
{
	play_button->Update();

	drawBackground();
	play_button->Draw();
}

void MenuScene::Destroy()
{
	delete play_button;

	printf("MenuScene destroyed!\n");
}


