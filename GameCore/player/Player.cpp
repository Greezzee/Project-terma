#include "Player.h"

#include "../../Engine/Control/InputManager.h"
#include "../../Engine/Graphics/DrawData.h"
#include "../../Engine/Graphics/GraphicManager.h"
#include "../../Engine/Utility/Coordinate.h"
#include "../Map.h"
#include "../Textures.h"

Player::Player() {
	camera = GraphicManager::GetView(Views::PLAYER_CAM);
	size = { 3 * BLOCK_SIZE, 6 * BLOCK_SIZE };
}

View* Player::getCamera() {
	return camera;
}

void Player::Draw() {
	DrawData info = { };

	// BASE DATA
	//----------------------------
	info.position = this->_pos;
	info.size = this->size;
	info.rotation = _angle;
	//----------------------------

	//----------------------------
	info.origin = { 0.5, 0.5 };
	info.frame = 0;
	info.layer = 0;
	//----------------------------

	// SET TEXTURE
	//----------------------------
	info.spriteID = Textures::PLAYER_STAND_TEXTURE;
	//----------------------------

	// DRAW
	//----------------------------
	GraphicManager::Draw(info, Views::PLAYER_CAM);
	//----------------------------
}

GameObject* Player::clone() const {
	return new Player();
}

void Player::Update() {
	SolidEntity::Update();

	if (InputManager::IsDown(KeyboardKey::R_Right)) {
		speed.x = 50;
	} else if (InputManager::IsDown(KeyboardKey::R_Left)) {
		speed.x = -50;
	} else
		speed.x = 0;
	if (InputManager::IsDown(KeyboardKey::R_Up)) {
		_pos.y += 1;
	}

	camera->virtual_position.x = _pos.x;
	camera->virtual_position.y = _pos.y;
}
