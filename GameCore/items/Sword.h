#pragma once

#include "Item.h"

class Sword: public Item {
public:
	Sword() {}

	void Draw() override;
	void Destroy() override;
	void Init(GameObject *owner) override;
	void Update() override;

	~Sword() {}
};
