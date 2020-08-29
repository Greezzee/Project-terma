#pragma once

#include "../../Scenes/LevelEditorScene.h"
#include "ImageWidget.h"

class Background : public ImageWidget
{
	bool to_draw = true;
public:
	Background();

	unsigned GetView();

	void Init(GameObject* owner) override;
	void Update() override;
	void Draw() override;
	void Destroy() override;

	~Background();
	bool isToDraw() const;
	void setToDraw(bool toDraw);

	friend LevelEditorScene;
};
