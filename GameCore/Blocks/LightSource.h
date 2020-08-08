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

protected:
	int lightRadius = 0;
};

#endif /* GAMECORE_BLOCKS_LIGHTSOURCE_H_ */
