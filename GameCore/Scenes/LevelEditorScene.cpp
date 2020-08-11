#include "LevelEditorScene.h"

#include "../Controls.h"
#include "MainMenuScene.h"

#include <cstdio>
#include <iostream>
#include <vector>

LevelEditorScene::LevelEditorScene() {}

void LevelEditorScene::Init()
{
	widgets = new std::vector<MenuWidget*>;

	// TODO Initialization of this scene

	printf("LevelEditorScene created!\n");
}

void LevelEditorScene::Update()
{
	// TODO Update scenes

	if (InputManager::IsPressed(Controls::BACK)) {
		SceneManager::CreateScene(new MainMenuScene());
		SceneManager::CloseScene(this);
		return ;
	}
}

void LevelEditorScene::Destroy()
{
	// TODO Destroy all objects

	widgets->clear();
	delete widgets;

	printf("LevelEditorScene destroyed!\n");
	std::cout.flush();

}

LevelEditorScene::~LevelEditorScene() {}
