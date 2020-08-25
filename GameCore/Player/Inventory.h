#pragma once

#include <stddef.h>
#include <vector>

#include "../Items/Item.h"
#include "../Player/Player.h"

class Player;

const unsigned inventorySize = 56;

class Inventory {
	std::vector<Item*>* items;
public:
	Inventory();
	~Inventory();

	void addItem(Item* _item);
	unsigned getItemsNumber();
	std::vector<Item*>* getItems();

	void Init();
	void Update();
	void Destroy();

	friend class Player;
private:
	Player * player = NULL;
};
