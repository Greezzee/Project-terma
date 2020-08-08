#include <stddef.h>
#include <vector>

#include "../items/Item.h"

class Player;

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
private:
	Player * player = NULL;
};
