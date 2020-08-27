#pragma once

#include "../../Blocks/Block.h"
#include "Button.h"
#include "../ImageWidgets/EditorCurrentBlock.h"

class EditorChooseBlock: public Button {
	Block* block;
	EditorCurrentBlock* current_block;
public:
	EditorChooseBlock(EditorCurrentBlock* _block);

	void rightClickReact() override;
	void leftClickReact() override;

	void focusReact() override;
	void disfocusReact() override;
	void Destroy() override;
	void Init(GameObject *owner) override;
	void Update() override;

	~EditorChooseBlock();
	Block* getBlock();
	void setBlock(Block *block);
};
