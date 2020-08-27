#pragma once

#include "../Blocks/Block.h"
#include "../Menu/ImageWidgets/EditorCurrentBlockBar.h"
#include "MenuScene.h"
#include "../Menu/ImageWidgets/EditorPanel.h"
#include "../Menu/ImageWidgets/EditorCurrentBlock.h"
#include "../Menu/Buttons/EditorChooseBlock.h"
#include "../Menu/Buttons/EditorModeButton.h"
#include "../Menu/Buttons/EditorDeleteButton.h"

class Block;
class Map;

enum BLOCK_SITUATION {
	FRONT, WALL
};

enum BLOCK_DELETE {
	NO, YES
};

class LevelEditorScene : public MenuScene {
	EditorCurrentBlock *block_button;
	enum BLOCK_SITUATION mode;
	enum BLOCK_DELETE to_delete;

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
	void toDelete();
	void toAdd();
	enum BLOCK_DELETE isDelete();

	//----------------------------------------------

private:

	Map * currentMap = NULL;
	Block* currentBlock;
	char currentLayer = 0;
};
