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
		setPassable(1);
	}

	GameObject* Clone() const {
		return new Tree();
	}
};
