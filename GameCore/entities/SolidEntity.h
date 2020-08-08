#pragma once

#include "Entity.h"

class SquareCollider;

//! Sey klass obrabativaet vse suschnosty, kotorye podverscheny gravitacii i ne moschet provodit cherez bloki
//! Neobhodimo vyzivat funkciu Update VO VSEH DOCHERNIH KLASSAH vo vremya obnovleniya.
class SolidEntity : public Entity {
public:

	// CONSTRUCTOR AND DESTRUCTOR
	//----------------------------------
	SolidEntity();
	~SolidEntity();
	//----------------------------------

	// BASE
	//----------------------------------
	void Update();
	//----------------------------------

	// GETTERS AND SETTERS
	//----------------------------------
	bool standsOnTheGround();
	void setMass(float mass = 1);
	//----------------------------------

protected:
	SquareCollider * collider;
	float mass = 1;
};
