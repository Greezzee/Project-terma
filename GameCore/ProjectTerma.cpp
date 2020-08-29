#include "ProjectTerma.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

#include "../Engine/SceneManagment/SceneManager.h"
#include "Blocks/Blocks.h"
#include "Controls.h"
#include "PTC.h"
#include "Scenes/MainMenuScene.h"
#include "Views.h"

class MainMenuScene;

void ProjectTerma::Init() {
	PTC::say("Game started!");
	PTC::say("Loading resources!");
	Textures::LOAD_ALL_TEXTURES();
	PTC::say("Textures loaded!");
	PTC::say("Loading views!");
	Views::LOAD_ALL_VIEWS();
	PTC::say("Views loaded!");
	PTC::say("Loading settings!");
	Settings::LOAD_SETTINGS();
	PTC::say("Settings loaded!");
	PTC::say("Loading controls!");
	Controls::LOAD_ALL_GAMEKEYS();
	PTC::say("Controls loaded!");
	PTC::say("Loading blocks!");
	Blocks::LOAD_ALL_BLOCKS();
	PTC::say("Blocks loaded!");
}

void ProjectTerma::Update() {
	SceneManager::CreateScene(new MainMenuScene());
	SceneManager::CloseScene(this);
}

void ProjectTerma::Destroy() {
	PTC::say("Start scene is terminated!");
}

void ProjectTerma::report_error(std::string mes) {
	std::cout << "Error reported!\n";
	std::cout << mes << "\n";
	exit(-2);
}
