#pragma once

#include "../Block.h"

class Multiblock;

class StructureBlock : Block {
public:
	StructureBlock(Multiblock * parent);
	void update();
	GameObject * clone();
private:
	Multiblock * parent;
};
