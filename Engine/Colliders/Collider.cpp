#include "Collider.h"

#include <cmath>

#include "../Utility/Coordinate.h"
#include "../Utility/Line.h"

float sqr(float x) {
	return x * x;
}

bool Collider::IsCollide(EllipseCollider* a, EllipseCollider* b) {

	float myR = fmaxf(a->_size.x, a->_size.y);
	float thatR = fmaxf(b->_size.x, b->_size.y);

	if (myR * thatR == 0)
		return false;

	float my_angle = a->_angle;// +a->_my_obj->_angle;
	Vector2F my_pos = a->_pos;// +a->_my_obj->_pos;

	float that_angle = b->_angle;// +b->_my_obj->_angle;
	Vector2F that_pos = b->_pos;// +b->_my_obj->_pos;

	Vector2F dif = my_pos - that_pos;

	if (dif.SqrMagnitude() > sqr(myR + thatR))
		return false;

	Vector2F posA, posB, sizeA, sizeB; //A - наибольший, B - наименьший
	float angleA, angleB;

	if (a->_size.x * a->_size.y > b->_size.x * b->_size.y) {
		posA = my_pos;
		posB = that_pos;
		sizeA = a->_size;
		sizeB = b->_size;
		angleA = my_angle;
		angleB = that_angle;
	}
	else {
		posB = my_pos;
		posA = that_pos;
		sizeB = a->_size;
		sizeA = b->_size;
		angleB = my_angle;
		angleA = that_angle;
	}

	//перемещаем центр и угол к B
	angleA -= angleB;
	angleB = 0;
	posA -= posB;
	posB = { 0, 0 };

	//***************************

	Vector2F p1 = posA + Vector2F(cosf(angleA), sinf(angleA)) * sizeA.x;
	Vector2F p2 = posA + Vector2F(-sinf(angleA), cosf(angleA)) * sizeA.y;
	p1 = { p1.x / sizeB.x, p1.y / sizeB.y };
	p2 = { p2.x / sizeB.x, p2.y / sizeB.y };
	posA = { posA.x / sizeB.x, posA.y / sizeB.y };
	p1 -= posA;
	p2 -= posA;


	//Масштабируем так, чтобы B стал единичным кругом

	sizeA = { p1.SqrMagnitude(), p2.SqrMagnitude() }; //Кладём КВАДРАТЫ длин полуосей
	sizeB = { 1, 1 };
	//***********************************************

	//Переводим центр и угол к А
	angleB -= angleA;
	angleA = 0;

	posB -= posA;
	posA = { 0, 0 };

	posB = { posB.x * cosf(angleB) + posB.y * sinf(angleB),
			-posB.x * sinf(angleB) + posB.y * cosf(angleB) };
	//***************************
	float angle_part = 2 * PI / (float)EllipseCollider::COLLIDE_ITERATIONS;
	for (unsigned i = 0; i < EllipseCollider::COLLIDE_ITERATIONS; i++) {
		float x = posB.x + cosf(angle_part * i);
		float y = posB.y + sinf(angle_part * i);

		if (sqr(x) * sizeA.y + sqr(y) * sizeA.x <= sizeA.x * sizeA.y)
			return true;
	}
	if (sqr(posB.x) * sizeA.y + sqr(posB.y) * sizeA.x <= sizeA.x * sizeA.y)
		return true;

	return false;
}

//! Проверяет, пересекаются ли 2 данных коллайдера
bool Collider::IsCollide(SquareCollider* a, SquareCollider* b)
{
	float sqrdist = Vector2F(a->_pos - b->_pos).SqrMagnitude();
	float rad = a->_size.Magnitude() + b->_size.Magnitude();

	if (sqrdist > rad * rad)
		return false;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			if (Intersect(a->_points[i], a->_points[(i + 1) % 4], b->_points[j], b->_points[(j + 1) % 4]))
				return true;
		}

	return false;
}

float Collider::DistanceBetween(SquareCollider* a, SquareCollider* b, Vector2F direction)
{
	direction = direction.Normalized();
	float dir_angle = atan2f(direction.y, direction.x);
	Vector2F pos_a = { 0, 0 };
	Vector2F pos_b = b->getPos() - a->getPos();
	Vector2F points_b[4];
	float max_dist = 0;
	for (int i = 0; i < 4; i++) {
		points_b[i] = b->_points[i] - a->getPos();
		float dist = points_b[i].x * cosf(dir_angle) + points_b[i].y * sinf(dir_angle);
		if (fabsf(dist) > fabsf(max_dist))
			max_dist = dist;
	}

	if (max_dist > 0)
		max_dist += a->getSize().Magnitude();
	else
		max_dist -= a->getSize().Magnitude();

	Vector2F point_a = a->getPos();
	Vector2F point_b = point_a + direction * max_dist;
	return 0;
}