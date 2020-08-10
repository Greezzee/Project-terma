#include "SolidEntity.h"

#include <algorithm>
#include <cmath>

#include "../../Engine/AllEngine.h"
#include "../Map.h"

const float epsilon = 1.0f;
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

	// DEBUG
	//------------------------------------------------------------------
	//Debugger::DrawSquareCollider(*collider, 10, 0, Views::PLAYER_CAM);
	//Debugger::DrawPoint(_pos, 20, Views::PLAYER_CAM);
	//------------------------------------------------------------------

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

	// X
	float problem_dist = map->testCollision(collider, dsx);
	problem_dist = std::max(0.0f, problem_dist - epsilon);
	if (problem_dist < dsx_len) {
		dsx = dsx.Normalized() * problem_dist;
	}
	_pos += dsx;

	// Y
	problem_dist = map->testCollision(collider, dsy);
	problem_dist = std::max(0.0f, problem_dist - epsilon);
	if (problem_dist < dsy_len) {
		dsy = dsy.Normalized() * problem_dist;
	}
	_pos += dsy;

	speed = (dsx + dsy) / dt;
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
	return getMap()->testCollision(collider, { 0, -10.0f }) < epsilon;
}

SolidEntity::~SolidEntity() {
	delete collider;
}

void SolidEntity::setMass(float mass) {
	this->mass = mass;
}
