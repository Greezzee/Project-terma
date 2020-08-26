#include "EditorPanel.h"

#include <cstdio>
#include <iostream>

#include "../../../Engine/Graphics/DrawData.h"
#include "../../../Engine/Graphics/GraphicManager.h"

EditorPanel::EditorPanel() {}

void EditorPanel::Init(GameObject *owner) {
	printf("EditorPanel created!\n");
}

void EditorPanel::Update() {}

void EditorPanel::Draw() {
	DrawData info = { };

	info.position = _pos;

	info.size = _size;

	info.origin = { 0.5, 0.5 };

	info.frame = 0;
	info.layer = this->layer;

	info.spriteID = this->sprite_id;
	GraphicManager::Draw(info, view_id);
}

void EditorPanel::Destroy()
{
	printf("EditorPanel destroyed!\n");
	std::cout.flush();

}

EditorPanel::~EditorPanel() {}
