#pragma once
#include "../Engine/Gameplay/GameField.h"

/*
 * Сей класс наследуется от GameField, тут будет вся инфа о текущих объектах в игре
 */
class Map : public GameField {
	void Init();
	void Update();
	void Destroy();
};
