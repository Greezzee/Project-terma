#include "Block.h"

#include <string>

#include "../../Engine/Graphics/GraphicManager.h"

int Block::getSpriteId() const {
	return this->sprite_id;
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
