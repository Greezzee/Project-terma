#pragma once

#include "../../../Engine/AllEngine.h"
#include "../../Textures.h"
#include "../LightSource.h"
#include "../MultiblockStructures/Multiblock.h"

class Tree: public Multiblock {
public:
	Tree() :
			Multiblock() {
		setSize( { 10, 10 });
		setSpriteId(Textures::TREE);
		setID(4567);
		setPassable(1);
	}

	void code(char *&buffer) override {

	}
	void decode(char *&buffer) override {

	}

	GameObject* Clone() const {
		return new Tree();
	}
};
