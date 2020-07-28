#pragma once

#include "../Textures.h"
#include "Block.h"

class DirtBlock : public Block {
	DirtBlock() : Block() {
		this->setSpriteId(Textures::DIRT_BLOCK_TEXTURE);
	}

	GameObject* clone() const {
		return new DirtBlock();
	}
};
