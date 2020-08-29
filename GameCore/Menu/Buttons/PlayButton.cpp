#include "PlayButton.h"

#include <cstdio>

#include "../../../Engine/SceneManagment/SceneManager.h"
#include "../../PTC.h"
#include "../../Scenes/GameplayScene.h"
#include "../../Scenes/MenuScene.h"
#include "../../Textures.h"

PlayButton::PlayButton() {}

void PlayButton::leftClickReact()
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
	PTC::sayCreated("PlayButton");
}

void PlayButton::disfocusReact()
{
	sprite_id = Textures::MAIN_MENU_PLAY_BUTTON;
}

void PlayButton::rightClickReact()
{
	// Nothing for now
}

void PlayButton::Destroy()
{
	PTC::sayDestroyed("PlayButton");
}


