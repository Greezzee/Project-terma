#pragma once

#include "../MenuWidget.h"
#include "../../../Engine/SceneManagment/Scene.h"

//! Все кнопки должны наследоваться от этого класса. При инициализации в
//! сцене обязательно задать размер, позицию и gap.
//! Так же обязательно переопределить disfocusReact()
//!	clickReact(), focusReact(), Destroy().
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
	//! Sets the button's gap
	void SetGap(Vector2F __gap);

	//! A virtual method that determines what is meant to happen when the button is out of focus
	//! Paired with focusReact()
	virtual void disfocusReact() = 0;
	//! A virtual method that determines what is meant to happen when the button is clicked
	virtual void clickReact() = 0;
	//! A virtual method that determines what is meant to happen when the button is focused
	virtual void focusReact() = 0;

	void Update();
	void Draw();
	virtual void Init(GameObject *owner) = 0;
	virtual void Destroy() = 0;

	virtual ~Button();
};
