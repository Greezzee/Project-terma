#include "Equippable.h"

Equippable::Equippable()
{
	is_equipped = false;
}

void Equippable::equip()
{
	is_equipped = true;
}

void Equippable::unequip()
{
	is_equipped = false;
}

bool Equippable::isEquipped()
{
	return is_equipped;
}

Equippable::~Equippable() {}
