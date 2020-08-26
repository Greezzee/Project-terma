#pragma once

#include "ImageWidget.h"

class EditorPanel: public ImageWidget {
public:
	EditorPanel();

	void Init(GameObject *owner) override;
	void Update() override;
	void Draw() override;
	void Destroy() override;

	~EditorPanel();

};
