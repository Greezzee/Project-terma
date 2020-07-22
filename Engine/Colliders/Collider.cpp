#include "../Colliders/Collider.h"
#include <cmath>

const float PI = 3.1415926f;
float sqr(float x) {
	return x * x;
}

void Collider::Init()
{
	_my_obj = nullptr;
	_pos = _size = { 0, 0 };
	_angle = 0;
}

void Collider::Init(GameObject* owner)
{
	_my_obj = owner;
	_pos = _size = { 0, 0 };
	_angle = 0;
}

void Collider::Init(Vector2F pos, float angle, Vector2F size, GameObject* owner)
{
	_my_obj = owner;
	_pos = pos;
	_size = size;
	_angle = angle;
}

bool Collider::IsCollideWith(Collider* that) {

	float myR = fmaxf(_size.x, _size.y);
	float thatR = fmaxf(that->_size.x, that->_size.y);

	if (myR * thatR == 0)
		return false;

	float my_angle = _angle + _my_obj->_angle;
	Vector2F my_pos = _pos + _my_obj->_pos;

	float that_angle = that->_angle + that->_my_obj->_angle;
	Vector2F that_pos = that->_pos + that->_my_obj->_pos;

	Vector2F dif = my_pos - that_pos;

	if (dif.SqrMagnitude() > sqr(myR + thatR))
		return false;

	Vector2F posA, posB, sizeA, sizeB; //A - наибольший, B - наименьший
	float angleA, angleB;

	if (_size.x * _size.y > that->_size.x * that->_size.y) {
		posA = my_pos;
		posB = that_pos;
		sizeA = _size;
		sizeB = that->_size;
		angleA = my_angle;
		angleB = that_angle;
	}
	else {
		posB = my_pos;
		posA = that_pos;
		sizeB = _size;
		sizeA = that->_size;
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
	posA = {0, 0};

	posB = { posB.x * cosf(angleB) + posB.y * sinf(angleB),
			-posB.x * sinf(angleB) + posB.y * cosf(angleB) };
	//***************************
	float angle_part = 2 * PI / (float)COLLIDE_ITERATIONS;
	for (unsigned i = 0; i < COLLIDE_ITERATIONS; i++) {
		float x = posB.x + cosf(angle_part * i);
		float y = posB.y + sinf(angle_part * i);

		if (sqr(x) * sizeA.y + sqr(y) * sizeA.x <= sizeA.x * sizeA.y)
			return true;
	}
	if (sqr(posB.x) * sizeA.y + sqr(posB.y) * sizeA.x <= sizeA.x * sizeA.y)
		return true;

	return false;
}