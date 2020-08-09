#pragma once

#include "../../../Engine/Graphics/DrawData.h"
#include "ImageWidget.h"

class Background : public ImageWidget
{
	Views view;
public:
	Background();

	void SetView(Views _view);
	Views GetView();

	void Init(GameObject* owner) override;
	void Update() override;
	void Draw() override;
	void Destroy() override;

	~Background();
};
