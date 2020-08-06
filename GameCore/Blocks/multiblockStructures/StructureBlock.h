#pragma once

#include "../Block.h"
#include "../LightSource.h"

class Multiblock;

class StructureBlock : public Block, public LightSource {
public:
	StructureBlock(Multiblock * parent);
	void update();
	GameObject * clone() const;
private:
	Multiblock * parent;
};
