#include "MenuScene.h"

MenuScene::MenuScene() {}

void MenuScene::drawButtons()
{
	for (auto button : buttons) {
		button->Draw();
	}
}

/*
void MenuScene::drawTextWidgets()
{
	for (auto text_widget : text_widgets) {
		text_widget.Draw();
	}
}
void MenuScene::drawImageWidgets()
{
	for (auto image_widget : image_widgets) {
			image_widget.Draw();
		}
}
*/
