/*
 * LightSource.cpp
 *
 *  Created on: Aug 6, 2020
 *      Author: timattt
 */

#include "LightSource.h"

LightSource::LightSource() {
	// TODO Auto-generated constructor stub
}

LightSource::~LightSource() {
	// TODO Auto-generated destructor stub
}

int LightSource::getLightRadius() const {
	return lightRadius;
}

void LightSource::setLightRadius(int lightRadius) {
	this->lightRadius = lightRadius;
}
