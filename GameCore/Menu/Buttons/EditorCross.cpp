#include "EditorCross.h"

#include "../../Map/Map.h"
#include "../../Scenes/LevelEditorScene.h"

EditorCross::EditorCross() {
}

void EditorCross::rightClickReact() {
}

void EditorCross::leftClickReact() {
	LevelEditorScene *_scene = dynamic_cast<LevelEditorScene*>(current_scene);

	_scene->currentMap->setMayDrawWallBlockCrosses(!_scene->currentMap->isMayDrawWallBlockCrosses());
}

void EditorCross::focusReact() {
}

void EditorCross::disfocusReact() {
}

void EditorCross::Destroy() {
}

void EditorCross::Init(GameObject *owner) {
}

EditorCross::~EditorCross() {
}
