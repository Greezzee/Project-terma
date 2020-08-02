#include "MenuWidget.h"

MenuWidget::MenuWidget()
{
	current_scene = nullptr;
	sprite_id = -1;
}

void MenuWidget::setScene(MenuScene* _scene)
{
	current_scene = _scene;
}

void MenuWidget::setSpriteID(unsigned _id)
{
	sprite_id = _id;
}

GameObject* MenuWidget::clone() const
{
	printf("Error! Cloning MenuWidget isn't supported\n");

	return nullptr;
}

void MenuWidget::setScalPos(Vector2F pos) {
	scal_position = pos;
}

