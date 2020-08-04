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

	//! Выпускает из центра коллайдера a вектор в направлении direction
	//! Определяет, сколько должен пройти коллайдер a в направлении данного вектора, чтобы столкнуться в b
	//! Вернёт искомое расстояние в тех же единицах, в которых заданы коллайдеры
	//! Вернёт NAN, если при движении в данном направлении, a никогда не встретит b
	static float DistanceBetween(SquareCollider* a, SquareCollider* b, Vector2F direction);
};