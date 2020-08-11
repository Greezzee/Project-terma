#pragma once

#include "../../../Engine/AllEngine.h"
#include "../MenuWidget.h"

//! Button class for scenes inherited from MenuScene.
//! Usage:
//! 1) Create a new button by inheriting it from this class
//! 2) Overwrite methods: disfocusReact(), clickReact(), focusReact()
//! 3) In YOUR_MENU_SCENE::Init(): create a new button, call YOUR_BUTTON::Init(), set the scene, size,
//!    sprite_id, gap and position, push this button to the 'widgets' vector.
//! 4) In YOUR_MENU_SCENE::Update(): call updateWidgets() and drawWidgets()
//! 5) In YOUR_MENU_SCENE::Destroy(): call YOUR_BUTTON::Destroy() and delete each widget, then clear the vector
//!	   and delete it
class Button : public MenuWidget
{
protected:
	// Gap for each button for proper "click-zone"
	// If the zone is too big, INcrease the gap
	// If the zone is too small, DEcrease the gap
	Vector2F _gap;
public:
	Button();
	//! Returns true if the mouse is on the button (doesn't work)
	bool isFocused();
	//! Returns true if the button was clicked
	bool isClicked();
	//! Sets the button's gap (for proper drawing)
	void SetGap(Vector2F __gap);

	//! A virtual method that determines what is meant to happen when the button is out of focus
	//! Paired with focusReact()
	virtual void disfocusReact() = 0;
	//! A virtual method that determines what is meant to happen when the button is clicked
	virtual void clickReact() = 0;
	//! A virtual method that determines what is meant to happen when the button is focused
	virtual void focusReact() = 0;

	//! Button's update function. Might be overwritten, basically does:
	//! isFocused -> focusReact, !isFocused -> disfocusReact, isClicked -> clickReact
	virtual void Update();
	//! Draws the button (view - MAIN_MENU), gets the size and position set before
	void Draw();
	//! Initialize the button
	virtual void Init(GameObject *owner) = 0;
	//! Destroys the button
	virtual void Destroy() = 0;

	virtual ~Button();
};
