#pragma once

#include "../../../Engine/AllEngine.h"
#include "ImageWidget.h"

class Background : public ImageWidget
{
	unsigned view;
public:
	Background();

	void SetView(unsigned _view);
	unsigned GetView();

	void Init(GameObject* owner) override;
	void Update() override;
	void Draw() override;
	void Destroy() override;

	~Background();
};
