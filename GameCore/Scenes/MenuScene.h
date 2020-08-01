#pragma once

#include <vector>

#include "../../Engine/SceneManagment/Scene.h"
#include "../Menu/MenuWidget.h"

class MenuWidget;

class MenuScene : public Scene {
protected:
	//! Vector that contains all buttons of this menu
	std::vector<MenuWidget*> widgets;

public:
	MenuScene();

	//! These functions draw certain widgets of the menu
	void drawButtons();
	/*
	void drawTextWidgets();
	void drawImageWidgets();
	*/

	//! The Init() method should include creating all widgets and putting them into the suitable vector
	virtual void Init() = 0;
	virtual void Update() = 0;
	//! The Destroy() method should include deleting all widgets in order to free memory
	virtual void Destroy() = 0;
};
