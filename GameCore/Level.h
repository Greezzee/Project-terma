#pragma once

#include <stdio.h>

class Map;

//! Этот класс будет подгружать и содержать в себе всю информацию о текущем уровне игры
class Level {
public:
	virtual void generate(Map * map) = 0;

protected:
	void loadBlocksFromFile(Map * map, FILE * from);
};
