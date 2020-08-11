#pragma once

#include "../../Engine/AllEngine.h"
#include "../Menu/MenuWidget.h"

#include "MenuScene.h"

class LevelEditorScene : public MenuScene {
public:
	LevelEditorScene();

	void Init() override;
	void Update() override;
	void Destroy() override;

	~LevelEditorScene();
};
