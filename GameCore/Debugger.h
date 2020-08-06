#pragma once
#include "../Engine/Utility/Coordinate.h"
#include "../Engine/Graphics/GraphicManager.h"
#include "../Engine/Colliders/Collider.h"
#include <vector>
class Debugger
{
public:
	//! –исует белую квадратную точку с центром в pos, длина стороны size
	static bool DrawPoint(Vector2F pos, float size, Views view_id = Views::BASIC, Color color = Color::White(), unsigned layer = 10);

	//! –исует белую линию между точками start и end, толщина линии thick
	static bool DrawLine(Vector2F start, Vector2F end, float thick, Views view_id = Views::BASIC, Color color = Color::White(), unsigned layer = 10);

	//! –исует квадратный коллайдер с размером угловых точек points_size и толщиной соедин€ющих их линий line_thick
	static bool DrawCollider(const SquareCollider& col, float points_size, float line_thick, Views view_id = Views::BASIC, Color color = Color::White(), unsigned layer = 10);

	//! –исует круглый коллайдер
	static bool DrawCollider(const CircleCollider& col, Views view_id = Views::BASIC, Color color = Color::White(), unsigned layer = 10);

	//! –исует многоугольник с вершинами в points
	static bool DrawRect(const std::vector<Vector2F>& points, float points_size, float line_thick, Views view_id = Views::BASIC, Color color = Color::White(), unsigned layer = 10);
};

