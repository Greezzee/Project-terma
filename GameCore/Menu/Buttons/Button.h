#pragma once

#include "../MenuWidget.h"
#include "../../../Engine/SceneManagment/Scene.h"

class Button : public MenuWidget
{
public:
	Button();
	//! Returns true if the mouse is on the button (doesn't work)
	bool isFocused();

	//! Returns true if the button was clicked
	//! (it was meant to be non-virtual, but as the mouse isn't supported yet, it is virtual)
	virtual bool isClicked() = 0;
	//! A virtual method that determines what is meant to happen when the button is clicked
	virtual void clickReact() = 0;
	//! A virtual method that determines what is meant to happen when the button is focused
	virtual void focusReact() = 0;

	void Update();
	virtual void Draw() = 0;
	virtual void Init(GameObject* owner) = 0;
	virtual void Destroy() = 0;
};
