#include "MenuWidget.h"

MenuWidget::MenuWidget()
{
	current_scene = nullptr;
	sprite_id = -1;
	_size = {0, 0};
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

void MenuWidget::SetSize(Vector2F __size) {
	_size = __size;
}

Vector2F MenuWidget::GetSize() {
	return _size;
}



