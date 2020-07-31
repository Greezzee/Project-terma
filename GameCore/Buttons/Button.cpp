#include "Button.h"

Button::Button(Scene *_scene, unsigned _sprite_id)
{
	scene = _scene;
	sprite_id = _sprite_id;
}

bool Button::isFocused()
{
	return true;
}
