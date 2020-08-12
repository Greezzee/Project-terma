#include "ItemFocus.h"

#include <cstdio>
#include <iostream>

#include "../../../Engine/Graphics/DrawData.h"
#include "../../../Engine/Graphics/GraphicManager.h"
#include "../../../Engine/Utility/Coordinate.h"
#include "../../Items/Item.h"
#include "../../Views.h"

void ItemFocus::Init(GameObject *owner) {
	printf("ItemFocus created!\n");
}

void ItemFocus::Update() {
	// Nothing for now
}

void ItemFocus::Draw() {
	if (focused_item != nullptr) {
		DrawData info = { };

		info.position = focused_item->GetPos();

		info.size = _size;

		info.origin = { 0.5, 0.5 };

		info.frame = 0;
		info.layer = 2;

		info.spriteID = this->sprite_id;
		GraphicManager::Draw(info, Views::MAIN_MENU);
	}
}

ItemFocus::ItemFocus() {
	focused_item = nullptr;
}

void ItemFocus::Destroy() {
	printf("ItemFocus destroyed!\n");
	std::cout.flush();
}

void ItemFocus::focusItem(Item *_item) {
	focused_item = _item;
}

void ItemFocus::disfocus() {
	focused_item = nullptr;
}
