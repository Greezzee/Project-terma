#include "ItemButton.h"

#include "../../Scenes/InventoryScene.h"

#include <cstdio>
#include <iostream>

ItemButton::ItemButton(Item *_item) {
	item = _item;
	was_focused = false;
}

const Vector2F weaponEquippedIcon = { 1021, 435 };

void ItemButton::clickReact() {
	// Equip this item (give the pointet to the player, indicate that other item is unequipped)

	InventoryScene *_scene = dynamic_cast<InventoryScene*>(current_scene);

	if (!item->isEquipped()) {
		// If the item isn't equipped yet

		if (_scene->gamefield->player->isEquipped()) {
			// Some item is equipped at the moment
			_scene->gamefield->player->weapon_equipped->unequip();
		}

		item->equip();
		_scene->gamefield->player->equipWeapon(item);
	} else {
		// Unequip this item

		printf("UNEQUIP!\n");

		item->unequip();
		_scene->gamefield->player->unequipWeapon();
	}
}

void ItemButton::focusReact() {
	// Show that this item is focused - indicate this item for item_focus image widget
	InventoryScene *_scene = dynamic_cast<InventoryScene*>(current_scene);
	_scene->focused_item->focusItem(this->item);
	was_focused = true;
	// printf("FOCUS ITEMBUTTON! ADDRESS - %x\n", _scene);
}

void ItemButton::disfocusReact() {
	/*
	 printf("=============\n");
	 printf("DISFOCUSED ITEMBUTTON NOW!\n");
	 printf("=============\n");
	 */

	// Disfocus (if have been focused)
	InventoryScene *_scene = dynamic_cast<InventoryScene*>(this->current_scene);

	if (was_focused) {
		_scene->focused_item->disfocus();
		was_focused = false;
	}
}

void ItemButton::Destroy() {
	printf("ItemButton destroyed!\n");
	std::cout.flush();
}

void ItemButton::Init(GameObject *owner) {
	printf("ItemButton created!\n");
}

void ItemButton::setOriginalPos(Vector2F original) {
	original_pos = original;
}

Vector2F ItemButton::getOriginalPos() {
	return original_pos;
}

void ItemButton::Update() {
	// If the item is equipped, change button's position. If not, return its position

	if (this->item->isEquipped()) {
		// If this button's item is equipped, change it's position to the equipped icon
		this->SetPos(weaponEquippedIcon);
		this->item->SetPos(weaponEquippedIcon);
	} else {
		// Othewise return the original position
		this->SetPos(this->getOriginalPos());
		this->item->SetPos(this->getOriginalPos());
	}

	if (isFocused())
		focusReact();
	else
		disfocusReact();
	if (isClicked())
		clickReact();
}

ItemButton::~ItemButton() {
	item = nullptr;
}