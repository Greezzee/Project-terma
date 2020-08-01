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

void Entity::setSize( Vector2F size) {
	this->size = size;
}

Map* Entity::getMap() {
	return (Map*) gamefield;
}

void Entity::Update() {

	float dt = TimeManager::GetDeltaTimeF();

	_pos += dt * speed;
	speed += dt * acceleration;
}
