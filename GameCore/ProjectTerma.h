#pragma once

#include "Textures.h"
#include "../Engine/AllEngine.h"
/*
 * Этот файл является основным для текущего игрового проекта
 * 
 * 	Теперь это СЦЕНА, которая запускается первой. Запуск смотреть в Main.cpp
 */

// Current_resolution
const Vector2F cur_resolution = {1024, 576};

class ProjectTerma: public Scene {

	void Init();

	void Update();

	void Destroy();

};
