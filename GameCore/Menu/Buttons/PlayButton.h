#pragma once

#include "Button.h"

#include "../../Scenes/MenuScene.h"

class PlayButton : public Button
{
protected:
	//! The menu scene where this button is situated
	MenuScene* menu_scene;
public:
	PlayButton(MenuScene* _scene);

	virtual bool isClicked() override;
	virtual void clickReact() override;
	virtual void focusReact() override;

	virtual void Update() override;
	virtual void Draw() override;
	virtual void Destroy() override;
	virtual GameObject* clone() const override;
	virtual void Init(GameObject* owner) override;
};
