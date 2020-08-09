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

	void equipWeapon(Item* weapon);
	void unequipWeapon();
	bool isEquipped();

	friend class InventoryScene;
	friend class ItemButton;
private:
	// INVENTORY
	Inventory *inventory;

	Item* weapon_equipped;

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
