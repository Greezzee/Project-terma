#include "../Colliders/EllipseCollider.h"
#include <cmath>

const float PI = 3.1415926f;

const unsigned EllipseCollider::COLLIDE_ITERATIONS = 16;

void EllipseCollider::Init()
{
	_my_obj = nullptr;
	_pos = _size = { 0, 0 };
	_angle = 0;
}

void EllipseCollider::Init(GameObject* owner)
{
	_my_obj = owner;
	_pos = _size = { 0, 0 };
	_angle = 0;
}

void EllipseCollider::Init(Vector2F pos, float angle, Vector2F size, GameObject* owner)
{
	_my_obj = owner;
	_pos = pos;
	_size = size;
	_angle = angle;
}