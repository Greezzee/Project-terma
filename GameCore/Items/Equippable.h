#pragma once

#include "Item.h"

class Equippable: public Item {
protected:
	// True if this item is equipped
	bool is_equipped;
public:
	Equippable();

	void equip();
	void unequip();
	bool isEquipped();

	virtual void Draw() = 0;
	virtual void Destroy() = 0;
	virtual void Init(GameObject *owner) = 0;
	virtual void Update() = 0;
	virtual GameObject* Clone() const = 0;

	virtual ~Equippable();
};
