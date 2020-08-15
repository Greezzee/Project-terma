#pragma once

#include "../Engine/AllEngine.h"

// ����� ��� ���������� � �������� ����� ����������
class Controls {
public:
	Controls() {}

	// ����� ����������� ��� ������������ ������� � ����
	enum GameKeys {
		RIGHT, LEFT, UP, DOWN, OPEN_INV, BACK
	};
	// ��������� ��� ������� (������ ���������������� ������ ������� �������!)
	static void LOAD_ALL_GAMEKEYS();

	~Controls() {}
};
