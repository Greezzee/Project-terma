#pragma once

#include "../Block.h"

class Multiblock;

class StructureBlock: public Block {
public:
	StructureBlock(Multiblock *parent);
	void update();
	GameObject* Clone() const;
	void code(char *&buffer) override {

	}
	void decode(char *&buffer) override {

	}

	const Multiblock* getParent() const;

private:
	Multiblock *parent;
};
