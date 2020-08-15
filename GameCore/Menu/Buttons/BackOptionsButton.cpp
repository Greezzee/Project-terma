#include "BackOptionsButton.h"

#include "../../../Engine/AllEngine.h"
#include "../../../GameCore/Textures.h"
#include "../../Scenes/MainMenuScene.h"

#include "../../../GameCore/Scenes/MainOptionsScene.h"

BackOptionsButton::BackOptionsButton() {
}

void BackOptionsButton::focusReact() {
	// Nothing for now
}

void BackOptionsButton::Init(GameObject *owner) {
	printf("BackOptionsButton created!\n");
}

void BackOptionsButton::disfocusReact() {
	// Nothing for now
}

void BackOptionsButton::rightClickReact()
{
	// Nothing for now
}

void BackOptionsButton::leftClickReact() {
	SceneManager::CreateScene(new MainMenuScene());
	current_scene->disableScene();
}

void BackOptionsButton::Destroy() {
	printf("BackOptionsButton destroyed!\n");
}
