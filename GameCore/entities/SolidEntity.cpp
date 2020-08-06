#include "SolidEntity.h"

#include "../../Engine/Colliders/SquareCollider.h"
#include "../../Engine/Time/TimeManager.h"
#include "../../Engine/Utility/Coordinate.h"
#include "../Map.h"
#include "../Debugger.h"

void SolidEntity::Update() {
	Entity::Update();

	// UPDATE COLLIDER
	collider->Init(this->_pos, this->size.x * 0.5);
	Debugger::DrawCollider(*collider, Views::PLAYER_CAM);
	Debugger::DrawPoint(_pos, 20, Views::PLAYER_CAM);

	// SET ACCELERATION TO g
	acceleration += { 0, -5000 };

	// STOP OBJECT IF IT IS FALLING IN TO THE GROUND
	if (this->isInBlocks = this->getMap()->testCollision(collider)) {
		speed.y = 0;
	}
}

SolidEntity::SolidEntity() {
	collider = new CircleCollider();
	collider->Init();
	this->isInBlocks = 0;
}
