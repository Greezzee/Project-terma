#include "Engine/AllEngine.h"
#include "GameCore/ProjectTerma.h"

int main() {
	GameManager::Init();
	Scene* start = new ProjectTerma;
	start->Init();
	GameManager::Launch(start);
	return 0;
}