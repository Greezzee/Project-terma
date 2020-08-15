#pragma once

#include "Button.h"

#include "../../../Engine/AllEngine.h"

const unsigned res_count = 3;

enum Resolutions {
	RES1024X576 = 0, RES1600X900, RES1920X1080
};

class ResolutionButton: public Button {
	unsigned resolution;
public:
	ResolutionButton();

	void rightClickReact() override;
	void leftClickReact() override;

	void focusReact() override;
	void disfocusReact() override;
	void Destroy() override;
	void Init(GameObject *owner) override;

	~ResolutionButton();
};
