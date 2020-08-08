#include "MenuScene.h"
#include "GameplayScene.h"

#include "../player/Inventory.h"

class InventoryScene: public MenuScene {
	Map *gamefield;
	Inventory* inventory;
public:
	InventoryScene(Map *_map);

	void Init() override;
	void Update() override;
	void Destroy() override;

	// Delay before inventory can be closed
	unsigned delay;
};
