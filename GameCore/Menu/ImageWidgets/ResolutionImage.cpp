#include "ResolutionImage.h"

#include <cstdio>

#include "../../../Engine/Graphics/DrawData.h"
#include "../../../Engine/Graphics/GraphicManager.h"
#include "../../PTC.h"

ResolutionImage::ResolutionImage() {
}

void ResolutionImage::Init(GameObject *owner) {
	PTC::sayCreated("ResolutionImage");
}

void ResolutionImage::Update() {
	// Nothing for now
}

void ResolutionImage::Draw() {
	DrawData info = { };

	info.position = _pos;

	info.size = _size;

	info.origin = { 0.5, 0.5 };

	info.frame = 0;
	info.layer = 1;

	info.spriteID = this->sprite_id;
	GraphicManager::Draw(info, view_id);
}

void ResolutionImage::Destroy() {
	PTC::sayDestroyed("ResolutionImage");
}

ResolutionImage::~ResolutionImage() {
}
