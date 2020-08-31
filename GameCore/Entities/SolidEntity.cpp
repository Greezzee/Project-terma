#include "SolidEntity.h"

#include <algorithm>
#include <cmath>

#include "../../Engine/Colliders/SquareCollider.h"
#include "../../Engine/Time/TimeManager.h"
#include "../../Engine/Utility/Coordinate.h"
#include "../Map/Map.h"

const float epsilon = 0.1f;
const float k = 4.0f;
const float g = 5000;
//!
//! m * a = externalForce - V * K + g * m;
//! dV = a * dt;
//! dS = V * dt;
//!
//! V * K	will be counted ONLY IF ENTITY IS TOUCHING THE GROUND (standsOnTheGround() == true)
//!
//! Where: V - speed, a - acceleration, dt - small time
void SolidEntity::Update() {
	// UPDATE COLLIDER
	collider->Init(this->_pos, this->collider_size * 0.5);

	// ADDING OTHER FORCES
	//------------------------------------------------------------------
	// SET ACCELERATION TO g
	externalForce += Vector2F(0, -g) * mass;

	// SOPROTIVLENIYE
	externalForce.x -= speed.x * k;
	//------------------------------------------------------------------

	// Now we can calculate acceleration
	Vector2F acceleration = externalForce / mass;

	// POSITION UPDATE
	//------------------------------------------------------------------
	float dt = TimeManager::GetDeltaTimeF();

	speed += acceleration * dt;
	Vector2F ds = speed * dt;

	Vector2F dsx = { ds.x, 0 };
	Vector2F dsy = { 0, ds.y };

	float dsx_len = dsx.Magnitude();
	float dsy_len = dsy.Magnitude();

	// MAP
	Map *map = getMap();
	/*
	float posible_dist = map->testCollision(collider, ds);
	posible_dist = std::max(posible_dist - epsilon, 0.0f);
	if (posible_dist < ds.Magnitude()) {
		ds = ds.Normalized() * posible_dist;
	}
	speed = ds / dt;
	_pos += ds;
	*/

	// X
	float posible_dist = map->testCollision(collider, dsx);
	posible_dist = std::max(0.0f, posible_dist - epsilon);
	if (posible_dist < dsx_len) {
		dsx = dsx.Normalized() * posible_dist;
		//speed.x = 0;
	}
	_pos += dsx;
	collider->Init(this->_pos, this->collider_size * 0.5);

	// Y
	posible_dist = map->testCollision(collider, dsy);
	posible_dist = std::max(0.0f, posible_dist - epsilon);
	if (posible_dist < dsy_len) {
		dsy = dsy.Normalized() * posible_dist;
		//speed.y = 0;
	}
	_pos += dsy;

	speed = (dsx + dsy) / dt;
	collider->Init(this->_pos, this->collider_size * 0.5);

	//------------------------------------------------------------------

	// FLUSH
	//------------------------------------------------------------------
	if (std::abs(speed.x) < epsilon) {
		speed.x = 0;
	}
	if (std::abs(speed.y) < epsilon) {
		speed.y = 0;
	}
	externalForce = { 0, 0 };
	//------------------------------------------------------------------
}

SolidEntity::SolidEntity() {
	collider = new SquareCollider();
	collider->Init();
}

bool SolidEntity::standsOnTheGround() {
	return getMap()->testCollision(collider, { 0, -epsilon * 2 }, 0) < epsilon * 2;
}

SolidEntity::~SolidEntity() {
	delete collider;
}

void SolidEntity::setMass(float mass) {
	this->mass = mass;
}

const SquareCollider* SolidEntity::getCollider() const {
	return collider;
}
