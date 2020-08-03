#include "OptionsButton.h"

#include "../../../Engine/Control/InputManager.h"
#include "../../../Engine/SceneManagment/SceneManager.h"
#include "../../../Engine/Graphics/DrawData.h"
#include "../../../GameCore/Textures.h"

#include "../../../GameCore/Scenes/MainOptionsScene.h"

OptionsButton::OptionsButton() {
}

bool OptionsButton::isClicked() {
	return InputManager::IsPressed(KeyboardKey::M_Sett);
}

void OptionsButton::clickReact() {
	SceneManager::CreateScene(new MainOptionsScene());
	current_scene->disableScene();
}

void OptionsButton::focusReact()
{
	//! Nothing for now
}

void OptionsButton::Draw()
{
	DrawData info = { };

	info.position.x = 800;
	info.position.y = 400;

	info.size.x = 760;
	info.size.y = 230;

	info.origin = { 0.5, 0.5 };

	info.frame = 0;
	info.layer = 1;

	info.spriteID = this->sprite_id;
	GraphicManager::Draw(info, Views::MAIN_MENU);

}

void OptionsButton::Init(GameObject *owner)
{
	printf("OptionsButton created!\n");
}

void OptionsButton::Destroy()
{
	printf("OptionsButton destroyed!\n");
}
