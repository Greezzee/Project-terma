#include "EditorSave.h"

#include "../../LevelCoder/LevelCoder.h"
#include "../../PTC.h"

EditorSave::EditorSave(Map *_map)
{
	map_to_save = _map;
}

void EditorSave::rightClickReact() {
}

void EditorSave::leftClickReact()
{
	LevelCoder::CODE("TestLevel/new_level.PTRoom", map_to_save);

	PTC::say("New level saved!");
}

void EditorSave::focusReact() {
}

void EditorSave::disfocusReact() {
}

void EditorSave::Destroy() {
}

void EditorSave::Init(GameObject *owner) {
}

EditorSave::~EditorSave() {
}
