#pragma once

#include "../Block.h"

class Multiblock : public Block {
public:
	Multiblock();
	virtual GameObject* clone();
	void Update();
};

