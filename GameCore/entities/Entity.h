#pragma once

#include "../../Engine/Gameplay/GameObject.h"

class Entity : public GameObject {
public:
	void Destroy() override;
	void Init(GameObject *owner) override;
};
