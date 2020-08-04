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

void PlayButton::clickReact()
{
	SceneManager::CreateScene(new GameplayScene());
	current_scene->disableScene();
}

void PlayButton::focusReact()
{
	//! Nothing for now
}

void PlayButton::Init(GameObject* owner)
{
	printf("PlayButton created!\n");
}

void PlayButton::Destroy()
{
	printf("PlayButton destroyed!\n");
}


