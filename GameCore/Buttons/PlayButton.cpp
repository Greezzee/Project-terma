#include "PlayButton.h"

#include "../../Engine/Control/InputManager.h"
#include "../../Engine/SceneManagment/SceneManager.h"
#include "../../Engine/Graphics/DrawData.h"
#include "../../GameCore/Textures.h"

#include "../../GameCore/Scenes/GameplayScene.h"

PlayButton::PlayButton(Scene *_scene, unsigned _sprite_id) :
		Button(_scene, _sprite_id) {}

bool PlayButton::isClicked()
{
	return InputManager::IsPressed(KeyboardKey::M_Play);
}

void PlayButton::clickReact()
{
	SceneManager::CreateScene(new GameplayScene());
	SceneManager::CloseScene(scene);
}

void PlayButton::focusReact()
{
	//! Nothing for now
}

void PlayButton::Update()
{
	if (isClicked()) {
		clickReact();
	}
}

void PlayButton::Draw()
{
	DrawData info = { };
	//! Later need to write something to support any resolution
	info.position.x = 650;
	info.position.y = 250;

	info.size.x = 410;
	info.size.y = 240;

	info.origin = { 0.5, 0.5 };

	info.frame = 0;
	info.layer = 0;

	info.spriteID = sprite_id;
	GraphicManager::Draw(info, Views::BASIC);
}

void PlayButton::Init(GameObject* owner)
{
	printf("PlayButton created!\n");
}

void PlayButton::Destroy()
{
	printf("PlayButton destroyed!\n");
}

GameObject* PlayButton::clone() const
{
	PlayButton* clone = new PlayButton(scene, sprite_id);

	return clone;
}


