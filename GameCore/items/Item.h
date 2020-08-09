#pragma once

#include "../../Engine/Gameplay/GameObject.h"

enum itemType {
	MELEE_WEAPON, ARMOR
};

class Item : public GameObject {
protected:
	// True if this item is equipped
	bool is_equipped;
	// Item type
	itemType type;
	// Inventory icon sprite ID
	unsigned icon_id;
	// Size of the object
	Vector2F size;
public:
	Item();

	void setIconID(unsigned _id);
	unsigned getIconID();
	void setSize(Vector2F _size);
	Vector2F getSize();

	void equip();
	void unequip();
	bool isEquipped();

	virtual void Draw() = 0;
	virtual void Destroy() = 0;
	virtual void Init(GameObject *owner) = 0;
	virtual void Update() = 0;
	virtual GameObject* clone() const;


	virtual ~Item();
};
