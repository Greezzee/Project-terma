#pragma once

#include "../Engine/AllEngine.h"

// ����������� ������� ������
const unsigned keys_number = 6;

// ����� ��� ���������� � �������� ����� ����������
class Controls {
public:
	Controls() {}

	// ����� ����������� ��� ������������ ������� � ����
	enum GameKeys {
		RIGHT, LEFT, UP, DOWN, OPEN_INV, BACK
	};
	// ������, ��� ������ - GAMEKEYS, � �������� - ENGINE VIRTUAL KEY
	static KeyboardKey linking[keys_number];

	// ��������� ��� ������� (����� �������� ���� ������ � ������ linking)
	static void LOAD_ALL_GAMEKEYS();

	~Controls() {}

	friend class Settings;
};
