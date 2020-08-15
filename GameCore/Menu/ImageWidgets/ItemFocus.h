#pragma once

#include "ImageWidget.h"
#include "../../Items/Item.h"

class ItemFocus: public ImageWidget {
	// Put an item there to indicate it is focused
	Item *focused_item;
public:
	ItemFocus();

	void Init(GameObject *owner) override;
	void Update() override;
	void Draw() override;
	void Destroy() override;

	void focusItem(Item *_item);
	void disfocus();

	~ItemFocus();
};
