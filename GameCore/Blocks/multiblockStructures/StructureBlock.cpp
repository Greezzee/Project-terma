#include "StructureBlock.h"

#include "../../Textures.h"
#include "Multiblock.h"

class Textures;

StructureBlock::StructureBlock(Multiblock *parent) {
	this->parent = parent;
	setSpriteId(-1);
	this->setPassable(parent->isPassable());
}

void StructureBlock::update() {
}

GameObject* StructureBlock::clone() const {
	return new StructureBlock(parent);
}
