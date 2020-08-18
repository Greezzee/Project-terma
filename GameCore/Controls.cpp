#include "Controls.h"

KeyboardKey Controls::linking[keys_number] = {};
std::string Controls::tags[keys_number] = {"RIGHT", "LEFT", "UP", "DOWN", "OPEN_INV", "BACK"};

void Controls::LOAD_ALL_GAMEKEYS()
{
	for (unsigned i = 0; i < keys_number; i++) {
		InputManager::LinkToCode(linking[i], i);
	}


	InputManager::LinkToCode(KeyboardKey::RIGHT, Controls::RIGHT);
	InputManager::LinkToCode(KeyboardKey::UP, Controls::UP);
	InputManager::LinkToCode(KeyboardKey::DOWN, Controls::DOWN);
	InputManager::LinkToCode(KeyboardKey::LEFT, Controls::LEFT);
	InputManager::LinkToCode(KeyboardKey::E, Controls::OPEN_INV);
	InputManager::LinkToCode(KeyboardKey::ESC, Controls::BACK);

}
