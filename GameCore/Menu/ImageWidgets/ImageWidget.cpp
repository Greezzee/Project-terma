#include "ImageWidget.h"

ImageWidget::ImageWidget() {
}

ImageWidget::~ImageWidget() {
}

void ImageWidget::Draw() {
	DrawData info = { };

	info.position = _pos;

	info.size = _size;

	info.origin = { 0.5, 0.5 };

	info.frame = 0;
	info.layer = this->layer;

	info.spriteID = this->sprite_id;
	GraphicManager::Draw(info, view_id);
}
