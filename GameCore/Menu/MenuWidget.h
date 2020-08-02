#pragma once

#include "../../Engine/Gameplay/GameObject.h"
#include "../Scenes/MenuScene.h"

class MenuScene;

class MenuWidget : public GameObject
{
protected:
	//! A pointer to the menu scene where this object is situated
	MenuScene* current_scene;

	//! A sprite ID that is meant to be put in the DrawData
	unsigned sprite_id;
public:
	MenuWidget();

	void setScene(MenuScene* _scene);
	void setSpriteID(unsigned _id);

	virtual void Init(GameObject* owner) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Destroy() = 0;

	//! Useless function for menu widgets
	GameObject* clone() const override;
};
