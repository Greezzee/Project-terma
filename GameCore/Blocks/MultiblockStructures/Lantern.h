/*
 * Lantern.h
 *
 *  Created on: Aug 6, 2020
 *      Author: timattt
 */

#ifndef GAMECORE_BLOCKS_LANTERN_H_
#define GAMECORE_BLOCKS_LANTERN_H_
#include "../../../Engine/AllEngine.h"
#include "../../Textures.h"
#include "../LightSource.h"
#include "../MultiblockStructures/Multiblock.h"

class Lantern: public Multiblock, public LightSource {
public:
	Lantern() :
			Multiblock(), LightSource() {
		setSize( { 3, 6 });
		setID(33);
		setSpriteId(Textures::LANTERN);
		setPassable(1);
		setLightRadius(100);
	}

	void Update() override
	{
		LightData data = {};
		data.pos = _pos;
		data.color = Color(255, 255, 255);
		data.full_dist = getLightRadius();
		data.any_dist = 500;
		data.softness = 1;
		LightManager::AddLightSource(data);
	}

	GameObject* Clone() const {
		return new Lantern();
	}
};

#endif /* GAMECORE_BLOCKS_LANTERN_H_ */
