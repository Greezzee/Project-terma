#include "Button.h"

Button::Button() {}

bool Button::isFocused()
{
	return true;
}

void Button::Update()
{
	if (isFocused())
		focusReact();
	if (isClicked())
		clickReact();
}
