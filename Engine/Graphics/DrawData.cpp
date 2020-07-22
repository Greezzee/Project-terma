#pragma once
#include "DrawData.h"

DrawData::DrawData() :
	spriteID(0), position({ 0, 0 }), layer(0), rotation(0) {}
DrawData::DrawData(unsigned id, unsigned lr, Vector2F& pos) :
	spriteID(id), position(pos), layer(lr), rotation(0) {}
DrawData::DrawData(unsigned id, unsigned lr, float x, float y) :
	spriteID(id), position({ x, y }), layer(lr), rotation(0) {}

DrawData::DrawData(unsigned id, unsigned lr, Vector2F& pos, float rot) :
	spriteID(id), position(pos), layer(lr), rotation(rot) {}
DrawData::DrawData(unsigned id, unsigned lr, float x, float y, float rot) :
	spriteID(id), position({ x, y }), layer(lr), rotation(rot) {}
