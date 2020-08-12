#pragma once

#include "../Textures.h"
#include "Block.h"

class GrassBlock : public Block {
public:
	GrassBlock() : Block() {
		this->setSpriteId(Textures::RED_STONE_TOP);
		this->SetID(12);
	}

	GameObject* Clone() const {
		return new GrassBlock();
	}

};
