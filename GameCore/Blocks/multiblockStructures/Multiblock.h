#pragma once

#include "../../../Engine/Utility/Coordinate.h"
#include "../Block.h"

class Multiblock : public Block {
public:
	Multiblock();
	void Update();
	const Vector2I& getSize() const;
	void setSize(const Vector2I &size);

protected:
	Vector2I size;
};

