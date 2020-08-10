#pragma once

#include "../Engine/AllEngine.h"

// ����� ��� ���������� � �������� ����� ����������
class Controls {
public:
	Controls() {}

	// ����� ����������� ��� ������������ ������� � ����
	enum GameKeys {
		RIGHT, LEFT, JUMP, OPEN_INV, BACK
	};
	// ��������� ��� ������� (������ ���������������� ������ ������� �������!)
	static void LOAD_ALL_GAMEKEYS();

	~Controls() {}
};
