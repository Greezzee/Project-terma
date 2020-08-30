#include "OptionsButton.h"

#include "../../../Engine/SceneManagment/SceneManager.h"
#include "../../PTC.h"
#include "../../Scenes/MainOptionsScene.h"
#include "../../Textures.h"

OptionsButton::OptionsButton() {}

void OptionsButton::leftClickReact() {
	SceneManager::CreateScene(new MainOptionsScene());
	current_scene->disableScene();
}

void OptionsButton::focusReact()
{
	sprite_id = Textures::MAIN_MENU_OPTIONS_BUTTON_FOCUS;
}

void OptionsButton::rightClickReact()
{
	// Nothing for now
}

void OptionsButton::Init(GameObject *owner)
{
	PTC::sayCreated("OptionsButton");
}

void OptionsButton::disfocusReact()
{
	sprite_id = Textures::MAIN_MENU_OPTIONS_BUTTON;
}

void OptionsButton::Destroy()
{
	PTC::sayCreated("OptionsButton");
}
