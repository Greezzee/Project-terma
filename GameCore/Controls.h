#pragma once

#include "../Engine/AllEngine.h"

// Класс для управления и загрузки клави управления
class Controls {
public:
	Controls() {}

	// Здесь перечислять все используемые клавиши в игре
	enum GameKeys {
		RIGHT, LEFT, JUMP, OPEN_INV, BACK
	};
	// Загрузить все клавиши (каждую инициализировать внутри функции вручную!)
	static void LOAD_ALL_GAMEKEYS();

	~Controls() {}
};
