#include "Inventory.h"

#include <cstdio>
#include <iostream>

#include "../PTC.h"

Inventory::Inventory()
{
	items = nullptr;
}

Inventory::~Inventory()
{
	items = nullptr;
}

void Inventory::Init()
{
	// TODO Read items from the save file
	items = new std::vector<Item*>;
	items->resize(inventorySize, nullptr);

	PTC::sayCreated("Inventory");
}

void Inventory::Update()
{
	// Nothing for now
}

void Inventory::Destroy()
{
	delete items;

	PTC::sayDestroyed("Inventory");
}

void Inventory::addItem(Item *_item)
{
	items->push_back(_item);
}

std::vector<Item*>* Inventory::getItems()
{
	return items;
}

unsigned Inventory::getItemsNumber()
{
	return items->size();
}
