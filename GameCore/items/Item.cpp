#include "Item.h"

void Item::Draw()
{
	// TODO Draw the item on the player
}

Item::Item()
{
	icon_id = -1;
	size = {0 ,0};
}

void Item::setIconID(unsigned _id)
{
	icon_id = _id;
}

unsigned Item::getIconID()
{
	return icon_id;
}

void Item::setSize(Vector2F _size)
{
	size = _size;
}

Vector2F Item::getSize()
{
	return size;
}

GameObject* Item::clone() const
{
	return nullptr;
}

Item::~Item() {}
