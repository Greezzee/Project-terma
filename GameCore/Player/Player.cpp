#include "Player.h"

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include "../../Engine/Control/InputManager.h"
#include "../../Engine/Graphics/DrawData.h"
#include "../../Engine/Graphics/GraphicManager.h"
#include "../../Engine/Utility/Coordinate.h"
#include "../Controls.h"
#include "../Items/Item.h"
#include "../Items/LimbSword.h"
#include "../Map/Map.h"
#include "../Textures.h"
#include "../Views.h"

Player::Player() {
	camera = Views::PLAYER_CAM;

	texture_size = { 5 * BLOCK_SIZE, 5 * BLOCK_SIZE };
	collider_size = { 1.7f * BLOCK_SIZE, 5 * BLOCK_SIZE };

	lookingRight = 1;

	this->setCurrentHealth(50);

	inventory = nullptr;
	weapon_equipped = nullptr;
}

unsigned Player::getCamera() {
	return camera;
}

void Player::Draw() {
	drawPlayer();
	drawHealthBar();
}

GameObject* Player::Clone() const {
	return new Player();
}

const float base_acceleration = 2200 / 40 * BLOCK_SIZE; // this will be used if players will matches current speed direction
const float stop_acceleration = 4000 / 40 * BLOCK_SIZE; // this will be used if players will is not matching current speed direction

void Player::Update() {
	SolidEntity::Update();

	if (InputManager::IsDown(Controls::RIGHT)) {
		externalForce.x += base_acceleration;
		lookingRight = 1;
	} else if (InputManager::IsDown(Controls::LEFT)) {
		externalForce.x -= base_acceleration;
		lookingRight = 0;
	} else if (standsOnTheGround()) {
	//	externalForce.x -= speed.x * BLOCK_SIZE;
	}

	// JUMPS
	if (InputManager::IsDown(Controls::UP) && standsOnTheGround()) {
		speed.y = 1100 / 40 * BLOCK_SIZE;
	}

	GraphicManager::GetView(camera)->virtual_position.x = _pos.x;
	GraphicManager::GetView(camera)->virtual_position.y = _pos.y;
}

void Player::Init(GameObject *owner) {
	Entity::Init(owner);

	inventory = new Inventory;
	inventory->Init();

	// TEST ITEMS
	for (int i = 0; i < 19; i++) {
		LimbSword *limb_sword = new LimbSword();
		limb_sword->Init(nullptr);
		limb_sword->setName("Sword " + std::to_string(i));
		inventory->items->at(i) = limb_sword;
	}

	printf("Player created!\n");
	printf("%d item(s) in the inventory!\n", inventory->getItemsNumber());
}

void Player::Destroy() {
	// Clear and destroy inventory
	for (auto item : *(inventory->items)) {
		if (item != nullptr) {
			item->Destroy();
			delete item;
		}
	}

	inventory->Destroy();
	delete inventory;

	printf("Player destroyed!\n");
	std::cout.flush();
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
		info.layer = ENTITIES_LAYER;
		//----------------------------

		// SET TEXTURE
		//----------------------------
		info.spriteID = Textures::RED_STAR;
		//----------------------------

		// DRAW
		//----------------------------
		GraphicManager::Draw(info, camera);
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
	info.layer = ENTITIES_LAYER;
	//----------------------------

	// SET TEXTURE
	//----------------------------
	info.spriteID = Textures::PLAYER_STAND_TEXTURE;
	//----------------------------

	// DRAW
	//----------------------------
	GraphicManager::Draw(info, camera);
	//----------------------------

}

void Player::equipWeapon(Item *weapon) {
	weapon_equipped = weapon;
}

void Player::unequipWeapon() {
	weapon_equipped = nullptr;
}

bool Player::isEquipped() {
	return (weapon_equipped == nullptr) ? false : true;
}

Item* Player::getEquippedWeapon() {
	return weapon_equipped;
}

void Player::setCamera(unsigned camera) {
	this->camera = camera;
}
