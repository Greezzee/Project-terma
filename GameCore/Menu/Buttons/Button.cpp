#include "Button.h"

#include "../../../Engine/Control/InputManager.h"
#include "../../../Engine/Graphics/DrawData.h"
#include "../../../Engine/Graphics/GraphicManager.h"
#include "../../../Engine/Utility/Coordinate.h"

Button::Button() {}

bool Button::isClicked() {
	bool _click = InputManager::IsPressed(MouseKey::Mouse_Left);
	Vector2F _mpos = GraphicManager::ConvertRealToView(
			InputManager::GetMousePos(), Views::MAIN_MENU);
	bool _res = (_mpos.x >= _pos.x - _size.x * 0.5 + _gap.x)
			&& (_mpos.x <= 0.5 * _size.x + _pos.x - _gap.x)
			&& (_mpos.y >= _pos.y - _size.y * 0.5 + _gap.y)
			&& (_mpos.y <= 0.5 * _size.y + _pos.y - _gap.y) && _click;

	return _res;
}

bool Button::isFocused() {
	Vector2F _mpos = GraphicManager::ConvertRealToView(
			InputManager::GetMousePos(), Views::MAIN_MENU);
	bool _res = (_mpos.x >= _pos.x - _size.x * 0.5)
			&& (_mpos.x <= 0.5 * _size.x + _pos.x)
			&& (_mpos.y >= _pos.y - _size.y * 0.5)
			&& (_mpos.y <= 0.5 * _size.y + _pos.y);

	return _res;
}

void Button::Draw() {
	DrawData info = { };

	info.position = _pos;

	info.size = _size;

	info.origin = { 0.5, 0.5 };

	info.frame = 0;
	info.layer = 1;

	info.spriteID = this->sprite_id;
	GraphicManager::Draw(info, Views::MAIN_MENU);
}

void Button::Update() {
	if (isFocused())
		focusReact();
	if (isClicked())
		clickReact();
}

void Button::SetSize(Vector2F __size) {
	_size = __size;
}

Vector2F Button::GetSize() {
	return _size;
}

void Button::SetGap(Vector2F __gap)
{
	_gap = __gap;
}
