#pragma once

#include "../Engine/AllEngine.h"

//! Class Views. Usage:
//! 1) Add static unsigned variable in calss declaration
//! 2) Define it in Views.cpp
//! 3) Load it in Views::LOAD_ALL_VIEWS()

class Views {

public:
	Views() {};

	static unsigned MAIN_MENU;
	static unsigned PLAYER_CAM;

	static void LOAD_ALL_VIEWS();

	~Views() {}
};