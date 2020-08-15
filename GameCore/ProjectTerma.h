#pragma once

#include "Textures.h"
#include "../Engine/AllEngine.h"
/*
 * ���� ���� �������� �������� ��� �������� �������� �������
 * 
 * 	������ ��� �����, ������� ����������� ������. ������ �������� � Main.cpp
 */

// Current resolution
const Vector2F resolution = {1024, 576};

class ProjectTerma: public Scene {

	void Init();

	void Update();

	void Destroy();

};
