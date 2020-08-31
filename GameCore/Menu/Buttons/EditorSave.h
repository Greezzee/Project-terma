#pragma once

#include "../../Map/Map.h"
#include "Button.h"

class EditorSave: public Button {
	Map* map_to_save;
public:
	EditorSave(Map* _map);

	void rightClickReact() override;
	void leftClickReact() override;

	void focusReact() override;
	void disfocusReact() override;
	void Destroy() override;
	void Init(GameObject *owner) override;

	~EditorSave();
};
