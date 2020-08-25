#include "ItemButton.h"

#include <cstdio>
#include <iostream>

#include "../../../Engine/Control/InputManager.h"
#include "../../../Engine/Graphics/GraphicManager.h"
#include "../../../Engine/Utility/Coordinate.h"
#include "../../Items/Equippable.h"
#include "../../Map/Map.h"
#include "../../Player/Player.h"
#include "../../Scenes/InventoryScene.h"
#include "../../Views.h"
#include "../ImageWidgets/ItemFocus.h"

ItemButton::ItemButton(Item *_item) {
	item = _item;
	was_focused = false;
	is_dragged = false;
}

const Vector2F weaponEquippedIcon = { 1021, 435 };

void ItemButton::leftClickReact() {
	// Equip this item (give the pointer to the player, indicate that other item is unequipped)

	Equippable *_item = dynamic_cast<Equippable*>(item);

	if (_item != nullptr) {
		this->setDragged();

		/*
		 if (!_item->isEquipped()) {
		 // If the item isn't equipped yet

		 if (_scene->gamefield->player->isEquipped()) {
		 // Some item is equipped at the moment
		 Equippable *__item =
		 dynamic_cast<Equippable*>(_scene->gamefield->player->weapon_equipped);
		 __item->unequip();
		 }

		 _item->equip();
		 _scene->gamefield->player->equipWeapon(item);
		 } else {
		 // Unequip this item

		 printf("UNEQUIP!\n");

		 _item->unequip();
		 _scene->gamefield->player->unequipWeapon();
		 }
		 */
	}
}

void ItemButton::focusReact() {
	// Show that this item is focused - indicate this item for item_focus image widget
	InventoryScene *_scene = dynamic_cast<InventoryScene*>(current_scene);

	if (!is_dragged) {
		_scene->focused_item->focusItem(this->item);
		was_focused = true;
	} else {
		disfocusReact();
	}
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
	Equippable *_item = dynamic_cast<Equippable*>(item);

	if (isDragged()) {
		_item->SetPos(
				GraphicManager::ConvertRealToView(InputManager::GetMousePos(),
						Views::MAIN_MENU));
		SetPos(
				GraphicManager::ConvertRealToView(InputManager::GetMousePos(),
						Views::MAIN_MENU));
	}

	if (_item != nullptr && !is_dragged) {
		if (_item->isEquipped()) {
			// If this button's item is equipped, change it's position to the equipped icon
			SetPos(weaponEquippedIcon);
			item->SetPos(weaponEquippedIcon);
		} else {
			// Othewise return the original position
			SetPos(getOriginalPos());
			item->SetPos(getOriginalPos());
		}
	}
	if (isFocused())
		focusReact();
	else
		disfocusReact();
	if (isRightClicked())
		rightClickReact();
	if (isLeftClicked())
		leftClickReact();
	if (InputManager::IsRealesed(MouseKey::Mouse_Left) && is_dragged) {
		leftButtonReleaseReact();
	}
}

void ItemButton::rightClickReact() {
	// Nothing for now
}

void ItemButton::setDragged() {
	is_dragged = true;
}

bool ItemButton::isDragged() {
	return is_dragged;
}

void ItemButton::leftButtonReleaseReact() {
	// If the item was released, check its position
	InventoryScene *_scene = dynamic_cast<InventoryScene*>(current_scene);
	Equippable *_item = dynamic_cast<Equippable*>(item);

	is_dragged = false;

	Vector2F calculate = {_pos.x - itemStartPos.x, _pos.y - itemStartPos.y};

	// If the button got to the equipping icon, its good
	if (_pos.x >= weaponEquippedIcon.x - _size.x / 2
			&& _pos.x <= weaponEquippedIcon.x + _size.x / 2
			&& _pos.y >= weaponEquippedIcon.y - _size.y / 2
			&& _pos.y <= weaponEquippedIcon.y + _size.y / 2) {
		if (_scene->gamefield->player->isEquipped()) {
			// Some item is equipped at the moment
			Equippable *__item =
					dynamic_cast<Equippable*>(_scene->gamefield->player->weapon_equipped);
			__item->unequip();
		}

		_item->equip();
		_scene->gamefield->player->equipWeapon(item);
	} else if (_pos.x >= getOriginalPos().x - _size.x / 2
			&& _pos.x <= getOriginalPos().x + _size.x / 2
			&& _pos.y >= getOriginalPos().y - _size.y / 2
			&& _pos.y <= getOriginalPos().y + _size.y / 2) {
		// Unequip and put back
		_item->unequip();
		_scene->gamefield->player->unequipWeapon();
		SetPos(getOriginalPos());
	}
}

ItemButton::~ItemButton() {
	item = nullptr;
}
