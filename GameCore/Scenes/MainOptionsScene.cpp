#include "MainOptionsScene.h"

#include <cstdio>
#include <iostream>
#include <vector>

#include "../../Engine/Control/InputManager.h"
#include "../../Engine/SceneManagment/SceneManager.h"
#include "../../Engine/Utility/Coordinate.h"
#include "../Menu/Buttons/BackOptionsButton.h"
#include "../Menu/ImageWidgets/Background.h"
#include "../Textures.h"
#include "MainMenuScene.h"

MainOptionsScene::MainOptionsScene() {
}

void MainOptionsScene::Init() {
	//! Initializing the background
	Background *background = new Background();
	background->Init(nullptr);
	background->setScene(this);
	background->setSpriteID(Textures::TEST_BACKGROUND);
	widgets.push_back(background);

	//! Initializing the background
	BackOptionsButton *back_options_button = new BackOptionsButton();
	back_options_button->Init(nullptr);
	back_options_button->setScene(this);
	back_options_button->setSpriteID(Textures::MAIN_OPTIONS_MENU_BACK_BUTTON);
	back_options_button->SetPos({200, 750});
	back_options_button->SetSize({280, 280});
	back_options_button->SetGap({0, 0});
	widgets.push_back(back_options_button);

	printf("MainOptionsScene created!\n");
}

void MainOptionsScene::Update() {
	for (auto widget : widgets) {
		widget->Update();
	}
	for (auto widget : widgets) {
		widget->Draw();
	}

	if (InputManager::IsPressed(KeyboardKey::BACK)) {
		SceneManager::CreateScene(new MainMenuScene());
		SceneManager::CloseScene(this);
		return;
	}

	// It is in the end of this function for gentle change of scene
	if (!is_active) {
		SceneManager::CloseScene(this);
		return;
	}
}

void MainOptionsScene::Destroy() {
	for (auto widget : widgets) {
		widget->Destroy();
		delete widget;
	}
	widgets.clear();

	printf("MainOptionsScene destroyed!\n");
	std::cout.flush();
}
