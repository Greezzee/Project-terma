#pragma once

#include "../entities/Entity.h"

class Player : public Entity {
public:
	Player();
	virtual void Draw();
	virtual GameObject* clone() const;
	virtual void Update();
};
