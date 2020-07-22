#pragma once
#include "GameManager.h"
#include "../Graphics/GraphicManager.h"
#include "../Time/TimeManager.h"
#include "../Control/InputManager.h"
#include <stdio.h>
#include "../SceneManagment/SceneManager.h"

void (*GameManager::init_project)()    = 0;
void (*GameManager::update_project)()  = 0;
void (*GameManager::destroy_project)() = 0;

void GameManager::handleProject(void (*init)(), void (*update)(), void (*dest)()) {
	GameManager::init_project = init;
	GameManager::update_project = update;
	GameManager::destroy_project = dest;
}

bool GameManager::is_exit;
void GameManager::Launch()
{
	is_exit = false;

	// INIT
	//------------------------------
	GraphicManager::Init();
	TimeManager::Init();
	InputManager::Init();
	GameManager::init_project();
	//------------------------------

	int frames = 0;
	unsigned sec = 0;
	while (!is_exit) {
		// UPDATE
		//------------------------------
		TimeManager::Update();
		InputManager::Update();
		update_project();
		//------------------------------

		is_exit = is_exit || SceneManager::UpdateScenes();
		is_exit = is_exit || GraphicManager::Update();
		sec += TimeManager::GetDeltaTime();
		frames++;
		if (sec >= 1000000) {
			sec = 0;
			printf("%d\n", frames);
			frames = 0;
		}
	}

	// DESTROY
	//------------------------------
	destroy_project();
	SceneManager::Destroy();
	GraphicManager::Exit();
	//GlobalTimer::Destroy();
	//------------------------------
}
