#pragma once

#include "../Block.h"

class Multiblock;

class StructureBlock : public Block {
public:
	StructureBlock(Multiblock * parent);
	void update();
	GameObject * clone() const;
private:
	Multiblock * parent;
};
