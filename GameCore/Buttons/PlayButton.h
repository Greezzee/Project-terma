#pragma once

#include "Button.h"

class PlayButton : public Button
{
public:
	PlayButton(Scene *_scene, unsigned _sprite_id);

	virtual bool isClicked() override;
	virtual void clickReact() override;
	virtual void focusReact() override;

	virtual void Update() override;
	virtual void Draw() override;
	virtual void Destroy() override;
	virtual GameObject* clone() const override;
	virtual void Init(GameObject* owner) override;
};
