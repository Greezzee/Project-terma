#include "../../Engine/AllEngine.h"
#include "MainOptionsScene.h"

#include <cstdio>
#include <iostream>
#include <vector>

#include "../Menu/Buttons/BackOptionsButton.h"
#include "../Menu/Buttons/ControlsButton.h"
#include "../Menu/Buttons/ResolutionButton.h"
#include "../Menu/ImageWidgets/Background.h"
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
	widgets->push_back(back_options_button);

	ControlsButton *controls_button = new ControlsButton();
	controls_button->Init(nullptr);
	controls_button->setScene(this);
	controls_button->setSpriteID(Textures::CONTROLS_BUTTON);
	controls_button->SetPos( { 800, 600 });
	controls_button->SetSize( { 760, 230 });
	controls_button->SetGap( { 45, 55 });
	widgets->push_back(controls_button);

	ResolutionButton *resolution_button = new ResolutionButton();
	resolution_button->Init(nullptr);
	resolution_button->setScene(this);
	resolution_button->setSpriteID(Textures::RESOLUTION_BUTTON);
	resolution_button->SetPos( { 800, 400 });
	resolution_button->SetSize( { 760, 230 });
	resolution_button->SetGap( { 45, 55 });
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
	for (auto widget : *widgets) {
		widget->Destroy();
		delete widget;
	}
	widgets->clear();
	delete widgets;

	printf("MainOptionsScene destroyed!\n");
	std::cout.flush();
}
