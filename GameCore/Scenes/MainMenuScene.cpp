#include "MainMenuScene.h"

#include "../Menu/Buttons/PlayButton.h"
#include "../Menu/Buttons/QuitButton.h"
#include "../Menu/ImageWidgets/Background.h"
#include "../Menu/Buttons/OptionsButton.h"

#include "../Textures.h"
#include "../../Engine/SceneManagment/SceneManager.h"
#include "../../Engine/Control/InputManager.h"

#include "../../Engine/Colliders/Collider.h"
#include "../../Engine/Colliders/SquareCollider.h"

#include <iostream>

MainMenuScene::MainMenuScene() {}

void MainMenuScene::Init()
{
	//! Initializing the background
	Background* background = new Background();
	background->Init(nullptr);
	background->setScene(this);
	background->setSpriteID(Textures::TEST_BACKGROUND);
	widgets.push_back(background);

	//! Initializing the button that leads to the gameplay scene
	PlayButton* play_button = new PlayButton();
	play_button->Init(nullptr);
	play_button->setScene(this);
	play_button->setSpriteID(Textures::MAIN_MENU_PLAY_BUTTON);
	widgets.push_back(play_button);

	//! Initializing the button that exits
	QuitButton* quit_button = new QuitButton();
	quit_button->Init(nullptr);
	quit_button->setScene(this);
	quit_button->setSpriteID(Textures::MAIN_MENU_QUIT_BUTTON);
	widgets.push_back(quit_button);

	//! Initializing the button that leads to the settings scene
	OptionsButton* options_button = new OptionsButton();
	options_button->Init(nullptr);
	options_button->setScene(this);
	options_button->setSpriteID(Textures::MAIN_MENU_OPTIONS_BUTTON);
	widgets.push_back(options_button);


	SquareCollider a, b;
	
	a.Init(nullptr, { 1, -1 }, { 1, 1 });
	b.Init(nullptr, { -1, 3 }, Vector2F(1, 1) * sqrtf(2), PI/4);

	printf("Distance = %g\n", Collider::DistanceBetween(&a, &b, Vector2F(1, -1).Normalized()));

}

void MainMenuScene::Update()
{
	for (auto widget : widgets) {
		widget->Update();
	}
	for (auto widget : widgets) {
		widget->Draw();
	}

	// It is in the end of this function for gentle change of scene
	if (!is_active){
		SceneManager::CloseScene(this);
		return ;
	}
}

void MainMenuScene::Destroy()
{
	for (auto widget : widgets) {
		widget->Destroy();
		delete widget;
	}
	widgets.clear();

	printf("MainMenuScene destroyed!\n");
	std::cout.flush();
}
