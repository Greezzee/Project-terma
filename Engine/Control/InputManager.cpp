#pragma once
#include "InputManager.h"

int max(int a, int b) {
	return a > b ? a : b;
}

KeyData InputManager::_key_info[KeysCount];
sf::Keyboard::Key InputManager::_control_keys[KeysCount];

void InputManager::Init()
{
	for (int i = 0; i < KeysCount; i++) {
		_key_info[i] = { false, false, false };
	}
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
}

void InputManager::Update()
{
	for (int i = 0; i < KeysCount; i++) {
		if (sf::Keyboard::isKeyPressed(_control_keys[i])) {
			if (!_key_info[i].is_down)
				_key_info[i].is_pressed = true;
			else
				_key_info[i].is_pressed = false;
			_key_info[i].is_down = true;
		}
		else {
			if (_key_info[i].is_down)
				_key_info[i].is_realesed = true;
			else
				_key_info[i].is_realesed = false;
			_key_info[i].is_down = false;
		}
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
