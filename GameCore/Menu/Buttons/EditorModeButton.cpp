#include "EditorModeButton.h"

#include <cstdio>
#include <iostream>

#include "../../Scenes/LevelEditorScene.h"
#include "../../Textures.h"

EditorModeButton::EditorModeButton() {
}

void EditorModeButton::rightClickReact() {
	// Nothing for now
}

void EditorModeButton::leftClickReact() {
	changeMode();
}

void EditorModeButton::focusReact() {
	// Nothing for now
}

void EditorModeButton::disfocusReact() {
	// Nothing for now
}

void EditorModeButton::Destroy() {
	printf("EditorModeButton destroyed!\n");
	std::cout.flush();
}

void EditorModeButton::Init(GameObject *owner) {
	printf("EditorModeButton created!\n");
}

void EditorModeButton::changeMode() {
	LevelEditorScene *_scene = dynamic_cast<LevelEditorScene*>(current_scene);

	if (_scene->getMode() == FRONT) {
		_scene->setMode(WALL);
		sprite_id = Textures::EDITOR_MODE_ACTIVE;
	} else {
		_scene->setMode(FRONT);
		sprite_id = Textures::EDITOR_MODE_DISACTIVE;
	}
}

EditorModeButton::~EditorModeButton() {
}
