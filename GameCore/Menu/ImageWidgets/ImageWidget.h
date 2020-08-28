#pragma once

#include "../MenuWidget.h"
#include "../../../Engine/AllEngine.h"

//! ImageWidget class for scenes inherited from MenuScene.
//! Usage:
//! 1) Create a new image widget by inheriting it from this class
//! 2) In YOUR_MENU_SCENE::Init(): create a new image widget, call YOUR_IMAGE_WIDGET::Init(), set the scene, size,
//!    sprite_id and position, push this button to the 'widgets' vector.
//! 3) In YOUR_MENU_SCENE::Update(): call updateWidgets() and drawWidgets()
//! 4) In YOUR_MENU_SCENE::Destroy(): call YOUR_IMAGE_WIDGET::Destroy() and delete each widget, then clear the vector
//!	   and delete it
class ImageWidget : public MenuWidget
{
public:
	ImageWidget();

	virtual void Init(GameObject* owner) = 0;
	virtual void Update() = 0;
	virtual void Draw();
	virtual void Destroy() = 0;

	virtual ~ImageWidget();
};
