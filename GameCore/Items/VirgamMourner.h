#pragma once

#include "Ranged.h"

const float VIRGAM_MOURNER_ATTACK_SPEED = 5;

class VirgamMourner: public Ranged {
public:
	VirgamMourner(Entity* _missile);

	void rightClickReact() override;
	void leftClickReact() override;

	void Draw() override;
	void Destroy() override;
	void Init(GameObject *owner) override;
	void Update() override;
	GameObject* Clone() const override;

	~VirgamMourner();
};
