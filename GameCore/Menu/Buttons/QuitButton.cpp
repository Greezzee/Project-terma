#include "QuitButton.h"

#include <iostream>

#include "../../../Engine/Control/InputManager.h"
#include "../../../Engine/SceneManagment/SceneManager.h"
#include "../../../Engine/Graphics/DrawData.h"
#include "../../../GameCore/Textures.h"

#include "../../../GameCore/Scenes/GameplayScene.h"

QuitButton::QuitButton() {}

bool QuitButton::isClicked() {
	return InputManager::IsPressed(KeyboardKey::M_Quit);
}

void QuitButton::clickReact() {
	current_scene->disableScene();
}

void QuitButton::focusReact() {
	//! Nothing for now
}

void QuitButton::Init(GameObject *owner) {
	printf("QuitButton created!\n");
}

void QuitButton::Draw() {
	DrawData info = { };

	info.position.x = 800;
	info.position.y = 200;

	info.size.x = 490;
	info.size.y = 190;

	info.origin = { 0.5, 0.5 };

	info.frame = 0;
	info.layer = 1;

	info.spriteID = this->sprite_id;
	GraphicManager::Draw(info, Views::MAIN_MENU);
}

void QuitButton::Destroy() {
	printf("QuitButton destroyed!\n");
	std::cout.flush();
}
