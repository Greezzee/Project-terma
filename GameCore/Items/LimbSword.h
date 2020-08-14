#pragma once

#include "../Items/Melee.h"

class LimbSword: public Melee {
public:
	LimbSword();

	void rightClickReact() override;
	void leftClickReact() override;

	void Draw() override;
	void Destroy() override;
	void Init(GameObject *owner) override;
	void Update() override;
	GameObject* Clone() const override;

	~LimbSword() {}
};
