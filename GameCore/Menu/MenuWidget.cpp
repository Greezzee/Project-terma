#include "MenuWidget.h"

MenuWidget::MenuWidget()
{
	current_scene = nullptr;
	sprite_id = -1;
}

void MenuWidget::setScene(Scene* _scene)
{
	current_scene = _scene;
}

void MenuWidget::setSpriteID(unsigned _id)
{
	sprite_id = _id;
}
