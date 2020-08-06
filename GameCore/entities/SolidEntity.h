#pragma once

#include "Entity.h"

class SquareCollider;

//! Sey klass obrabativaet vse suschnosty, kotorye podverscheny gravitacii i ne moschet provodit cherez bloki
//! Neobhodimo vyzivat funkciu Update VO VSEH DOCHERNIH KLASSAH vo vremya obnovleniya.
class SolidEntity : public Entity {
public:
	void Update();
	SolidEntity();
	bool standsOnTheGround();

protected:
	SquareCollider * collider;
};
