#include "RedStar.h"

#include "../../../Engine/Graphics/DrawData.h"
#include "../../../Engine/Graphics/GraphicManager.h"
#include "../../Map.h"
#include "../../Textures.h"

RedStar::RedStar() {
	texture_size = {BLOCK_SIZE * 10 , BLOCK_SIZE * 10};
	collider_size = {BLOCK_SIZE * 10 , BLOCK_SIZE * 10};
}

void RedStar::Draw() {

	DrawData info = { };

	// BASE DATA
	//----------------------------
	info.position = this->_pos;
	info.size = this->texture_size;
	info.rotation = _angle;
	//----------------------------

	//----------------------------
	info.origin = { 0.5, 0.5 };
	info.frame = 0;
	info.layer = 0;
	//----------------------------

	// SET TEXTURE
	//----------------------------
	info.spriteID = Textures::RED_STAR;
	//----------------------------

	// DRAW
	//----------------------------
	GraphicManager::Draw(info, Views::PLAYER_CAM);
	//----------------------------

}

GameObject* RedStar::Clone() const {
	return new RedStar();
}

void RedStar::Update() {
	_angle += (float)(rand() % 100 - 50) / 100;
}
