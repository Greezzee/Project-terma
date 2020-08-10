#pragma once

#include "../Engine/AllEngine.h"

// Здесь объявлены все вьюшки, их инициализация в конструкторе
class Views {

public:
	Views() {};

	// Все вьюшки перечислять здесь
	static unsigned MAIN_MENU;
	static unsigned PLAYER_CAM;

	// Вызвать, чтобы загрузить все вьюшки в GraphicManager (инициализировать внутри функции вручную!)
	static void LOAD_ALL_VIEWS();

	~Views() {}
};
