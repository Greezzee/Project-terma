#include "ItemButton.h"

#include <cstdio>
#include <iostream>

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
	printf("ItemButton destroyed!\n");
	std::cout.flush();
}

void ItemButton::Init(GameObject *owner)
{
	printf("ItemButton created!\n");
}

ItemButton::~ItemButton()
{
	item = nullptr;
}
