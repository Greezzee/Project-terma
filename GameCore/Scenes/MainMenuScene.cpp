#include "MainMenuScene.h"

#include "../Menu/Buttons/PlayButton.h"

#include <iostream>

MainMenuScene::MainMenuScene() {}

void MainMenuScene::Init()
{
	//! Initializing a button that leads to the gameplay scene
	PlayButton* play_button = new PlayButton(this);
	play_button->Init(nullptr);
	buttons.push_back(play_button);
}

void MainMenuScene::Update()
{
	for (auto button : buttons) {
		button->Update();
	}
	for (auto button : buttons) {
		button->Draw();
	}
}

void MainMenuScene::Destroy()
{
	for (auto button : buttons) {
		button->Destroy();
		delete button;
	}
	buttons.clear();

	printf("MainMenuScene destroyed!");
	std::cout.flush();
}
