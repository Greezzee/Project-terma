#pragma once

#include "../../Entities/Entity.h"

class RedStar: public Entity {

public:
	RedStar();

	void Draw();
	GameObject* Clone() const;
	void Update();

};
