#include "EditorDisplayBar.h"

#include "../../PTC.h"

EditorDisplayBar::EditorDisplayBar() {}

void EditorDisplayBar::Init(GameObject *owner)
{
	PTC::sayCreated("EditorDisplayBar");
}

void EditorDisplayBar::Update() {}

void EditorDisplayBar::Destroy()
{
	PTC::sayDestroyed("EditorDisplayBar");
}

EditorDisplayBar::~EditorDisplayBar() {}
