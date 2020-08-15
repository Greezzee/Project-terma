#pragma once

#include "../../../Engine/AllEngine.h"
#include "ImageWidget.h"

class Background : public ImageWidget
{
public:
	Background();

	unsigned GetView();

	void Init(GameObject* owner) override;
	void Update() override;
	void Draw() override;
	void Destroy() override;

	~Background();
};
