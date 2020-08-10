#include "QuitButton.h"

#include <iostream>

#include "../../../Engine/AllEngine.h"
#include "../../../GameCore/Textures.h"

#include "../../../GameCore/Scenes/GameplayScene.h"

QuitButton::QuitButton() {}

void QuitButton::clickReact() {
	current_scene->disableScene();
}

void QuitButton::focusReact() {
	//! Nothing for now
}

void QuitButton::Init(GameObject *owner) {
	printf("QuitButton created!\n");
}

void QuitButton::disfocusReact()
{
	// Nothing for now
}

void QuitButton::Destroy() {
	printf("QuitButton destroyed!\n");
	std::cout.flush();
}
