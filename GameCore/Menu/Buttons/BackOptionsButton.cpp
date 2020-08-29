#include "BackOptionsButton.h"

#include <cstdio>

#include "../../../Engine/SceneManagment/SceneManager.h"
#include "../../PTC.h"
#include "../../Scenes/MainMenuScene.h"

BackOptionsButton::BackOptionsButton() {
}

void BackOptionsButton::focusReact() {
	// Nothing for now
}

void BackOptionsButton::Init(GameObject *owner) {
	PTC::sayCreated("BackOptionsButton");
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
	PTC::sayDestroyed("BackOptionsButton");
}
