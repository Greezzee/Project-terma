#include "SolidEntity.h"

#include "../../Engine/Colliders/SquareCollider.h"
#include "../../Engine/Time/TimeManager.h"
#include "../../Engine/Utility/Coordinate.h"
#include "../Map.h"

void SolidEntity::Update() {
	Entity::Update();

	collider->Init(this, this->_pos, this->size * 0.5);
	acceleration = { 0, -30 };

	if (this->getMap()->testCollision(collider)) {
		speed.y = 0;
	}
}

SolidEntity::SolidEntity() {
	collider = new SquareCollider();
	collider->Init(this);
}
