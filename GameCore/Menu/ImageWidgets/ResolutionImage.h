#pragma once

#include "ImageWidget.h"

class ResolutionImage: public ImageWidget {
public:
	ResolutionImage();

	void Init(GameObject *owner) override;
	void Update() override;
	void Draw() override;
	void Destroy() override;

	~ResolutionImage();
};
