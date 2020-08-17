#pragma once

#include "../Engine/AllEngine.h"

//  олличество игровых клавиш
const unsigned keys_number = 6;

//  ласс дл€ управлени€ и загрузки клави управлени€
class Controls {
public:
	Controls() {}

	// «десь перечисл€ть все используемые клавиши в игре
	enum GameKeys {
		RIGHT, LEFT, UP, DOWN, OPEN_INV, BACK
	};
	// ћассив, где индекс - GAMEKEYS, а значение - ENGINE VIRTUAL KEY
	static KeyboardKey linking[keys_number];

	// «агрузить все клавиши (после загрузки всех кнопок в массив linking)
	static void LOAD_ALL_GAMEKEYS();

	~Controls() {}

	friend class Settings;
};
