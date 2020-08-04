/*
 * Damageable.cpp
 *
 *  Created on: Aug 3, 2020
 *      Author: timattt
 */

#include "Damageable.h"

Damageable::Damageable() {
	// TODO Auto-generated constructor stub

}

Damageable::~Damageable() {
	// TODO Auto-generated destructor stub
}

float Damageable::getCurrentHealth() const {
	return currentHealth;
}

void Damageable::setCurrentHealth(float currentHealth) {
	this->currentHealth = currentHealth;
}
