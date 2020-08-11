#include "MenuLevelEditorButton.h"

#include <cstdio>
#include <iostream>

#include "../../../Engine/SceneManagment/SceneManager.h"
#include "../../Scenes/LevelEditorScene.h"

MenuLevelEditorButton::MenuLevelEditorButton() {}

void MenuLevelEditorButton::clickReact()
{
	SceneManager::CreateScene(new LevelEditorScene());
	current_scene->disableScene();
}

void MenuLevelEditorButton::focusReact()
{
	// Nothing for now
}

void MenuLevelEditorButton::disfocusReact()
{
	// Nothing for now
}

void MenuLevelEditorButton::Destroy()
{
	printf("MenuLevelEditorButton destroyed!\n");
	std::cout.flush();
}

void MenuLevelEditorButton::Init(GameObject *owner)
{
	printf("MenuLevelEditorButton created!\n");
}

MenuLevelEditorButton::~MenuLevelEditorButton() {}
