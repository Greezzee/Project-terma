#include "OptionsButton.h"

#include <cstdio>

#include "../../../Engine/SceneManagment/SceneManager.h"
#include "../../PTC.h"
#include "../../Scenes/MainOptionsScene.h"

OptionsButton::OptionsButton() {}

void OptionsButton::leftClickReact() {
	SceneManager::CreateScene(new MainOptionsScene());
	current_scene->disableScene();
}

void OptionsButton::focusReact()
{
	//! Nothing for now
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
	// Nothing for now
}

void OptionsButton::Destroy()
{
	PTC::sayCreated("OptionsButton");
}
