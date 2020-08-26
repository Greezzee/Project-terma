#include "StructureBlock.h"

#include "../../Map/Map.h"
#include "Multiblock.h"

class Textures;

StructureBlock::StructureBlock(Multiblock *parent) {
	this->parent = parent;
	setSpriteId(-1);
	this->setPassable(parent->isPassable());
}

void StructureBlock::update() {
}

GameObject* StructureBlock::Clone() const {
	return new StructureBlock(parent);
}

const Multiblock* StructureBlock::getParent() const {
	return parent;
}
