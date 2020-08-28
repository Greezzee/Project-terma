#include "EditorLight.h"

#include "../../Map/Map.h"
#include "../../Scenes/LevelEditorScene.h"

EditorLight::EditorLight() {
}

void EditorLight::rightClickReact() {
}

void EditorLight::leftClickReact() {
	LevelEditorScene *_scene = dynamic_cast<LevelEditorScene*>(current_scene);

	_scene->currentMap->setIgnoreLight(
			!_scene->currentMap->isIgnoreLight());
}

void EditorLight::focusReact() {
}

void EditorLight::disfocusReact() {
}

void EditorLight::Destroy() {
}

void EditorLight::Init(GameObject *owner) {
}

EditorLight::~EditorLight() {
}
