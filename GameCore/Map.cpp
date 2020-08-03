#include "Map.h"

#include <cstdlib>
#include <iostream>
#include <iterator>
#include <type_traits>

#include "../Engine/Colliders/Collider.h"
#include "../Engine/Colliders/SquareCollider.h"
#include "../Engine/Graphics/DrawData.h"
#include "../Engine/Graphics/GraphicManager.h"
#include "../Engine/Utility/Coordinate.h"
#include "Blocks/DirtBlock.h"
#include "Blocks/GrassBlock.h"
#include "Blocks/multiblockStructures/Multiblock.h"
#include "Blocks/multiblockStructures/StructureBlock.h"
#include "Blocks/multiblockStructures/Tree.h"
#include "entities/mobs/RedStar.h"
#include "Level.h"
#include "player/Player.h"
#include "Textures.h"

class Multiblock;

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
	this->addEntity( { 1500, 700 }, this->player);

	genTestStuff();
}

void Map::Update() {
	updateBlocks();
	updateEntities();

	drawBackground();
	drawBlocks();
	drawEntities();
	drawMultiblocks();
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

template<typename Base, typename T> inline bool Map::instanceof(const T*) {
	return std::is_base_of<Base, T>::value;
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
			if (dynamic_cast<Multiblock*>(currBlock) != NULL) {
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
	for (int y = 0; y < 14; y++) {
		for (int x = 0; x < MAX_LEVEL_SIZE; x++) {
			addBlock( { x, y }, new DirtBlock());
		}
	}
	for (int y = 10; y < 14; y++) {
		for (int x = 0; x < MAX_LEVEL_SIZE; x++) {
			int token = random() % 3;
			if (token == 1 || token == 2)
				addBlock( { x, y }, new GrassBlock());
		}
	}
	for (int y = 13; y < 14; y++) {
		for (int x = 0; x < MAX_LEVEL_SIZE; x++) {
			addBlock( { x, y }, new GrassBlock());
		}
	}

	for (int x = 0; x < MAX_LEVEL_SIZE - 20; x++) {
		if (x % 15 == 1)
			addMultiblock( { x, 14 }, new Tree());
	}
	addEntity( { 600, 500 }, new RedStar());
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
			if (blocks[x][y]->isPassable()) {
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

void Map::drawMultiblocks() {
	View *camera = this->player->getCamera();
	for (int x = (camera->virtual_position.x - camera->virtual_size.x / 2)
			/ BLOCK_SIZE - 1 - MAX_MULTIBLOCK_STRUCTURE_SEARCH_RADIUS;
			x
					< (camera->virtual_position.x + camera->virtual_size.x / 2)
							/ BLOCK_SIZE + 1 + MAX_MULTIBLOCK_STRUCTURE_SEARCH_RADIUS; x++) {
		for (int y = (camera->virtual_position.y - camera->virtual_size.y / 2)
				/ BLOCK_SIZE - 1 - MAX_MULTIBLOCK_STRUCTURE_SEARCH_RADIUS;
				y
						< (camera->virtual_position.y
								+ camera->virtual_size.y / 2) / BLOCK_SIZE + 1 + MAX_MULTIBLOCK_STRUCTURE_SEARCH_RADIUS;
				y++) {
			if (x < 0 || x >= MAX_LEVEL_SIZE || y < 0 || y >= MAX_LEVEL_SIZE) {
				continue;
			}

			Block *currBlock_ = blocks[x][y];

			if (!currBlock_) {
				continue;
			}
			if (dynamic_cast<Multiblock*>(currBlock_) == NULL) {
				continue;
			}

			Multiblock *currBlock = (Multiblock*) currBlock_;

			DrawData info = { };
			info.position =
					(Vector2F(x, y) + 0.5f * currBlock->getSize().to2F())
							* BLOCK_SIZE;

			info.size = (float) (BLOCK_SIZE) * currBlock->getSize().to2F();

			info.origin = { 0.5, 0.5 };

			info.frame = 0;
			info.layer = 0;

			info.spriteID = currBlock->getSpriteId();
			GraphicManager::Draw(info, Views::PLAYER_CAM);
		}
	}
}

void Map::addMultiblock(Vector2I pos, Multiblock *block) {
	addBlock(pos, block);
	for (int x = 0; x < block->getSize().x; x++) {
		for (int y = 0; y < block->getSize().y; y++) {
			if (x == 0 && y == 0) {
				continue;
			}
			addBlock( { pos.x + x, pos.y + y }, new StructureBlock(block));
		}
	}
}

void Map::updateEntities() {
	for (Entity *ent : entities) {
		ent->Update();
	}
}
