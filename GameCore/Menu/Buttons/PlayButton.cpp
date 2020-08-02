#include "PlayButton.h"

#include <SFML/System/Vector2.hpp>
#include <cstdio>
#include <iostream>

#include "../../../Engine/Control/InputManager.h"
#include "../../../Engine/Graphics/DrawData.h"
#include "../../../Engine/Graphics/GraphicManager.h"
#include "../../../Engine/SceneManagment/SceneManager.h"
#include "../../../Engine/Utility/Coordinate.h"
#include "../../Scenes/GameplayScene.h"

PlayButton::PlayButton() {}

bool PlayButton::isClicked()
{
	return InputManager::IsPressed(KeyboardKey::M_Play);
}

void PlayButton::clickReact()
{
	SceneManager::CreateScene(new GameplayScene());
	current_scene->disableScene();
}

void PlayButton::focusReact()
{
	//! Nothing for now
}

void PlayButton::Draw()
{
	DrawData info = { };

	// std::cout << "Resolution: x " << resolution.x << ", y " << resolution.y << std::endl;

	info.position = {800, 600};

	// std::cout << "Position: x " << info.position.x << ", y " << info.position.y << std::endl;

	info.size.x = 410;
	info.size.y = 240;

	info.origin = { 0.5, 0.5 };

	info.frame = 0;
	info.layer = 1;

	info.spriteID = this->sprite_id;

	GraphicManager::Draw(info, Views::MAIN_MENU);
}

void PlayButton::Init(GameObject* owner)
{
	printf("PlayButton created!\n");
}

void PlayButton::Destroy()
{
	printf("PlayButton destroyed!\n");
}


