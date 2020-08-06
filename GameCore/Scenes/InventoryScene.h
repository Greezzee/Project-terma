#include "MenuScene.h"
#include "GameplayScene.h"

class InventoryScene: public MenuScene
{
	Map *gamefield;
public:
	InventoryScene(Map* _map);

	void Init() override;
	void Update() override;
	void Destroy() override;

	// Delay before inventory can be closed
	unsigned delay;
};
