#include "Engine/GameManagment/GameManager.h"
#include "GameCore/ProjectTerma.h"

int main() {
	Scene* start = new ProjectTerma;
	start->Init();
	GameManager::Launch(start);
	return 0;
}