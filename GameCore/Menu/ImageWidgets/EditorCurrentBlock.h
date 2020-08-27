#pragma once

#include "../../Blocks/Block.h"
#include "ImageWidget.h"

enum BLOCK_TYPE {
	NONE, STANDART, MULTI
};

class EditorCurrentBlock: public ImageWidget {
	Block *current_block;
	enum BLOCK_TYPE block_type;
public:
	EditorCurrentBlock();

	void setBlock(Block *_block);
	Block* getBlock();

	void Init(GameObject *owner) override;
	void Update() override;
	void Draw() override;
	void Destroy() override;

	~EditorCurrentBlock();
	enum BLOCK_TYPE getBlockType() const;
	void setBlockType(enum BLOCK_TYPE blockType);
};
