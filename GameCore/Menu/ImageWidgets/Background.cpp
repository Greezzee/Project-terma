#include "Background.h"

#include "../../../Engine/Graphics/DrawData.h"
#include "../../../Engine/Graphics/GraphicManager.h"

Background::Background() {}

void Background::Init(GameObject *owner) {
	printf("Background created!\n");
}

void Background::Update() {
	//! Background is a static image
	return ;
}

void Background::Draw() {
	DrawData info = { };

	info.position = _pos;

	info.size = _size;

	info.origin = { 0.5, 0.5 };

	info.frame = 0;
	info.layer = 0;

	info.spriteID = this->sprite_id;
	GraphicManager::Draw(info, view_id);
}


unsigned Background::GetView()
{
	return view_id;
}

void Background::Destroy() {
	printf("Background destroyed!\n");
}

Background::~Background() {}
