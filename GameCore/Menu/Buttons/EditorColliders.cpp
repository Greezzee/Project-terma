#include "EditorColliders.h"

#include "../../Map/Map.h"
#include "../../Scenes/LevelEditorScene.h"

EditorColliders::EditorColliders() {
}

void EditorColliders::rightClickReact() {
}

void EditorColliders::leftClickReact() {
	LevelEditorScene *_scene = dynamic_cast<LevelEditorScene*>(current_scene);

	_scene->currentMap->setMayDrawColliders(!_scene->currentMap->isMayDrawColliders());
}

void EditorColliders::focusReact() {
}

void EditorColliders::disfocusReact() {
}

void EditorColliders::Destroy() {
}

void EditorColliders::Init(GameObject *owner) {
}

EditorColliders::~EditorColliders() {
}
