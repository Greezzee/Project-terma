#include "MenuLevelEditorButton.h"

#include <cstdio>
#include <iostream>

#include "../../../Engine/SceneManagment/SceneManager.h"
#include "../../PTC.h"
#include "../../Scenes/LevelEditorScene.h"

MenuLevelEditorButton::MenuLevelEditorButton() {}

void MenuLevelEditorButton::leftClickReact()
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
	PTC::sayDestroyed("MenuLevelEditorButton");
}

void MenuLevelEditorButton::Init(GameObject *owner)
{
	PTC::sayCreated("MenuLevelEditorButton");
}

void MenuLevelEditorButton::rightClickReact()
{
	// Nothing for now
}

MenuLevelEditorButton::~MenuLevelEditorButton() {}
