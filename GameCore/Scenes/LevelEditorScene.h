#pragma once

#include "../Blocks/Block.h"
#include "../Menu/ImageWidgets/EditorCurrentBlockBar.h"
#include "MenuScene.h"
#include "../Menu/ImageWidgets/EditorPanel.h"
#include "../Menu/ImageWidgets/EditorCurrentBlock.h"
#include "../Menu/Buttons/EditorChooseBlock.h"

class Block;
class Map;

class LevelEditorScene : public MenuScene {
	EditorCurrentBlock *block_button;
public:
	// Constructor and destructor
	//----------------------------------------------
	LevelEditorScene();
	~LevelEditorScene();
	//----------------------------------------------

	// BASE
	//----------------------------------------------
	void Init() override;
	void Update() override;
	void Destroy() override;
	//----------------------------------------------

private:

	Map * currentMap = NULL;
	Block* currentBlock;
	char currentLayer = 0;
};
