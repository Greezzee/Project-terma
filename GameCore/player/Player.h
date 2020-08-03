#pragma once

#include "../entities/SolidEntity.h"

struct View;

class Player : public SolidEntity {
public:
	Player();
	void Draw();
	GameObject* clone() const;
	void Update();
	View* getCamera();

private:
	View* camera;
	bool lookingRight;
};
