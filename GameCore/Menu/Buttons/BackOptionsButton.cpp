#include "BackOptionsButton.h"

#include "../../../Engine/Control/InputManager.h"
#include "../../../Engine/SceneManagment/SceneManager.h"
#include "../../../Engine/Graphics/DrawData.h"
#include "../../../GameCore/Textures.h"
#include "../../Scenes/MainMenuScene.h"

#include "../../../GameCore/Scenes/MainOptionsScene.h"

BackOptionsButton::BackOptionsButton() {}

bool BackOptionsButton::isClicked()
{
	return InputManager::IsPressed(KeyboardKey::M_S_Back);
}

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

void BackOptionsButton::Draw()
{
	DrawData info = { };

	info.position.x = 200;
	info.position.y = 750;

	info.size.x = 280;
	info.size.y = 280;

	info.origin = { 0.5, 0.5 };

	info.frame = 0;
	info.layer = 1;

	info.spriteID = this->sprite_id;
	GraphicManager::Draw(info, Views::MAIN_MENU);
}

void BackOptionsButton::Destroy() {
	printf("BackOptionsButton destroyed!\n");
}
