#pragma once
#include "../Engine/SceneManagment/Scene.h"
/*
 * Этот файл является основным для текущего игрового проекта
 * 
 * 	Теперь это СЦЕНА, которая запускается первой. Запуск смотреть в Main.cpp
 */

class ProjectTerma :
	public Scene{

	void Init();

	void Update();

	void Destroy();

};
