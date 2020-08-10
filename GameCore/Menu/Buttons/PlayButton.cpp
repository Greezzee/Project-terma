#include "PlayButton.h"

#include <cstdio>

#include "../../../Engine/AllEngine.h"
#include "../../Scenes/GameplayScene.h"
#include "../../Textures.h"

PlayButton::PlayButton() {}

void PlayButton::clickReact()
{
	SceneManager::CreateScene(new GameplayScene());
	current_scene->disableScene();
}

void PlayButton::focusReact()
{
	sprite_id = Textures::MAIN_MENU_PLAY_BUTTON_FOCUS;
}

void PlayButton::Init(GameObject* owner)
{
	printf("PlayButton created!\n");
}

void PlayButton::disfocusReact()
{
	sprite_id = Textures::MAIN_MENU_PLAY_BUTTON;
}

void PlayButton::Destroy()
{
	printf("PlayButton destroyed!\n");
}


