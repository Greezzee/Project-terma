#pragma once

#include "Button.h"

#include "../../Scenes/MenuScene.h"

class PlayButton : public Button
{
public:
	PlayButton();

	virtual bool isClicked() override;
	virtual void clickReact() override;
	virtual void focusReact() override;

	virtual void Update() override;
	virtual void Draw() override;
	virtual void Destroy() override;
	virtual GameObject* clone() const override;
	virtual void Init(GameObject* owner) override;
};
