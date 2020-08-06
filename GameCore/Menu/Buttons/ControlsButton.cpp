#include "ControlsButton.h"

#include <cstdio>
#include <iostream>

ControlsButton::ControlsButton() {}

void ControlsButton::clickReact()
{
	// Create controls scene
}

void ControlsButton::focusReact()
{
	// Nothing for now
}

void ControlsButton::disfocusReact()
{
	// Nothing for now
}

void ControlsButton::Destroy()
{
	printf("ControlsButton destroyed!\n");
	std::cout.flush();
}

void ControlsButton::Init(GameObject *owner)
{
	printf("ControlsButton created!\n");
}
