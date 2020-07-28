#pragma once
#include "EllipseCollider.h"
#include "SquareCollider.h"


class Collider
{
public:
	/*!
	* Получает указатели на 2 эллиптических коллайдера
	* Вернёт false, если данные эллипсы не пересекаются
	* Вернёт true, еслии пересекаются
	*
	* Функция НЕ 100% ТОЧНАЯ, использует приближения. Степени точности определяет COLLIDE_ITERATIONS
	*/
	static bool IsCollide(EllipseCollider* a, EllipseCollider* b);

	//! Проверяет, пересекаются ли 2 данных коллайдера
	static bool IsCollide(SquareCollider* a, SquareCollider* b);
};