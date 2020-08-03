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
	Damageable();
	virtual ~Damageable();
	float getCurrentHealth() const;
	void setCurrentHealth(float currentHealth);

private:
	float currentHealth;
};

#endif /* GAMECORE_ENTITIES_DAMAGEABLE_H_ */
