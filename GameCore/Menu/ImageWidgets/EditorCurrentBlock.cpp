#include "EditorCurrentBlock.h"

#include <cstdio>
#include <iostream>

#include "../../Blocks/Block.h"
#include "../../Blocks/MultiblockStructures/Multiblock.h"

EditorCurrentBlock::EditorCurrentBlock() {
	current_block = nullptr;
	block_type = NONE;
}

void EditorCurrentBlock::Init(GameObject *owner) {
	printf("EditorCurrentBlock created!\n");
}

void EditorCurrentBlock::Update() {
	sprite_id = (current_block == nullptr) ? -1 : current_block->getSpriteId();
}

void EditorCurrentBlock::Draw() {
	DrawData info = { };

	info.position = _pos;

	info.size = _size;

	info.origin = { 0.5, 0.5 };

	info.frame = 0;
	info.layer = this->layer;

	info.spriteID = sprite_id;
	GraphicManager::Draw(info, view_id);
}

void EditorCurrentBlock::Destroy() {
	printf("EditorCurrentBlock destroyed!\n");
	std::cout.flush();
}

void EditorCurrentBlock::setBlock(Block *_block) {
	current_block = _block;

	// If this is a multiblock structure
	if (dynamic_cast<Multiblock*>(current_block) != nullptr) {
		block_type = MULTI;
	} else
		block_type = STANDART;
}

Block* EditorCurrentBlock::getBlock() {
	return current_block;
}

EditorCurrentBlock::~EditorCurrentBlock() {}

enum BLOCK_TYPE EditorCurrentBlock::getBlockType() const {
	return block_type;
}

void EditorCurrentBlock::setBlockType(enum BLOCK_TYPE blockType) {
	block_type = blockType;
}
