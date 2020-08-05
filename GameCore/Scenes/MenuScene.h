#pragma once

#include <vector>

#include "../../Engine/SceneManagment/Scene.h"
#include "../Menu/MenuWidget.h"

class MenuWidget;

//! Все сцены меню должны наслдоваться от этого класса. Все виджеты
//! должны при инициализации класться в вектор widgets. Доступные
//! виджеты: Button и ImageWidget.
class MenuScene : public Scene {
protected:
	//! Shows whether the scene is active (for correct switching scenes with buttons)
	bool is_active;
	//! Vector that contains all buttons of this menu
	std::vector<MenuWidget*> widgets;
public:
	MenuScene();

	//! These functions draw certain widgets of the menu
	void drawWidgets();
	//! Sets the 'is_active' variable to false
	void disableScene();

	//! The Init() method should include creating all widgets and putting them into the suitable vector
	virtual void Init() = 0;
	virtual void Update() = 0;
	//! The Destroy() method should include deleting all widgets in order to free memory
	virtual void Destroy() = 0;
};
