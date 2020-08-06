#include "Debugger.h"

#include "../Engine/Graphics/DrawData.h"
#include "Textures.h"
#include <math.h>

bool Debugger::DrawPoint(Vector2F pos, float size, Views view_id, Color color, unsigned layer)
{
	DrawData point;
	point.origin = { 0.5, 0.5 };
	point.spriteID = Textures::WHITE_BLOCK;
	point.size = { size, size };
	point.position = pos;
	point.layer = layer;
	point.rotation = 0;
	point.frame = 0;
	point.color = color;
	return GraphicManager::Draw(point, view_id);
}
bool Debugger::DrawLine(Vector2F start, Vector2F end, float thick, Views view_id, Color color, unsigned layer)
{
	DrawData line;
	line.spriteID = Textures::WHITE_BLOCK;
	line.origin = { 0.5, 0.5 };
	line.size = { 4, Vector2F(start - end).Magnitude() };
	line.position = (start + end) / 2;
	line.layer = 10;
	line.frame = 0;
	line.rotation = atan2f(end.x - start.x, end.y - start.y) / 3.1415926 * 180;
	Vector2F unit = GraphicManager::GetView(view_id)->unit_vector;
	line.rotation = unit.y * unit.x * line.rotation;
	line.color = color;
	return GraphicManager::Draw(line, view_id);
}

bool Debugger::DrawSquareCollider(const SquareCollider& col, float points_size, float line_thick, Views view_id, Color color, unsigned layer)
{
	for (int i = 0; i < 4; i++) {
		if (!DrawPoint(col.getPoint(i), points_size, view_id, color, layer))
			return false;
		if (!DrawLine(col.getPoint(i), col.getPoint((i + 1) % 4), line_thick, view_id, color, layer))
			return false;
	}
	return true;
}
