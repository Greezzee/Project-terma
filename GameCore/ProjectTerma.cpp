#include "ProjectTerma.h"

#include <cstdio>
#include <iostream>
#include <string>

#include "../Engine/SceneManagment/SceneManager.h"
#include "Controls.h"
#include "Scenes/MainMenuScene.h"
#include "Views.h"

class MainMenuScene;

void ProjectTerma::Init() {
	printf("Game started!\n");
	printf("Loading resources!\n");
	Textures::LOAD_ALL_TEXTURES();
	printf("Textures loaded!\n");
	printf("Loading views!\n");
	Views::LOAD_ALL_VIEWS();
	printf("Views loaded!\n");
	printf("Loading settings!\n");
	Settings::LOAD_SETTINGS();
	printf("Settings loaded!\n");
	printf("Loading controls!\n");
	Controls::LOAD_ALL_GAMEKEYS();
	printf("Controls loaded!\n");
}

void ProjectTerma::Update() {
	SceneManager::CreateScene(new MainMenuScene());
	SceneManager::CloseScene(this);
}

void ProjectTerma::Destroy() {
	printf("Start scene is terminated!\n");
}

void ProjectTerma::report_error(std::string mes) {
	std::cout << "Error reported!\n";
	std::cout << mes << "\n";
	exit(-2);
}
