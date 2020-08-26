#pragma once

#include "../Block.h"
#include "../LightSource.h"

class Multiblock;

class StructureBlock : public Block {
public:
	StructureBlock(Multiblock * parent);
	void update();
	GameObject * Clone() const;
	const Multiblock* getParent() const;

private:
	Multiblock * parent;
};
