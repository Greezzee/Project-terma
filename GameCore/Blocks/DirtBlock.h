#pragma once

#include <iostream>

#include "../Textures.h"
#include "Block.h"

class DirtBlock : public Block {
public:
	DirtBlock() : Block() {
		this->setSpriteId(Textures::DIRT_BLOCK_TEXTURE);
		setID(11);
	}

	~DirtBlock() {
	}

	void code(char*& buffer) override {

	}
	void decode(char*& buffer) override {

	}

	GameObject* Clone() const {
		return new DirtBlock();
	}

};
