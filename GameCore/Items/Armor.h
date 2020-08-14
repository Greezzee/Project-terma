#pragma once

#include "Equippable.h"

enum ArmorType {
	NONE, HELMET, CHESTPLATE, PANTS
};

class Armor: public Equippable {
protected:
	enum ArmorType type;
public:
	Armor();

	virtual void Draw() = 0;
	virtual void Destroy() = 0;
	virtual void Init(GameObject *owner) = 0;
	virtual void Update() = 0;
	virtual GameObject* Clone() const = 0;

	virtual ~Armor();
};
