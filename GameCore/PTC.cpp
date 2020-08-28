/*
 * PTC.cpp
 *
 *  Created on: Aug 28, 2020
 *      Author: timattt
 */

#include "PTC.h"
#include <chrono>
#include <ctime>
#include <iostream>

PTCMP PTC::CURRENT_PRIORITY = medium;
bool PTC::SAY_DEBUG = true;

PTC::PTC() {
}

PTC::~PTC() {
}

void PTC::say(std::string mes, PTCMT type, PTCMP prior) {
	if (prior < CURRENT_PRIORITY || (!SAY_DEBUG && type == debug)) {
		return;
	}

	time_t now = time(0);
	tm *ltm = localtime(&now);

	if (type == error) {
		std::cerr << "[" << ltm->tm_hour << ":" << ltm->tm_min << ":"
				<< ltm->tm_sec << "] ";
		std::cerr << mes << "\n";
	} else {
		std::cout << "[" << ltm->tm_hour << ":" << ltm->tm_min << ":"
				<< ltm->tm_sec << "] ";
		std::cout << mes << "\n";
	}
}

void PTC::shutUpDebug() {
	SAY_DEBUG = false;
}
