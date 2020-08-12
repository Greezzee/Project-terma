#pragma once

#include "../Blocks/Block.h"
#include "MenuScene.h"

class Block;
class Map;

class LevelEditorScene : public MenuScene {
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
	Block* currentBlock = NULL;
	char currentLayer = 0;
};
