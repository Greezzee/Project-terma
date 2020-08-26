#include "EditorCurrentBlock.h"

#include <cstdio>
#include <iostream>

EditorCurrentBlock::EditorCurrentBlock()
{
	current_block = nullptr;
}

void EditorCurrentBlock::Init(GameObject *owner) {
	printf("EditorCurrentBlock created!\n");
}

void EditorCurrentBlock::Update()
{
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

void EditorCurrentBlock::setBlock(Block *_block)
{
	current_block = _block;
}

Block* EditorCurrentBlock::getBlock()
{
	return current_block;
}

EditorCurrentBlock::~EditorCurrentBlock() {}
