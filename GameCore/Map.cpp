#include "Map.h"

#include <stddef.h>
#include <iterator>

#include "../Engine/Colliders/Collider.h"
#include "../Engine/Colliders/SquareCollider.h"
#include "../Engine/Graphics/DrawData.h"
#include "../Engine/Graphics/GraphicManager.h"
#include "../Engine/Utility/Coordinate.h"

#include "Blocks/DirtBlock.h"
#include "Blocks/GrassBlock.h"
#include "entities/mobs/RedStar.h"
#include "Level.h"
#include "player/Player.h"
#include "Textures.h"

void Map::setLevel(Level *level) {
	this->level = level;
}

Level* Map::getLevel() {
	return this->level;
}

void Map::addBlock(Vector2I pos, Block *block) {
	this->blocks[pos.x][pos.y] = block;
}

void Map::Init() {
	this->level->generate(this);
	this->player = new Player();
	this->addEntity( { 500, 500 }, this->player);

	genTestStuff();
}

void Map::Update() {
	updateBlocks();
	updateEntities();

	drawBackground();
	drawBlocks();
	drawEntities();
}

void Map::Destroy() {
}

void Map::addEntity(Vector2F pos, Entity *entity) {
	entity->SetPos( { pos.x, pos.y });
	entity->setMap(this);
	this->entities.push_back(entity);
}

Block* Map::getBlockFromMesh(Vector2I pos) {
	return blocks[pos.x][pos.y];
}

void Map::removeEntity(Entity *entity) {
	for (auto it = entities.begin(); it != entities.end(); it++) {
		if (entity == *it) {
			entities.erase(it);
			return;
		}
	}
}

/*

 Y
 ^
 |
 |
 |		          +-----* (x1, y1)
 |                |BLOCK|
 |	     	      |     |
 y*       (x0, y0) *-----+
 |
 |
 |
 +----------------*-----------------> X
 |		          x
 |


 */
//! Рисует блоки, схема прорисовки в ИГРОВЫХ координатах выше.
void Map::drawBlocks() {
	View *camera = this->player->getCamera();
	int total = 0;
	for (int x = (camera->virtual_position.x - camera->virtual_size.x / 2)
			/ BLOCK_SIZE - 1;
			x
					< (camera->virtual_position.x + camera->virtual_size.x / 2)
							/ BLOCK_SIZE + 1; x++) {
		for (int y = (camera->virtual_position.y - camera->virtual_size.y / 2)
				/ BLOCK_SIZE - 1;
				y
						< (camera->virtual_position.y
								+ camera->virtual_size.y / 2) / BLOCK_SIZE + 1;
				y++) {
			if (x < 0 || x >= MAX_LEVEL_SIZE || y < 0 || y >= MAX_LEVEL_SIZE) {
				continue;
			}

			Block *currBlock = blocks[x][y];

			if (!currBlock) {
				continue;
			}
			total++;

			float x0 = x * BLOCK_SIZE;
			float y0 = y * BLOCK_SIZE;

			float x1 = (x + 1) * BLOCK_SIZE;
			float y1 = (y + 1) * BLOCK_SIZE;

			DrawData info = { };
			info.position.x = (x0 + x1) / 2;
			info.position.y = (y0 + y1) / 2;

			info.size.x = BLOCK_SIZE;
			info.size.y = BLOCK_SIZE;

			info.origin = { 0.5, 0.5 };

			info.frame = 0;
			info.layer = 0;

			info.spriteID = currBlock->getSpriteId();
			GraphicManager::Draw(info, Views::PLAYER_CAM);
		}
	}
	//std::cout << "rendered: " << total << "\n";
}

void Map::drawEntities() {
	for (Entity *ent : entities) {
		ent->Draw();
	}
}

void Map::drawBackground() {
	DrawData info = { };
	info.position.x = player->GetPos().x;
	info.position.y = player->GetPos().y;

	info.size.x = 2000;
	info.size.y = 1000;

	info.origin = { 0.5, 0.5 };

	info.frame = 0;
	info.layer = 0;

	info.spriteID = Textures::TEST_BACKGROUND;
	GraphicManager::Draw(info, Views::PLAYER_CAM);
}

void Map::updateBlocks() {
	for (int i = 0; i < MAX_LEVEL_SIZE; i++) {
		for (int j = 0; j < MAX_LEVEL_SIZE; j++) {
			if (blocks[i][j])
				blocks[i][j]->Update();
		}
	}
}

void Map::genTestStuff() {
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < MAX_LEVEL_SIZE; x++) {
			addBlock( { x, y }, new DirtBlock());
		}
	}
	for (int y = 5; y < 8; y++) {
		for (int x = 0; x < MAX_LEVEL_SIZE; x++) {
			addBlock( { x, y }, new GrassBlock());
		}
	}

	addEntity({600, 500}, new RedStar());
}

bool Map::testCollision(SquareCollider *col) {
	SquareCollider bl = { };
	Vector2F bl_sz = { BLOCK_SIZE / 2, BLOCK_SIZE / 2 };

	for (int y = (col->getPos().y - 3 * col->getSize().y) / BLOCK_SIZE - 1;
			y < (col->getPos().y + 3 * col->getSize().y) / BLOCK_SIZE + 1;
			y++) {
		for (int x = (col->getPos().x - 3 * col->getSize().x) / BLOCK_SIZE - 1;
				x < (col->getPos().x + 3 * col->getSize().x) / BLOCK_SIZE + 1;
				x++) {
			if (x < 0 || x >= MAX_LEVEL_SIZE || y < 0 || y >= MAX_LEVEL_SIZE) {
				continue;
			}
			Vector2F p0 = Vector2F { (float) x, (float) y } * (float) BLOCK_SIZE
					+ Vector2F(0.5, 0.5) * (float) BLOCK_SIZE;
			if (blocks[x][y] == NULL) {
				continue;
			}
			bl.Init(blocks[x][y], p0, bl_sz);

			if (Collider::IsCollide(&bl, col)) {
				return 1;
			}
		}
	}

	return 0;
}

void Map::updateEntities() {
	for (Entity *ent : entities) {
		ent->Update();
	}
}
