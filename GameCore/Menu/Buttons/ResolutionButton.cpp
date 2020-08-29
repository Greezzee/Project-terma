#include "ResolutionButton.h"

#include <cstdio>
#include <iostream>

#include "../../../Engine/Graphics/GraphicManager.h"
#include "../../../Engine/Utility/Coordinate.h"
#include "../../PTC.h"
#include "../../Textures.h"
#include "../../Views.h"

ResolutionButton::ResolutionButton() {
	resolution = 0;
}

void ResolutionButton::rightClickReact() {
	// Nothing for now
}

void ResolutionButton::leftClickReact() {
	if (resolution != res_count - 1) {
		resolution++;
	} else {
		resolution = 0;
	}

	switch (resolution) {
	case RES1024X576:
		GraphicManager::SetResolution(Vector2U(1024, 576));
		sprite_id = Textures::RES1024x576;
		Views::SET_RESOLUTION(Vector2U(1024, 576));

		break;
	case RES1600X900:
		GraphicManager::SetResolution(Vector2U(1600, 900));
		sprite_id = Textures::RES1600x900;
		Views::SET_RESOLUTION(Vector2U(1600, 900));
		break;
	case RES1920X1080:
		GraphicManager::SetResolution(Vector2U(1920, 1080));
		sprite_id = Textures::RES1920x1080;
		Views::SET_RESOLUTION(Vector2U(1920, 1080));
		break;
	}
}

void ResolutionButton::focusReact() {
	// Nothing for now
}

void ResolutionButton::disfocusReact() {
	// Nothing for now
}

void ResolutionButton::Destroy() {
	PTC::sayDestroyed("ResolutionButton");
}

void ResolutionButton::Init(GameObject *owner) {
	Vector2U _res = GraphicManager::GetResolution();

	if (_res == Vector2U(1024, 576)) {
		resolution = RES1024X576;
		sprite_id = Textures::RES1024x576;
	} else if (_res == Vector2U(1600, 900)) {
		resolution = RES1600X900;
		sprite_id = Textures::RES1600x900;
	} else if (_res == Vector2U(1920, 1080)) {
		resolution = RES1920X1080;
		sprite_id = Textures::RES1920x1080;
	}

	PTC::sayCreated("ResolutionButton");
}

ResolutionButton::~ResolutionButton() {
}
