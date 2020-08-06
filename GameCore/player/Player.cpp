#include "Player.h"

#include "../../Engine/Control/InputManager.h"
#include "../../Engine/Graphics/DrawData.h"
#include "../../Engine/Graphics/GraphicManager.h"
#include "../../Engine/Utility/Coordinate.h"
#include "../Map.h"
#include "../Textures.h"

Player::Player() {
	camera = GraphicManager::GetView(Views::PLAYER_CAM);

	texture_size = { 5 * BLOCK_SIZE, 5 * BLOCK_SIZE };
	collider_size = { 1.7f * BLOCK_SIZE, 5 * BLOCK_SIZE };

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

const float base_acceleration = 4000; // this will be used if players will matches current speed direction
const float stop_acceleration = 8000; // this will be used if players will is not matching current speed direction

void Player::Update() {
	SolidEntity::Update();

	// X
	char going_to = -10;
	if (speed.x > 0) {
		going_to = 1;
	}
	if (speed.x == 0) {
		going_to = 0;
	}
	if (speed.x < 0) {
		going_to = -1;
	}

	char want_to_go = -10;
	if (InputManager::IsDown(KeyboardKey::R_Right)) {
		want_to_go = 1;
		lookingRight = 1;
	} else if (InputManager::IsDown(KeyboardKey::R_Left)) {
		want_to_go = -1;
		lookingRight = 0;
	} else {
		want_to_go = 0;
	}

	if (want_to_go == 1 && going_to == 1) {
		externalForce.x += base_acceleration;
	}
	if (want_to_go == 0 && going_to == 1) {
		externalForce.x -= stop_acceleration;
	}
	if (want_to_go == -1 && going_to == 1) {
		externalForce.x -= stop_acceleration;
	}
	if (want_to_go == 1 && going_to == 0) {
		externalForce.x += base_acceleration;
	}
	if (want_to_go == 0 && going_to == 0) {
		externalForce.x += 0;
	}
	if (want_to_go == -1 && going_to == 0) {
		externalForce.x -= base_acceleration;
	}
	if (want_to_go == 1 && going_to == -1) {
		externalForce.x += stop_acceleration;
	}
	if (want_to_go == 0 && going_to == -1) {
		externalForce.x += stop_acceleration;
	}
	if (want_to_go == -1 && going_to == -1) {
		externalForce.x -= base_acceleration;
	}

	// JUMPS
	if (InputManager::IsDown(KeyboardKey::R_Up) && standsOnTheGround()) {
		externalForce.y = 40000;
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

		info.position.x += ((float) (i) * bar_width / (float) (total));
		info.position.y += (texture_size.y / 2.0f + BLOCK_SIZE);
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
	info.size = this->texture_size;
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
