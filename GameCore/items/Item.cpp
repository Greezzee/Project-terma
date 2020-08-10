#include "Item.h"

void Item::Draw()
{
	// TODO Draw the item on the player
}

Item::Item()
{
	type = MELEE_WEAPON;
	icon_id = -1;
	size = {0 ,0};
	is_equipped = false;
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

GameObject* Item::Clone() const
{
	return nullptr;
}

void Item::equip()
{
	is_equipped = true;
}

void Item::unequip()
{
	is_equipped = false;
}

Item::~Item() {
}

bool Item::isEquipped()
{
	return is_equipped;
}
