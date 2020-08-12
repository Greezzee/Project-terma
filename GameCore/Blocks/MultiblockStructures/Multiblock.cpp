#include "../MultiblockStructures/Multiblock.h"

Multiblock::Multiblock() {
}

void Multiblock::Update() {
}

const Vector2I& Multiblock::getSize() const {
	return size;
}

void Multiblock::setSize(const Vector2I &size) {
	this->size = size;
}
