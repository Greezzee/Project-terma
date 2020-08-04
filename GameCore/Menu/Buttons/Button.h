#pragma once

#include "../MenuWidget.h"
#include "../../../Engine/SceneManagment/Scene.h"

class Button : public MenuWidget
{
protected:
	// Gap for each button for proper "click-zone"
	// If the zone is too big, INcrease the gap
	// If the zone is too small, DEcrease the gap
	Vector2F _gap;
	// Size of the sprite
	Vector2F _size;
public:
	Button();
	//! Returns true if the mouse is on the button (doesn't work)
	bool isFocused();
	//! Returns true if the button was clicked
	bool isClicked();
	//! Sets the button's gap
	void SetGap(Vector2F __gap);

	//! A virtual method that determines what is meant to happen when the button is clicked
	virtual void clickReact() = 0;
	//! A virtual method that determines what is meant to happen when the button is focused
	virtual void focusReact() = 0;

	void SetSize(Vector2F __size);
	Vector2F GetSize();

	void Update();
	void Draw();
	virtual void Destroy() = 0;
};
