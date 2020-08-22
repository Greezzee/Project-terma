#include "Block.h"

#include <algorithm>

Block::Block() {
	id = 0;
}

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

unsigned int Block::getID() const {
	return id;
}

void Block::setID(unsigned int id) {
	this->id = id;
}

void Block::setPassable(bool passable) {
	this->passable = passable;
}
