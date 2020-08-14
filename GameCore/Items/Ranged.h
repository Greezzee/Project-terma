#pragma once

#include "Usable.h"
#include "../Entities/Entity.h"

class Ranged: public Usable {
protected:
	float attack_speed;
	Entity* missile;
public:
	Ranged();

	virtual void rightClickReact() = 0;
	virtual void leftClickReact() = 0;

	virtual void Draw() = 0;
	virtual void Destroy() = 0;
	virtual void Init(GameObject *owner) = 0;
	virtual void Update() = 0;
	virtual GameObject* Clone() const = 0;

	virtual ~Ranged();
};
