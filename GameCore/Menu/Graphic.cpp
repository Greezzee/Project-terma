/*
 * Graphic.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: timattt
 */

#include "Graphic.h"

#include "../../Engine/Debugger/Debugger.h"
#include "../../Engine/Graphics/DrawData.h"
#include "../../Engine/Utility/Coordinate.h"
#include "../Views.h"

Graphic::Graphic() {}

Graphic::~Graphic() {}

void Graphic::Init() {
}

void Graphic::Draw() {
	drawAxis();
	drawPoints();
}

void Graphic::Destroy() {
}

void Graphic::Update() {
}

void Graphic::Init(GameObject *owner) {
}

GameObject* Graphic::Clone() const {
	return nullptr;
}


void Graphic::drawAxis() {
	DrawData axis = {};

}

void Graphic::drawPoints() {
}
