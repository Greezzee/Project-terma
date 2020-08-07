#pragma once
#include "InputManager.h"
#include "../Graphics/GraphicManager.h"
int max(int a, int b) {
	return a > b ? a : b;
}

KeyData InputManager::_key_info[KeysCount];
MouseData InputManager::_mouse_info;
sf::Keyboard::Key InputManager::_control_keys[KeysCount];

void InputManager::Init()
{
	for (int i = 0; i < KeysCount; i++) {
		_key_info[i] = { false, false, false };
	}

	_mouse_info = { {0, 0}, {false, false, false}, {false, false, false} };

	_control_keys[KeyboardKey::L_Left] = sf::Keyboard::A;
	_control_keys[KeyboardKey::L_Right] = sf::Keyboard::D;
	_control_keys[KeyboardKey::L_Up] = sf::Keyboard::W;
	_control_keys[KeyboardKey::L_Down] = sf::Keyboard::S;
	_control_keys[KeyboardKey::L_ShootA] = sf::Keyboard::F;
	_control_keys[KeyboardKey::L_ShootB] = sf::Keyboard::G;
	_control_keys[KeyboardKey::R_Left] = sf::Keyboard::Left;
	_control_keys[KeyboardKey::R_Right] = sf::Keyboard::Right;
	_control_keys[KeyboardKey::R_Up] = sf::Keyboard::Up;
	_control_keys[KeyboardKey::R_Down] = sf::Keyboard::Down;
	_control_keys[KeyboardKey::R_ShootA] = sf::Keyboard::Slash;
	_control_keys[KeyboardKey::R_ShootB] = sf::Keyboard::Period;
	_control_keys[KeyboardKey::BACK] = sf::Keyboard::Escape;
	_control_keys[KeyboardKey::OPEN_INV] = sf::Keyboard::E;
}

void InputManager::Update()
{
	for (int i = 0; i < KeysCount; i++) {
		if (_key_info[i].is_pressed)
			_key_info[i].is_pressed = false;
		if (_key_info[i].is_realesed)
			_key_info[i].is_realesed = false;
		if (sf::Keyboard::isKeyPressed(_control_keys[i])) {
			if (!_key_info[i].is_down)
				_key_info[i].is_pressed = true;
			_key_info[i].is_down = true;
		}
		else {
			if (_key_info[i].is_down)
				_key_info[i].is_realesed = true;
			_key_info[i].is_down = false;
		}
	}

	_mouse_info.pos = { (float)sf::Mouse::getPosition(*GraphicManager::GetWindow()).x, (float)sf::Mouse::getPosition(*GraphicManager::GetWindow()).y };
	_mouse_info.pos += Vector2F((float)GraphicManager::GetWindow()->getSize().x, (float)GraphicManager::GetWindow()->getSize().y) / 2;

	if (_mouse_info.l_button.is_pressed)
		_mouse_info.l_button.is_pressed = false;
	if (_mouse_info.l_button.is_realesed)
		_mouse_info.l_button.is_realesed = false;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		if (!_mouse_info.l_button.is_down)
			_mouse_info.l_button.is_pressed = true;
		_mouse_info.l_button.is_down = true;
	}
	else {
		if (_mouse_info.l_button.is_down)
			_mouse_info.l_button.is_realesed = true;
		_mouse_info.l_button.is_down = false;
	}

	if (_mouse_info.r_button.is_pressed)
		_mouse_info.r_button.is_pressed = false;
	if (_mouse_info.r_button.is_realesed)
		_mouse_info.r_button.is_realesed = false;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
		if (!_mouse_info.r_button.is_down)
			_mouse_info.r_button.is_pressed = true;
		else
			_mouse_info.r_button.is_pressed = false;
		_mouse_info.r_button.is_down = true;
	}
	else {
		if (_mouse_info.r_button.is_down)
			_mouse_info.r_button.is_realesed = true;
		else
			_mouse_info.r_button.is_realesed = false;
		_mouse_info.r_button.is_down = false;
	}

}

bool InputManager::IsDown(KeyboardKey key)
{
	return _key_info[key].is_down;
}

bool InputManager::IsUp(KeyboardKey key)
{
	return !_key_info[key].is_down;
}

bool InputManager::IsPressed(KeyboardKey key)
{
	return _key_info[key].is_pressed;
}

bool InputManager::IsRealesed(KeyboardKey key)
{
	return _key_info[key].is_realesed;
}

Vector2F InputManager::GetMousePos()
{
	return _mouse_info.pos;
}


bool InputManager::IsPressed(MouseKey key)
{
	switch (key)
	{
	case Mouse_Left:
		return _mouse_info.l_button.is_pressed;
		break;
	case Mouse_Right:
		return _mouse_info.r_button.is_pressed;
		break;
	default:
		return false;
		break;
	}
}

bool InputManager::IsRealesed(MouseKey key)
{
	switch (key)
	{
	case Mouse_Left:
		return _mouse_info.l_button.is_realesed;
		break;
	case Mouse_Right:
		return _mouse_info.r_button.is_realesed;
		break;
	default:
		return false;
		break;
	}
}

bool InputManager::IsUp(MouseKey key)
{
	return !IsDown(key);
}

bool InputManager::IsDown(MouseKey key)
{
	switch (key)
	{
	case Mouse_Left:
		return _mouse_info.l_button.is_down;
		break;
	case Mouse_Right:
		return _mouse_info.r_button.is_down;
		break;
	default:
		return false;
		break;
	}
}
