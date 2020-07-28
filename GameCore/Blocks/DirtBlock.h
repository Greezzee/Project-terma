#pragma once

#include "../Textures.h"
#include "Block.h"

class DirtBlock : public Block {
	DirtBlock() : Block() {
		this->setSpriteId(Textures::DIRT_BLOCK_TEXTURE);
		this->SetID(11);
	}

	GameObject* clone() const {
		return new DirtBlock();
	}
};
