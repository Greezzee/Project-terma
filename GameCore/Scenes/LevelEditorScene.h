#pragma once

#include "../Blocks/Block.h"
#include "../Menu/ImageWidgets/EditorCurrentBlockBar.h"
#include "MenuScene.h"
#include "../Menu/ImageWidgets/EditorPanel.h"
#include "../Menu/ImageWidgets/EditorCurrentBlock.h"
#include "../Menu/Buttons/EditorChooseBlock.h"
#include "../Menu/Buttons/EditorModeButton.h"

class Block;
class Map;

enum BLOCK_SITUATION {
	FRONT, WALL
};

class LevelEditorScene : public MenuScene {
	EditorCurrentBlock *block_button;
	enum BLOCK_SITUATION mode;
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
	enum BLOCK_SITUATION getMode() const;
	void setMode(enum BLOCK_SITUATION mode);

	//----------------------------------------------

private:

	Map * currentMap = NULL;
	Block* currentBlock;
	char currentLayer = 0;
};
