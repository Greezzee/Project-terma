/*
 * Damageable.h
 *
 *  Created on: Aug 3, 2020
 *      Author: timattt
 */

#ifndef GAMECORE_ENTITIES_DAMAGEABLE_H_
#define GAMECORE_ENTITIES_DAMAGEABLE_H_

class Damageable {
public:
	Damageable() {};
	~Damageable() {};

	float getCurrentHealth() const;
	void setCurrentHealth(float currentHealth);

private:
	float currentHealth = -1;
};

#endif /* GAMECORE_ENTITIES_DAMAGEABLE_H_ */
