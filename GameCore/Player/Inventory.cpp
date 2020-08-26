#include "../Player/Inventory.h"

#include <cstdio>
#include <iostream>

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

	printf("Inventory created!\n");
}

void Inventory::Update()
{
	// Nothing for now
}

void Inventory::Destroy()
{
	delete items;

	printf("Inventory destroyed!\n");
	std::cout.flush();
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
