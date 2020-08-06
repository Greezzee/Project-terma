#include "Player.h"

#include "../../Engine/Control/InputManager.h"
#include "../../Engine/Graphics/DrawData.h"
#include "../../Engine/Graphics/GraphicManager.h"
#include "../../Engine/Utility/Coordinate.h"
#include "../Map.h"
#include "../Textures.h"

Player::Player() {
	camera = GraphicManager::GetView(Views::PLAYER_CAM);

	size = { 5 * BLOCK_SIZE, 5 * BLOCK_SIZE };

	lookingRight = 1;

	this->setCurrentHealth(50);
}

View* Player::getCamera() {
	return camera;
}

void Player::Draw() {
	drawPlayer();
	drawHealthBar();
}

GameObject* Player::clone() const {
	return new Player();
}

void Player::Update() {
	SolidEntity::Update();

	if (InputManager::IsDown(KeyboardKey::R_Right)) {
		speed.x = 350;
		lookingRight = 1;
	} else if (InputManager::IsDown(KeyboardKey::R_Left)) {
		speed.x = -350;
		lookingRight = 0;
	} else
		speed.x = 0;
	if (InputManager::IsDown(KeyboardKey::R_Up) && isInBlocks) {
		speed.y = 1000;
	}

	camera->virtual_position.x = _pos.x;
	camera->virtual_position.y = _pos.y;
}

void Player::Init(GameObject *owner) {
	Entity::Init(owner);
	inventory.init(this);
}

void Player::drawHealthBar() {
	int total = this->getCurrentHealth() / 10;
	float bar_width = BLOCK_SIZE * 4;
	for (int i = 0; i < total; i++) {
		DrawData info = { };

		// BASE DATA
		//----------------------------
		info.position = this->_pos;
		info.position.x -= bar_width / 2;

		info.position.x += ((float)(i) * bar_width / (float)(total));
		info.position.y += (size.y / 2.0f + BLOCK_SIZE);
		info.size = Vector2F(1, 1) * BLOCK_SIZE;
		//----------------------------

		//----------------------------
		info.origin = { 0, 0 };
		info.frame = 0;
		info.layer = 0;
		//----------------------------

		// SET TEXTURE
		//----------------------------
		info.spriteID = Textures::RED_STAR;
		//----------------------------

		// DRAW
		//----------------------------
		GraphicManager::Draw(info, Views::PLAYER_CAM);
		//----------------------------
	}
}

void Player::drawPlayer() {
	DrawData info = { };

	// BASE DATA
	//----------------------------
	info.position = this->_pos;
	info.size = this->size;
	info.size.x *= (lookingRight ? 1.0f : -1.0f);
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
