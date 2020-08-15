#include "OptionsButton.h"

#include "../../../Engine/AllEngine.h"
#include "../../../GameCore/Textures.h"

#include "../../../GameCore/Scenes/MainOptionsScene.h"

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
	printf("OptionsButton created!\n");
}

void OptionsButton::disfocusReact()
{
	// Nothing for now
}

void OptionsButton::Destroy()
{
	printf("OptionsButton destroyed!\n");
}
