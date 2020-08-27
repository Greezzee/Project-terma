#include "EditorChooseBlock.h"

#include <cstdio>
#include <iostream>

#include "../../Blocks/Blocks.h"

EditorChooseBlock::EditorChooseBlock(EditorCurrentBlock* _block)
{
	block = nullptr;
	current_block = _block;
}

void EditorChooseBlock::Update() {
	if (block != nullptr)
		sprite_id = block->getSpriteId();

	if (isFocused())
		focusReact();
	else
		disfocusReact();

	if (isRightClicked())
		rightClickReact();
	else if (isLeftClicked())
		leftClickReact();
}

void EditorChooseBlock::rightClickReact()
{
	// Nothing for now
}

void EditorChooseBlock::leftClickReact()
{
	// !!
	if (block == nullptr)
		return ;

	current_block->setBlock(block);
}

void EditorChooseBlock::focusReact()
{
	// Nothing for now
}

void EditorChooseBlock::disfocusReact()
{
	// Nothing for now
}

void EditorChooseBlock::Destroy()
{
	if (block != nullptr) {
		block->Destroy();
		delete block;
		block = nullptr;
	}

	printf("EditorChooseBlock destroyed!\n");
	std::cout.flush();
}

void EditorChooseBlock::Init(GameObject *owner)
{
	printf("EditorChooseBlock created!\n");
}

Block* EditorChooseBlock::getBlock() {
	return block;
}

void EditorChooseBlock::setBlock(Block *block) {
	this->block = block;
}

EditorChooseBlock::~EditorChooseBlock() {}
