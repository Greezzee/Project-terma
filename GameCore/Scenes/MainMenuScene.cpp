#include "MainMenuScene.h"

#include "../Menu/Buttons/PlayButton.h"

#include <iostream>

MainMenuScene::MainMenuScene() {}

void MainMenuScene::Init()
{
	//! Initializing a button that leads to the gameplay scene
	PlayButton* play_button = new PlayButton();
	play_button->Init(nullptr);
	widgets.push_back(play_button);
}

void MainMenuScene::Update()
{
	for (auto widget : widgets) {
		widget->Update();
	}
	for (auto button : widgets) {
		button->Draw();
	}
}

void MainMenuScene::Destroy()
{
	for (auto widget : widgets) {
		widget->Destroy();
		delete widget;
	}
	widgets.clear();

	printf("MainMenuScene destroyed!");
	std::cout.flush();
}
