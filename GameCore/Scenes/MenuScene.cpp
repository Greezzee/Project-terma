#include "MenuScene.h"

MenuScene::MenuScene()
{
	is_active = true;
}

void MenuScene::drawWidgets()
{
	for (auto widget : widgets) {
		widget->Draw();
	}
}

void MenuScene::disableScene() {
	is_active = false;
}
