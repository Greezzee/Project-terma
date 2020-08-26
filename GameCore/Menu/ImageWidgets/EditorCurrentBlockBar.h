#pragma once

#include "../../Blocks/Block.h"
#include "ImageWidget.h"

class EditorCurrentBlockBar : public ImageWidget {
public:
	EditorCurrentBlockBar();

	void Init(GameObject *owner) override;
	void Update() override;
	void Draw() override;
	void Destroy() override;

	~EditorCurrentBlockBar();
};
