#include "OptionsButton.h"

#include "../../../Engine/Control/InputManager.h"
#include "../../../Engine/SceneManagment/SceneManager.h"
#include "../../../Engine/Graphics/DrawData.h"
#include "../../../GameCore/Textures.h"

#include "../../../GameCore/Scenes/MainOptionsScene.h"

OptionsButton::OptionsButton() {}

void OptionsButton::clickReact() {
	SceneManager::CreateScene(new MainOptionsScene());
	current_scene->disableScene();
}

void OptionsButton::focusReact()
{
	//! Nothing for now
}

void OptionsButton::Init(GameObject *owner)
{
	printf("OptionsButton created!\n");
}

void OptionsButton::Destroy()
{
	printf("OptionsButton destroyed!\n");
}
