#pragma once

#include "ImageWidget.h"

class EditorDisplayBar: public ImageWidget {
public:
	EditorDisplayBar();

	void Init(GameObject *owner) override;
	void Update() override;
	void Destroy() override;

	~EditorDisplayBar();
};
