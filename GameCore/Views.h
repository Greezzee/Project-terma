#pragma once

#include "../Engine/AllEngine.h"

// ����� ��������� ��� ������, �� ������������� � ������������
class Views {

public:
	Views() {};

	// ��� ������ ����������� �����
	static unsigned MAIN_MENU;
	static unsigned PLAYER_CAM;

	// �������, ����� ��������� ��� ������ � GraphicManager (���������������� ������ ������� �������!)
	static void LOAD_ALL_VIEWS();

	~Views() {}
};
