#include "Block.h"

#include "Blocks.h"


Block::Block() {
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

int Block::getID() const {
	return id;
}

void Block::setID(int id) {
	this->id = id;
	if (Blocks::isBlocksInitPhaseInProgres()) {
		Blocks::registerBlock(id, this);
	}
}

void Block::setPassable(bool passable) {
	this->passable = passable;
}
