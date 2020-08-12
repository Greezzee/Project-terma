#pragma once

#include "../Entities/Damageable.h"
#include "../Entities/SolidEntity.h"
#include "../Player/Inventory.h"

struct DrawData;
class Item;
struct View;

class Inventory;

const float DELAY_BETWEEN_JUMPS = 0.1f;

class Player: public SolidEntity, public Damageable {
public:

	// BASE
	//--------------------------------------------------------------------
	Player();
	void Draw();
	void Destroy() override;
	GameObject* Clone() const;
	void Update();
	void Init(GameObject *owner);
	//--------------------------------------------------------------------

	// GETTERS AND SETTERS
	//--------------------------------------------------------------------
	//! Get the current equipped weapon. Returns the nullptr, if none weapon is equipped at the time
	Item* getEquippedWeapon();
	//! Equips the given weapon to this player
	void equipWeapon(Item *weapon);
	//! Unequip the current weapon of this player
	void unequipWeapon();
	//! Returns true if some weapon is equipped, otherwise false
	bool isEquipped();
	View* getCamera();
	//--------------------------------------------------------------------

	// FRIENDS
	//--------------------------------------------------------------------
	friend class InventoryScene;
	friend class ItemButton;
	//--------------------------------------------------------------------

private:

	// INVENTORY
	//--------------------------------------------------------------------
	Inventory *inventory;
	Item *weapon_equipped;
	//--------------------------------------------------------------------

	// Camera
	//--------------------------------------------------------------------
	View *camera;
	//--------------------------------------------------------------------

	bool lookingRight;

	// DRAW
	//---------------------------
	void drawHealthBar();
	void drawPlayer();
	//---------------------------

	// LIGHT
	void correctLight(DrawData &data);
};
