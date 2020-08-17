/*
 * LightSource.cpp
 *
 *  Created on: Aug 6, 2020
 *      Author: timattt
 */

#include "LightSource.h"

LightSource::LightSource() {
}

LightSource::~LightSource() {
}

int LightSource::getLightRadius() const {
	return lightRadius;
}

void LightSource::setLightRadius(int lightRadius) {
	this->lightRadius = lightRadius;
}

int LightSource::getCurrentLightSourceId() const {
	return currentLightSourceId;
}

void LightSource::setCurrentLightSourceId(int currentLightSourceId) {
	this->currentLightSourceId = currentLightSourceId;
}
