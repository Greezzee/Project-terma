#pragma once

#include "Textures.h"
#include "Settings.h"
#include "../Engine/AllEngine.h"
/*
 * ���� ���� �������� �������� ��� �������� �������� �������
 * 
 * 	������ ��� �����, ������� ����������� ������. ������ �������� � Main.cpp
 */

class SorterLab: public Scene {

	void Init();

	void Update();

	void Destroy();

public:

	static void report_error(std::string mes);

};
