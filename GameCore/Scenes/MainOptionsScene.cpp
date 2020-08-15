#include "../../Engine/AllEngine.h"
#include "MainOptionsScene.h"

#include <cstdio>
#include <iostream>
#include <vector>

#include "../Menu/Buttons/BackOptionsButton.h"
#include "../Menu/Buttons/ResolutionButton.h"
#include "../Menu/ImageWidgets/Background.h"
#include "../Menu/ImageWidgets/ResolutionImage.h"

#include "../Textures.h"
#include "../Views.h"

#include "MainMenuScene.h"

MainOptionsScene::MainOptionsScene() {
}

void MainOptionsScene::Init() {
	widgets = new std::vector<MenuWidget*>;

	//! Initializing the background
	Background *background = new Background();
	background->Init(nullptr);
	background->setScene(this);
	background->setSpriteID(Textures::TEST_BACKGROUND);
	background->SetSize( { 2000, 1000 });
	background->SetPos( { 1000, 500 });
	background->SetView(Views::MAIN_MENU);
	widgets->push_back(background);

	//! Initializing the background
	BackOptionsButton *back_options_button = new BackOptionsButton();
	back_options_button->Init(nullptr);
	back_options_button->setScene(this);
	back_options_button->setSpriteID(Textures::MAIN_OPTIONS_MENU_BACK_BUTTON);
	back_options_button->SetPos( { 80, 820 });
	back_options_button->SetSize( { 120, 120 });
	back_options_button->SetGap( { 0, 0 });
	back_options_button->SetView(Views::MAIN_MENU);
	widgets->push_back(back_options_button);

	ResolutionImage *resolution_image = new ResolutionImage();
	resolution_image->Init(nullptr);
	resolution_image->setScene(this);
	resolution_image->setSpriteID(Textures::RESOLUTION_BUTTON);
	resolution_image->SetPos({480, 550});
	resolution_image->SetSize({760, 230});
	resolution_image->SetView(Views::MAIN_MENU);
	widgets->push_back(resolution_image);

	ResolutionButton *resolution_button = new ResolutionButton();
	resolution_button->Init(nullptr);
	resolution_button->setScene(this);
	resolution_button->SetPos({1120, 550});
	resolution_button->SetSize({760, 230});
	resolution_button->SetView(Views::MAIN_MENU);
	widgets->push_back(resolution_button);

	printf("MainOptionsScene created!\n");
}

void MainOptionsScene::Update() {
	updateWidgets();
	drawWidgets();

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
	destroyWidgets();

	printf("MainOptionsScene destroyed!\n");
	std::cout.flush();
}
