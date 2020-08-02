#pragma once

#include "../Textures.h"
#include "Block.h"

class GrassBlock : public Block {
public:
	GrassBlock() : Block() {
		this->setSpriteId(Textures::GRASS_BLOCK_TEXTURE);
		this->SetID(12);
	}

	GameObject* clone() const {
		return new GrassBlock();
	}

	void Update();
};

void GrassBlock::Update() {

}
