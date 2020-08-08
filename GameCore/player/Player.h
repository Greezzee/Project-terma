#pragma once

#include "../entities/Damageable.h"
#include "../entities/SolidEntity.h"
#include "Inventory.h"

struct DrawData;

class Inventory;

struct View;

class Player: public SolidEntity, public Damageable {
public:
	Player();
	void Draw();
	void Destroy() override;
	GameObject* clone() const;
	void Update();
	View* getCamera();
	virtual void Init(GameObject *owner);

	// INVENTORY
	Inventory *inventory;
private:
	View *camera;
	bool lookingRight;

	// DRAW
	//---------------------------
	void drawHealthBar();
	void drawPlayer();
	//---------------------------

	// LIGHT
	void correctLight(DrawData &data);
};
