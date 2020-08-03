#pragma once

#include "../entities/SolidEntity.h"
#include "Inventory.h"

class Inventory;

struct View;

class Player : public SolidEntity {
public:
	Player();
	void Draw();
	GameObject* clone() const;
	void Update();
	View* getCamera();
	virtual void Init(GameObject *owner);

private:
	View* camera;
	bool lookingRight;
	Inventory inventory;
};
