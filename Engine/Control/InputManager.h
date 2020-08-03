#pragma once
#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "../Utility/Coordinate.h"

//! �������� �������� ����������� ������.
const unsigned KeysCount = 15;
enum KeyboardKey {
	L_Left, L_Right, L_Up, L_Down, L_ShootA, L_ShootB,
	R_Left, R_Right, R_Up, R_Down, R_ShootA, R_ShootB,
	M_Play, M_Sett, M_Quit
};

const unsigned MouseKeysCount = 2;
enum MouseKey {
	Mouse_Left, Mouse_Right
};

//! ��������� ����������, WIP, ����� �� �������
const unsigned PlayerKeysCount = 6;
enum PlayerKey {
	Left, Right, Up, Down, ShootA, ShootB
};

//! ������ ���������� � ��������� ����������� �������
struct KeyData {
	bool is_pressed;
	bool is_realesed;
	bool is_down;
};

struct MouseData {
	Vector2F pos;
	KeyData l_button, r_button;
};

/*!
* ��������, ������� ������������� ������ � ���������� (� ������� � � ����) � ������������� �� ������ �������� � ����� ������� ����
* 
* ��������� ��������� ��������� ����������, ��� ��� ������ ����� ����� ��������� ��������� ���������� � ������������ ��������� (L_Left, L_Right � ��)
* � �������� �������� ����, ����� ����������������� ������ ������������ ���������.
* ���� ����� ���������� ��������� ����������, ����� �������� ������� ����� ��������������� ������ ����������� (�� �� ��������)
* 
* ������� �� SFML
* 
* ���������. ����� ������ ��� ���������� ����� ������ ����������
*/

struct InputManager
{
	//! �� �������, ������������� ���������� ��� ������������� ����
	static void Init();

	//! �� �������, ������������� ���������� ������ ���� � ������� �����
	static void Update();

	//! ����� true � ����, � ������� ����������� ������� key ����������, ����� false
	static bool IsPressed(KeyboardKey key);

	//! ����� true � ����, � ������� ����������� ������� key ����������, ����� false
	static bool IsRealesed(KeyboardKey key);

	//! ����� true ���� key ������, ����� false
	static bool IsUp(KeyboardKey key);

	//! ����� true ���� key �� ������, ����� false
	static bool IsDown(KeyboardKey key);

	//! ����� true � ����, � ������� ������� ���� key ����������, ����� false
	static bool IsPressed(MouseKey key);

	//! ����� true � ����, � ������� ����������� ������� key ����������, ����� false
	static bool IsRealesed(MouseKey key);

	//! ����� true ���� key ������, ����� false
	static bool IsUp(MouseKey key);

	//! ����� true ���� key �� ������, ����� false
	static bool IsDown(MouseKey key);

	//! ����� ���������� ������� � ������� ���� SFML
	static Vector2F GetMousePos();

private:
	static KeyData _key_info[KeysCount]; //! ������ ���������� � ���� ����������� ��������
	static MouseData _mouse_info; //! ���������� � ��������� ����
	static sf::Keyboard::Key _control_keys[KeysCount]; //! ������ ����� ����� ��������� � ������������ ���������
};
