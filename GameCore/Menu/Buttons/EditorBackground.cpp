#include "EditorBackground.h"

#include "../../Map/Map.h"
#include "../../Scenes/LevelEditorScene.h"

EditorBackground::EditorBackground() {}

void EditorBackground::rightClickReact() {}

void EditorBackground::leftClickReact()
{
	LevelEditorScene *_scene = dynamic_cast<LevelEditorScene*>(current_scene);

	_scene->currentMap->setMayDrawBackground(!_scene->currentMap->isMayDrawBackground());
}

void EditorBackground::focusReact() {}

void EditorBackground::disfocusReact() {}

void EditorBackground::Destroy() {}

void EditorBackground::Init(GameObject *owner) {}

EditorBackground::~EditorBackground() {}
