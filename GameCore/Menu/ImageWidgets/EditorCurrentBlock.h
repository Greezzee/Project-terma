#pragma once

#include "../../Blocks/Block.h"
#include "ImageWidget.h"

class EditorCurrentBlock: public ImageWidget {
	Block *current_block;
public:
	EditorCurrentBlock();

	void setBlock(Block *_block);
	Block* getBlock();

	void Init(GameObject *owner) override;
	void Update() override;
	void Draw() override;
	void Destroy() override;

	~EditorCurrentBlock();
};
