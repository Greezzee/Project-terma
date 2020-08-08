/*
 * Damageable.cpp
 *
 *  Created on: Aug 3, 2020
 *      Author: timattt
 */

#include "Damageable.h"

float Damageable::getCurrentHealth() const {
	return currentHealth;
}

void Damageable::setCurrentHealth(float currentHealth) {
	this->currentHealth = currentHealth;
}
