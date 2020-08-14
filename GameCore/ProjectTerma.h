#pragma once

#include "Textures.h"
#include "../Engine/AllEngine.h"
/*
 * Этот файл является основным для текущего игрового проекта
 * 
 * 	Теперь это СЦЕНА, которая запускается первой. Запуск смотреть в Main.cpp
 */

// Current resolution
const Vector2F resolution = {1920, 1080};

class ProjectTerma: public Scene {

	void Init();

	void Update();

	void Destroy();

};
