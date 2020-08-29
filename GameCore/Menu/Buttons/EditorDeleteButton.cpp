#include "EditorDeleteButton.h"

#include <cstdio>

#include "../../PTC.h"
#include "../../Scenes/LevelEditorScene.h"
#include "../../Textures.h"

EditorDeleteButton::EditorDeleteButton()
{
	delete_active = false;
}

void EditorDeleteButton::active()
{
	delete_active = true;
}

void EditorDeleteButton::disactive()
{
	delete_active = false;
}

bool EditorDeleteButton::getStatus()
{
	return delete_active;
}

void EditorDeleteButton::rightClickReact()
{
	//
}

void EditorDeleteButton::leftClickReact()
{
	LevelEditorScene *_scene = dynamic_cast<LevelEditorScene*>(current_scene);

	if (delete_active) {
		_scene->toAdd();
		disactive();
		sprite_id = Textures::EDITOR_DELETE_DISACTIVE;
	}
	else {
		_scene->toDelete();
		active();
		sprite_id = Textures::EDITOR_DELETE_ACTIVE;
	}
}

void EditorDeleteButton::focusReact()
{
	//
}

void EditorDeleteButton::disfocusReact()
{
	//
}

void EditorDeleteButton::Destroy()
{
	PTC::sayDestroyed("EditorDeleteButton");
}

void EditorDeleteButton::Init(GameObject *owner)
{
	PTC::sayCreated("EditorDeleteButton");
}

EditorDeleteButton::~EditorDeleteButton() {}
