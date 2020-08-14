#pragma once

#include "Equippable.h"

class Usable: public Equippable {
public:
	Usable();

	virtual void rightClickReact() = 0;
	virtual void leftClickReact() = 0;

	virtual void Draw() = 0;
	virtual void Destroy() = 0;
	virtual void Init(GameObject *owner) = 0;
	virtual void Update() = 0;
	virtual GameObject* Clone() const = 0;

	virtual ~Usable();
};
