#include "ItemFocus.h"

#include <cstdio>
#include <iostream>

#include "../../../Engine/Graphics/DrawData.h"
#include "../../../Engine/Graphics/GraphicManager.h"
#include "../../../Engine/Utility/Coordinate.h"
#include "../../PTC.h"
#include "../../Views.h"

void ItemFocus::Init(GameObject *owner) {
	PTC::sayCreated("ItemFocus");
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
		info.layer = layer;

		info.spriteID = this->sprite_id;
		GraphicManager::Draw(info, Views::MAIN_MENU);
	}
}

ItemFocus::ItemFocus() {
	focused_item = nullptr;
}

void ItemFocus::Destroy() {
	PTC::sayDestroyed("ItemFocus");
}

void ItemFocus::focusItem(Item *_item) {
	focused_item = _item;
}

void ItemFocus::disfocus() {
	focused_item = nullptr;
}

ItemFocus::~ItemFocus() {}
