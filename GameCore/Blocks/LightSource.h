/*
 * LightSource.h
 *
 *  Created on: Aug 6, 2020
 *      Author: timattt
 */

#ifndef GAMECORE_BLOCKS_LIGHTSOURCE_H_
#define GAMECORE_BLOCKS_LIGHTSOURCE_H_
class Map;

class LightSource {
public:
	LightSource();
	virtual ~LightSource();
	int getLightRadius() const;
	void setLightRadius(int lightRadius);
	int getCurrentLightSourceId() const;
	void setCurrentLightSourceId(int currentLightSourceId = -1);

protected:
	int lightRadius = 0;
	int currentLightSourceId = -1;
};

#endif /* GAMECORE_BLOCKS_LIGHTSOURCE_H_ */
