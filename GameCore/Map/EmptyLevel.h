/*
 * EmptyLevel.h
 *
 *  Created on: Aug 12, 2020
 *      Author: timattt
 */

#ifndef GAMECORE_MAP_EMPTYLEVEL_H_
#define GAMECORE_MAP_EMPTYLEVEL_H_

#include "Level.h"

class EmptyLevel: public Level {
public:
	EmptyLevel();
	~EmptyLevel();
	void generate(Map *map) override;
};

#endif /* GAMECORE_MAP_EMPTYLEVEL_H_ */
