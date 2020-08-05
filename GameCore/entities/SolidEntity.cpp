#include "SolidEntity.h"

#include "../../Engine/Colliders/SquareCollider.h"
#include "../../Engine/Time/TimeManager.h"
#include "../../Engine/Utility/Coordinate.h"
#include "../Map.h"
#include "../Debugger.h"

void SolidEntity::Update() {
	Entity::Update();

	// UPDATE COLLIDER
	collider->Init(this, this->_pos, this->size * 0.5);
	Debugger::DrawSquareCollider(*collider, 10, 0, Views::PLAYER_CAM);

	// SET ACCELERATION TO g
	acceleration += { 0, -5000 };

	// STOP OBJECT IF IT IS FALLING IN TO THE GROUND
	if (this->isInBlocks = this->getMap()->testCollision(collider)) {
		speed.y = 0;
	}
}

SolidEntity::SolidEntity() {
	collider = new SquareCollider();
	collider->Init(this);
	this->isInBlocks = 0;
}
