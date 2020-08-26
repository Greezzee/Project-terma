#include "EditorCurrentBlockBar.h"

#include <cstdio>
#include <iostream>

EditorCurrentBlockBar::EditorCurrentBlockBar() {
}

void EditorCurrentBlockBar::Init(GameObject *owner) {
	printf("EditorCurrentBlock created!\n");
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
	printf("EditorCurrentBlock destroyed!\n");
	std::cout.flush();
}

EditorCurrentBlockBar::~EditorCurrentBlockBar() {
}
