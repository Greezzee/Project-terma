#include "Cell.h"

Cell::Cell()
{
	button = nullptr;
}

void Cell::drawCell()
{
	if (button != nullptr)
		button->Draw();
}

Cell::~Cell() {}
