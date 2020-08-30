#pragma once

#include "../Textures.h"
#include "Block.h"

class GrassBlock: public Block {
public:
	GrassBlock() :
			Block() {
		this->setSpriteId(Textures::RED_STONE_TOP);
		this->setID(12);
	}

	void code(char *&buffer) override {

	}
	void decode(char *&buffer) override {

	}

	GameObject* Clone() const {
		return new GrassBlock();
	}

};
