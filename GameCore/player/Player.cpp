#include "Player.h"

#include "../../Engine/Control/InputManager.h"
#include "../../Engine/Graphics/DrawData.h"
#include "../../Engine/Graphics/GraphicManager.h"
#include "../../Engine/Utility/Coordinate.h"
#include "../Map.h"
#include "../Textures.h"

Player::Player() {
	camera = GraphicManager::GetView(Views::PLAYER_CAM);
}

View* Player::getCamera() {
	return camera;
}

void Player::Draw() {
	DrawData info = { };
	info.position.x = GetPos().x;
	info.position.y = GetPos().y;

	info.size.x = 2 * BLOCK_SIZE;
	info.size.y = 6 * BLOCK_SIZE;

	info.origin = { 0.5, 0.5 };

	info.frame = 0;
	info.layer = 0;

	info.spriteID = Textures::PLAYER_STAND_TEXTURE;
	GraphicManager::Draw(info, Views::PLAYER_CAM);
}

GameObject* Player::clone() const {
	return new Player();
}

void Player::Update() {
	if (InputManager::IsDown(KeyboardKey::R_Right)) {
		_pos.x += 5;
	}
	if (InputManager::IsDown(KeyboardKey::R_Left)) {
		_pos.x -= 5;
	}
	if (InputManager::IsDown(KeyboardKey::R_Up)) {
		_pos.y += 5;
	}
	if (InputManager::IsDown(KeyboardKey::R_Down)) {
		_pos.y -= 5;
	}

	camera->virtual_position.x = _pos.x;
	camera->virtual_position.y = _pos.y;
}
