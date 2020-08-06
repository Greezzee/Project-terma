#include "Entity.h"

#include <iostream>

#include "../../Engine/Gameplay/GameField.h"
#include "../../Engine/Time/TimeManager.h"
#include "../Map.h"

void Entity::Destroy() {
}

void Entity::Init(GameObject *owner) {
}

void Entity::setMap( Map *map) {
	this->map = map;
}

Map* Entity::getMap() {
	return this->map;
}

void Entity::Update() {
	float dt = TimeManager::GetDeltaTimeF();

	_pos += dt * speed;
	speed += dt * acceleration;

	acceleration = {0, 0};
}

void Entity::setColliderSize(const Vector2F &colliderSize) {
	collider_size = colliderSize;
}

void Entity::setTextureSize(const Vector2F &textureSize) {
	texture_size = textureSize;
}
