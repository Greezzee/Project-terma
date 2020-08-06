#include "Block.h"

#include <string>

#include "../../Engine/Graphics/GraphicManager.h"

int Block::getSpriteId() const {
	return this->sprite_id;
}

void Block::addLightLevel(float add) {
	lightLevel += add;
	lightLevel = std::min(1.0f, std::max(0.0f, lightLevel));
}

void Block::setSpriteId(int id) {
	this->sprite_id = id;
}

void Block::Draw() {
}

void Block::Destroy() {
}

void Block::Init(GameObject *owner) {
}

void Block::Update() {
}

bool Block::isPassable() const {
	return passable;
}

void Block::setPassable(bool passable) {
	this->passable = passable;
}

float Block::getLightLevel() const {
	return lightLevel;
}

void Block::setLightLevel(float lightLevel) {
	this->lightLevel = lightLevel;
}
