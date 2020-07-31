#pragma once

#include <iostream>

#include "../Textures.h"
#include "Block.h"

class DirtBlock : public Block {
public:
	DirtBlock() : Block() {
		this->setSpriteId(Textures::DIRT_BLOCK_TEXTURE);
		this->SetID(11);
	}

	GameObject* clone() const {
		return new DirtBlock();
	}

	void Update();
};

void DirtBlock::Update() {
}
