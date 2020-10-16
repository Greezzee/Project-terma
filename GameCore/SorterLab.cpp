#include "SorterLab.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include "../Engine/SceneManagment/SceneManager.h"
#include "Controls.h"
#include "PTC.h"
#include "Scenes/SLScene.h"
#include "Views.h"

class MainMenuScene;

void SorterLab::Init() {
	PTC::say("Sorter lab started!");
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
}

void SorterLab::Update() {
	SceneManager::CreateScene(new SLScene());
	SceneManager::CloseScene(this);
}

void SorterLab::Destroy() {
	PTC::say("Start scene is terminated!");
}

void SorterLab::report_error(std::string mes) {
	std::cout << "Error reported!\n";
	std::cout << mes << "\n";
	exit(-2);
}
