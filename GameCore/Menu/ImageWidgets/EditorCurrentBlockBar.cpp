#include "EditorCurrentBlockBar.h"

#include <cstdio>
#include <iostream>

#include "../../../Engine/Graphics/DrawData.h"
#include "../../../Engine/Graphics/GraphicManager.h"
#include "../../PTC.h"

EditorCurrentBlockBar::EditorCurrentBlockBar() {
}

void EditorCurrentBlockBar::Init(GameObject *owner) {
	PTC::sayCreated("EditorCurrentBlock");
}

void EditorCurrentBlockBar::Update() {
}

void EditorCurrentBlockBar::Draw() {
	DrawData info = { };

	info.position = _pos;

	info.size = _size;

	info.origin = { 0.5, 0.5 };

	info.frame = 0;
	info.layer = this->layer;

	info.spriteID = this->sprite_id;
	GraphicManager::Draw(info, view_id);
}

void EditorCurrentBlockBar::Destroy() {
	PTC::sayDestroyed("EditorCurrentBlockBar");
}

EditorCurrentBlockBar::~EditorCurrentBlockBar() {
}
