#pragma once

#include "../Textures.h"
#include "Block.h"

class DirtBlock : public Block {
public:
	DirtBlock() : Block() {
		this->setSpriteId(Textures::DIRT_BLOCK_TEXTURE);
		this->SetID(11);
	}

	~DirtBlock() {
	}

	GameObject* Clone() const {
		return new DirtBlock();
	}

	void Update();
};

void DirtBlock::Update() {
}
