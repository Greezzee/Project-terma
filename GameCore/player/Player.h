#pragma once

#include "../entities/Damageable.h"
#include "../entities/SolidEntity.h"
#include "Inventory.h"

struct DrawData;
class Item;
struct View;

class Inventory;

class Player: public SolidEntity, public Damageable {
public:
	Player();
	void Draw();
	void Destroy() override;
	GameObject* Clone() const;
	void Update();
	View* getCamera();
	virtual void Init(GameObject *owner);

	//! Get the current equipped weapon. Returns the nullptr, if none weapon is equipped at the time
	Item* getEquippedWeapon();

	//! Equips the given weapon to this player
	void equipWeapon(Item* weapon);

	//! Unequip the current weapon of this player
	void unequipWeapon();

	//! Returns true if some weapon is equipped, otherwise false
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
