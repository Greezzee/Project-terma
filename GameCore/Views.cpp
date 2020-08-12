#include "Views.h"

// Define static variables
unsigned Views::MAIN_MENU = 1;
unsigned Views::PLAYER_CAM = 1;

// Current resolution
const Vector2F resolution = {1024, 576};

void Views::LOAD_ALL_VIEWS() {
	Views::MAIN_MENU = GraphicManager::AddView({{ 0, 0 }, resolution,{ 0, 0 },{ 0, 0 },{ 1600,900 },{ 0, 0 },{ 1, -1 }});
	Views::PLAYER_CAM = GraphicManager::AddView({resolution * 0.5, resolution * 0.5, { 0.5, 0.5 }, { 0, 0 }, { 1600,900 }, { 0.5, 0.5 }, { 1, -1 }});
}
