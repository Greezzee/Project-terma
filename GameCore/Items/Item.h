#pragma once

#include "../../Engine/AllEngine.h"

class Item : public GameObject {
protected:
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

	virtual void Draw() = 0;
	virtual void Destroy() = 0;
	virtual void Init(GameObject *owner) = 0;
	virtual void Update() = 0;
	virtual GameObject* Clone() const = 0;

	virtual ~Item();
};
