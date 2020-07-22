#include <iostream>
#include "../Engine/Gameplay/GameManager.h"
#include "Scenes/MainMenuScene.h"
#include "../Engine/SceneManagment/SceneManager.h"

class ProjectTerma {
public:
	static void init() {
		//GraphicManager::LoadPack("Menu");
		SceneManager::CreateScene(new MainMenuScene);
	}

	static void update() {

	}

	static void destroy() {

	}
};

int main() {
	GameManager::handleProject(ProjectTerma::init, ProjectTerma::update, ProjectTerma::destroy);
	GameManager::Launch();
	return 0;
}
