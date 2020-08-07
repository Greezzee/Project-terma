#pragma once
#include "../Engine/Utility/Coordinate.h"
#include "../Engine/Graphics/GraphicManager.h"
#include "../Engine/Colliders/SquareCollider.h"
class Debugger
{
public:
	//! ������ ����� ���������� ����� � ������� � pos, ����� ������� size
	static bool DrawPoint(Vector2F pos, float size, Views view_id = Views::BASIC, Color color = Color::White(), unsigned layer = 10);

	//! ������ ����� ����� ����� ������� start � end, ������� ����� thick
	static bool DrawLine(Vector2F start, Vector2F end, float thick, Views view_id = Views::BASIC, Color color = Color::White(), unsigned layer = 10);

	//! ������ ���������� ��������� � �������� ������� ����� points_size � �������� ����������� �� ����� line_thick
	static bool DrawSquareCollider(const SquareCollider& col, float points_size, float line_thick, Views view_id = Views::BASIC, unsigned layer = 10);
};

