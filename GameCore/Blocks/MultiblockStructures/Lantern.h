/*
 * Lantern.h
 *
 *  Created on: Aug 6, 2020
 *      Author: timattt
 */

#ifndef GAMECORE_BLOCKS_LANTERN_H_
#define GAMECORE_BLOCKS_LANTERN_H_

#include "../../../Engine/Utility/Coordinate.h"
#include "../../Map/Map.h"
#include "../../Textures.h"
#include "../LightSource.h"
#include "Multiblock.h"

const unsigned LANTERTN_LIGHT_RADIUS = 8;

class Lantern: public Multiblock, public LightSource {
public:
	Lantern() :
			Multiblock(), LightSource() {
		setSize( { 3, 6 });
		setID(334);
		setSpriteId(Textures::LANTERN);
		setPassable(1);
		setLightRadius(LANTERTN_LIGHT_RADIUS);
	}

	void code(char *&buffer) override {

	}
	void decode(char *&buffer) override {

	}

	GameObject* Clone() const {
		return new Lantern();
	}
};

#endif /* GAMECORE_BLOCKS_LANTERN_H_ */
