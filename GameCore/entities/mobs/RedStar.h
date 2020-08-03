#pragma once

#include "../Entity.h"

class RedStar: public Entity {

public:
	RedStar();

	void Draw();
	GameObject* clone() const;
	void Update();

};
