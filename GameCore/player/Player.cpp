#include "Player.h"

#include <iostream>

#include "../../Engine/Control/InputManager.h"
#include "../../Engine/Graphics/DrawData.h"
#include "../../Engine/Graphics/GraphicManager.h"
#include "../../Engine/Utility/Coordinate.h"
#include "../Textures.h"

Player::Player() {
	camera = GraphicManager::GetView(Views::TEST);
}

View* Player::getCamera() {
	return camera;
}

void Player::Draw() {
}

GameObject* Player::clone() const {
	return new Player();
}

void Player::Update() {
	if (InputManager::IsDown(KeyboardKey::R_Right)) {
		_pos.x += 5;
	}

	camera->virtual_position.x = _pos.x - camera->virtual_size.x / 2;
	camera->virtual_position.y = _pos.y - camera->virtual_size.y / 2;
}
