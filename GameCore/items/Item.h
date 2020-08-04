#pragma once

#include "../../Engine/Gameplay/GameObject.h"

class Item : public GameObject {
public:
	virtual void Draw();
	virtual void Destroy();
	virtual void Init(GameObject *owner);
	virtual void Update();
};