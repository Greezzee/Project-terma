#include "ItemButton.h"

ItemButton::ItemButton(Item* _item)
{
	item = _item;
}

void ItemButton::clickReact()
{
	// Nothing for now
}

void ItemButton::focusReact()
{
	// Nothing for now
}

void ItemButton::disfocusReact()
{
	// Nothing for now
}

void ItemButton::Destroy()
{
	printf("ItemButton created!\n");
}

void ItemButton::Init(GameObject *owner)
{
	printf("ItemButton created!\n");
}

ItemButton::~ItemButton()
{
	item = nullptr;
}
