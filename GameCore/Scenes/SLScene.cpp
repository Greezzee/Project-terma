/*
 * SLScene.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: timattt
 */

#include "SLScene.h"

#include <vector>

#include "../Menu/Graphic.h"

SLScene::SLScene() {

}

SLScene::~SLScene() {

}

void SLScene::Init() {
	widgets = new std::vector<MenuWidget*>;
	widgets->push_back(new Graphic);
}

void SLScene::Update() {
	updateWidgets();
	drawWidgets();
}

void SLScene::Destroy() {
	destroyWidgets();
}
