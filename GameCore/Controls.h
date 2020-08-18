#pragma once

#include "../Engine/AllEngine.h"

// Колличество игровых клавиш
const unsigned keys_number = 6;

// Класс для управления и загрузки клави управления
class Controls {
public:
	Controls() {}

	// Здесь перечислять все используемые клавиши в игре
	enum GameKeys {
		RIGHT, LEFT, UP, DOWN, OPEN_INV, BACK
	};
	// Массив, где индекс - GAMEKEYS, а значение - ENGINE VIRTUAL KEY
	static KeyboardKey linking[keys_number];

	// Названия всех виртуальных кнопок (для файла с настройками)
	static std::string tags[keys_number];

	// Загрузить все клавиши (после загрузки всех кнопок в массив linking)
	static void LOAD_ALL_GAMEKEYS();

	~Controls() {}

	friend class Settings;
};
