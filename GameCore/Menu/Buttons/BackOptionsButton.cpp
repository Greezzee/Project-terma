#include "BackOptionsButton.h"

#include "../../../Engine/Control/InputManager.h"
#include "../../../Engine/SceneManagment/SceneManager.h"
#include "../../../Engine/Graphics/DrawData.h"
#include "../../../GameCore/Textures.h"
#include "../../Scenes/MainMenuScene.h"

#include "../../../GameCore/Scenes/MainOptionsScene.h"

BackOptionsButton::BackOptionsButton() {}

void BackOptionsButton::clickReact()
{
	SceneManager::CreateScene(new MainMenuScene());
	current_scene->disableScene();
}

void BackOptionsButton::focusReact()
{
	// Nothing for now
}

void BackOptionsButton::Init(GameObject *owner)
{
	printf("BackOptionsButton created!\n");
}

void BackOptionsButton::Destroy() {
	printf("BackOptionsButton destroyed!\n");
}
