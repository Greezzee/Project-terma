#pragma once

#include "../../../Engine/Utility/Coordinate.h"
#include "../Block.h"

class Multiblock : public Block {
public:
	Multiblock();
	void Update();
protected:
	Vector2I size;
};

