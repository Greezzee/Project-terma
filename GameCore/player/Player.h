#pragma once

#include "../entities/Entity.h"

struct View;

class Player : public Entity {
public:
	Player();
	void Draw();
	GameObject* clone() const;
	void Update();
	View* getCamera();

private:
	View* camera;
};
