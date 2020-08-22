#include "Map.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iterator>

#include "../../Engine/Colliders/Collider.h"
#include "../../Engine/Colliders/SquareCollider.h"
#include "../../Engine/Debugger/Debugger.h"
#include "../../Engine/Graphics/DrawData.h"
#include "../../Engine/Graphics/GraphicManager.h"
#include "../../Engine/Graphics/ShaderManagment/LightManager/LightManager.h"
#include "../../Engine/Utility/Coordinate.h"
#include "../Blocks/DirtBlock.h"
#include "../Blocks/GrassBlock.h"
#include "../Blocks/MultiblockStructures/Lantern.h"
#include "../Blocks/MultiblockStructures/Multiblock.h"
#include "../Blocks/MultiblockStructures/StructureBlock.h"
#include "../Blocks/MultiblockStructures/Tree.h"
#include "../Player/Player.h"
#include "../Textures.h"
#include "../Views.h"
#include "Level.h"

class Multiblock;

void Map::setLevel(Level *level) {
	this->level = level;
}

Level* Map::getLevel() {
	return this->level;
}

void Map::addBlock(Vector2I pos, Block *block) {
	if (blocks[pos.x][pos.y] != NULL) {
		delete blocks[pos.x][pos.y];
	}
	this->blocks[pos.x][pos.y] = block;
}

template<typename T>
void Map::collectEntities(void inv(T *ent)) {
	for (int i = 0; i < this->entities.size(); i++) {
		if (dynamic_cast<T*>(entities[i]) != NULL) {
			inv(entities[i]);
		}
	}
}

void Map::Init() {
	this->level->generate(this);
	this->player = new Player();
	player->Init(nullptr);
	this->addEntity( { 1500, 800 }, this->player);

	GraphicManager::SetLayerShader(1, &currentShader);

	// WIREFRAME
	for (int x = 0; x < MAX_LEVEL_SIZE; x++) {
		for (int y = 0; y < MAX_LEVEL_SIZE; y++) {
			colliders_wireframe[x][y] = new SquareCollider();
			colliders_wireframe[x][y]->Init(Vector2F(x, y) * BLOCK_SIZE,
					Vector2F(1, 1) * BLOCK_SIZE);
		}
	}

	genTestStuff();
	LightManager::SetView(this->player->getCamera());
	printf("Map created!\n");
}

void Map::Update() {
	if (!is_paused) {
		updateWallblocks();
		updateBlocks();
		updateEntities();
	}
	if (!ignoreLight) {
		drawLight();
	}
	if (mayDrawBackground) {
		drawBackground();
	}
	drawWallblocks();
	drawBlocks();
	drawMultiblocks();
	drawEntities();
	if (mayDrawGrid) {
		drawGrid();
	}
}

void Map::Destroy() {
	LightManager::ClearLightSource();
	for (int x = 0; x < MAX_LEVEL_SIZE; x++) {
		for (int y = 0; y < MAX_LEVEL_SIZE; y++) {
			delete colliders_wireframe[x][y];
			delete blocks[x][y];
			delete wallblocks[x][y];

			blocks[x][y] = NULL;
			wallblocks[x][y] = NULL;
			colliders_wireframe[x][y] = NULL;
		}
	}
	for (unsigned i = 0; i < entities.size(); i++) {
		entities[i]->Destroy();
		delete entities[i];
	}
	entities.clear();
	player = NULL;
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
	View *camera = GraphicManager::GetView(this->player->getCamera());
	int startx = (camera->virtual_position.x - camera->virtual_size.x / 2)
			/ BLOCK_SIZE - 1;
	int starty = (camera->virtual_position.y - camera->virtual_size.y / 2)
			/ BLOCK_SIZE - 1;

	int endx = (camera->virtual_position.x + camera->virtual_size.x / 2)
			/ BLOCK_SIZE + 1;
	int endy = (camera->virtual_position.y + camera->virtual_size.y / 2)
			/ BLOCK_SIZE + 1;

	for (int x = startx; x < endx; x++) {
		for (int y = starty; y < endy; y++) {
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

			info.layer = 1;

			info.frame = 0;

			info.spriteID = currBlock->getSpriteId();
			GraphicManager::Draw(info, this->player->getCamera());
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

	info.size.x = 1600;
	info.size.y = 900;

	info.origin = { 0.5, 0.5 };

	info.frame = 0;
	info.layer = 1;

	info.spriteID = Textures::TEST_BACKGROUND;
	GraphicManager::Draw(info, this->player->getCamera());
}

void Map::updateBlocks() {
	View *camera = GraphicManager::GetView(this->player->getCamera());

	//----------------------------------------------------------------------------
	int startx = (camera->virtual_position.x - camera->virtual_size.x / 2)
			/ BLOCK_SIZE - 1;
	int starty = (camera->virtual_position.y - camera->virtual_size.y / 2)
			/ BLOCK_SIZE - 1;

	int endx = (camera->virtual_position.x + camera->virtual_size.x / 2)
			/ BLOCK_SIZE + 1;
	int endy = (camera->virtual_position.y + camera->virtual_size.y / 2)
			/ BLOCK_SIZE + 1;
	//----------------------------------------------------------------------------

	// UPDATE
	//----------------------------------------------------------------------------
	for (int x = startx; x < endx; x++) {
		for (int y = starty; y < endy; y++) {
			if (x < 0 || x >= MAX_LEVEL_SIZE || y < 0 || y >= MAX_LEVEL_SIZE) {
				continue;
			}
			if (blocks[x][y]) {
				blocks[x][y]->Update();
			}
		}
	}
	//----------------------------------------------------------------------------
}

void Map::genTestStuff() {
	for (int x = 0; x < MAX_LEVEL_SIZE; x++) {
		for (int y = 0; y < MAX_LEVEL_SIZE; y++) {
			addWallblock(Vector2I(x, y), new DirtBlock());
		}
	}
	for (int y = 0; y < 14; y++) {
		for (int x = 0; x < MAX_LEVEL_SIZE; x++) {
			addBlock(Vector2I(x, y), new DirtBlock());
		}
	}
	for (int y = 10; y < 14; y++) {
		for (int x = 0; x < MAX_LEVEL_SIZE; x++) {
			int token = rand() % 3;
			if (token == 1 || token == 2)
				addBlock(Vector2I(x, y), new GrassBlock());
		}
	}
	for (int y = 13; y < 14; y++) {
		for (int x = 0; x < MAX_LEVEL_SIZE; x++) {
			addBlock(Vector2I(x, y), new GrassBlock());
		}
	}

	// TREES
	for (int x = 0; x < MAX_LEVEL_SIZE - 20; x++) {
		if (x % 15 == 0) {
			if (x % 2 == 0) {
				addMultiblock( { x, 14 }, new Lantern());
			} else {
				addMultiblock( { x, 14 }, new Tree());
			}
		}
	}
}

float Map::testCollision(SquareCollider *col, Vector2F dir) {
	float dir_len = dir.Magnitude();
	float result = 10000000.0f;

	for (int y = (col->GetPos().y - 1 * col->GetSize().y - dir_len) / BLOCK_SIZE
			- 1;
			y
					< (col->GetPos().y + 1 * col->GetSize().y + dir_len)
							/ BLOCK_SIZE + 1; y++) {
		for (int x = (col->GetPos().x - 1 * col->GetSize().x - dir_len)
				/ BLOCK_SIZE - 1;
				x
						< (col->GetPos().x + 1 * col->GetSize().x + dir_len)
								/ BLOCK_SIZE + 1; x++) {

			if (x < 0 || x >= MAX_LEVEL_SIZE || y < 0 || y >= MAX_LEVEL_SIZE) {
				continue;
			}

			if (blocks[x][y] == NULL) {
				continue;
			}
			if (blocks[x][y]->isPassable()) {
				continue;
			}

			// DEBUG
			//------------------------------
			//Debugger::DrawSquareCollider(bl, 10, 4, this->player->getCamera());
			//Debugger::DrawLine(bl.getPos(), col->getPos(), 4, this->player->getCamera(),
			//		Color::Red());
			//------------------------------

			float dist = Collider::DistanceBetween(col,
					colliders_wireframe[x][y], dir);

			if (!std::isnan(dist)) {
				if (dist >= 0.0f) {
					result = std::min(result, dist);
				}
			}
		}
	}

	return result;
}

void Map::drawMultiblocks() {
	View *camera = GraphicManager::GetView(this->player->getCamera());
	int startx = (camera->virtual_position.x - camera->virtual_size.x / 2)
			/ BLOCK_SIZE - 1;
	int starty = (camera->virtual_position.y - camera->virtual_size.y / 2)
			/ BLOCK_SIZE - 1;

	int endx = (camera->virtual_position.x + camera->virtual_size.x / 2)
			/ BLOCK_SIZE + 1;
	int endy = (camera->virtual_position.y + camera->virtual_size.y / 2)
			/ BLOCK_SIZE + 1;

	for (int x = startx - MULTIBLOCK_STRUCTURE_SEARCH_RADIUS;
			x < endx + MULTIBLOCK_STRUCTURE_SEARCH_RADIUS; x++) {
		for (int y = starty - MULTIBLOCK_STRUCTURE_SEARCH_RADIUS;
				y < endy + MULTIBLOCK_STRUCTURE_SEARCH_RADIUS; y++) {
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
			info.layer = 1;

			info.spriteID = currBlock->getSpriteId();
			GraphicManager::Draw(info, this->player->getCamera());
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
			addBlock(Vector2I(pos.x + x, pos.y + y), new StructureBlock(block));
		}
	}
}

void Map::pauseGame() {
	is_paused = true;
}

void Map::unpauseGame() {
	is_paused = false;
}

bool Map::isPaused() {
	return is_paused;
}

void Map::addWallblock(Vector2I pos, Block *block) {
	this->wallblocks[pos.x][pos.y] = block;
}

Block* Map::getBlock(Vector2F pos) {
	int x = pos.x / BLOCK_SIZE;
	int y = pos.y / BLOCK_SIZE;
	if (x < 0 || x >= MAX_LEVEL_SIZE || y < 0 || y >= MAX_LEVEL_SIZE) {
		return NULL;
	}
	return blocks[x][y];
}

Block* Map::getWallblock(Vector2F pos) {
	int x = pos.x / BLOCK_SIZE;
	int y = pos.y / BLOCK_SIZE;
	if (x < 0 || x >= MAX_LEVEL_SIZE || y < 0 || y >= MAX_LEVEL_SIZE) {
		return NULL;
	}
	return wallblocks[x][y];
}

void Map::updateEntities() {
	for (Entity *ent : entities) {
		ent->Update();
	}
}

void Map::drawWallblocks() {
	View *camera = GraphicManager::GetView(this->player->getCamera());

	int startx = (camera->virtual_position.x - camera->virtual_size.x / 2)
			/ BLOCK_SIZE - 1;
	int starty = (camera->virtual_position.y - camera->virtual_size.y / 2)
			/ BLOCK_SIZE - 1;

	int endx = (camera->virtual_position.x + camera->virtual_size.x / 2)
			/ BLOCK_SIZE + 1;
	int endy = (camera->virtual_position.y + camera->virtual_size.y / 2)
			/ BLOCK_SIZE + 1;

	for (int x = startx; x < endx; x++) {
		for (int y = starty; y < endy; y++) {
			if (x < 0 || x >= MAX_LEVEL_SIZE || y < 0 || y >= MAX_LEVEL_SIZE) {
				continue;
			}

			Block *currBlock = wallblocks[x][y];

			if (!currBlock) {
				continue;
			}
			if (dynamic_cast<Multiblock*>(currBlock) != NULL) {
				continue;
			}

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
			info.layer = 1;

			// TODO
			//info.color.b = info.color.r = info.color.g = 255.0f * 0.5f;
			//????????

			info.spriteID = currBlock->getSpriteId();
			GraphicManager::Draw(info, this->player->getCamera());
		}
	}
}

void Map::setPlayersView(unsigned view) {
	player->setCamera(view);
}

bool Map::isIgnoreLight() const {
	return ignoreLight;
}

void Map::setIgnoreLight(bool ignoreLight) {
	this->ignoreLight = ignoreLight;
}

void Map::drawGrid() {
	View *camera = GraphicManager::GetView(this->player->getCamera());
	int startx = (camera->virtual_position.x - camera->virtual_size.x / 2)
			/ BLOCK_SIZE - 1;
	int starty = (camera->virtual_position.y - camera->virtual_size.y / 2)
			/ BLOCK_SIZE - 1;

	int endx = (camera->virtual_position.x + camera->virtual_size.x / 2)
			/ BLOCK_SIZE + 1;
	int endy = (camera->virtual_position.y + camera->virtual_size.y / 2)
			/ BLOCK_SIZE + 1;

	for (int x = startx; x < endx; x++) {
		for (int y = starty; y < endy; y++) {
			if (x < 0 || x >= MAX_LEVEL_SIZE || y < 0 || y >= MAX_LEVEL_SIZE) {
				continue;
			}

			Block *currBlock = blocks[x][y];

			float x0 = x * BLOCK_SIZE;
			float y0 = y * BLOCK_SIZE;

			float x1 = (x + 1) * BLOCK_SIZE;
			float y1 = (y + 1) * BLOCK_SIZE;

			float th = 2;
			Color co = { 0, 0, 0 };

			if (currBlock != NULL
					&& (dynamic_cast<StructureBlock*>(currBlock) != NULL
							|| dynamic_cast<Multiblock*>(currBlock) != NULL)) {
				co.r = 255;
			}

			Debugger::DrawLine( { x0, y0 }, { x0, y1 }, th,
					this->player->getCamera(), co);
			Debugger::DrawLine( { x0, y0 }, { x1, y0 }, th,
					this->player->getCamera(), co);
			Debugger::DrawLine( { x1, y1 }, { x0, y1 }, th,
					this->player->getCamera(), co);
			Debugger::DrawLine( { x1, y1 }, { x1, y0 }, th,
					this->player->getCamera(), co);
		}
	}
}

void Map::addBlock(Vector2F pos, Block *block) {
	Vector2I grid_pos = getGridCoords(pos);

	if (grid_pos.x == -1) {
		return;
	}

	if (getBlockFromMesh(grid_pos) != NULL) {
		return;
	}

	addBlock(grid_pos, block);
}

Vector2I Map::getGridCoords(Vector2F pos) {
	int x = pos.x / BLOCK_SIZE;
	int y = pos.y / BLOCK_SIZE;
	if (x < 0 || x >= MAX_LEVEL_SIZE || y < 0 || y >= MAX_LEVEL_SIZE) {
		return {-1, -1};
	}
	return {x, y};
}

void Map::drawLight() {
	View *camera = GraphicManager::GetView(this->player->getCamera());
	int startx = (camera->virtual_position.x - camera->virtual_size.x / 2)
			/ BLOCK_SIZE - 1;
	int starty = (camera->virtual_position.y - camera->virtual_size.y / 2)
			/ BLOCK_SIZE - 1;

	int endx = (camera->virtual_position.x + camera->virtual_size.x / 2)
			/ BLOCK_SIZE + 1;
	int endy = (camera->virtual_position.y + camera->virtual_size.y / 2)
			/ BLOCK_SIZE + 1;
	LightManager::ClearLightSource();

	for (int x = startx - LIGHT_SOURCE_SEARCH_RADIUS;
			x < endx + LIGHT_SOURCE_SEARCH_RADIUS; x++) {
		for (int y = starty - LIGHT_SOURCE_SEARCH_RADIUS;
				y < endy + LIGHT_SOURCE_SEARCH_RADIUS; y++) {
			if (x < 0 || x >= MAX_LEVEL_SIZE || y < 0 || y >= MAX_LEVEL_SIZE) {
				continue;
			}

			Block *currBlock = blocks[x][y];

			if (currBlock == NULL) {
				continue;
			}

			FAST_CAST(currBlock, LightSource, {
					if (casted->getLightRadius() != 0) {
						LightData data = {};
						data.pos = Vector2F(x, y) * BLOCK_SIZE;
						data.color = Color(255, 255, 255);
						data.full_dist = casted->getLightRadius() * BLOCK_SIZE;
						data.any_dist = 50;
						data.softness = 1;
						LightManager::AddLightSource(data);
			}});
		}
	}

}

void Map::updateWallblocks() {
	View *camera = GraphicManager::GetView(this->player->getCamera());

	//----------------------------------------------------------------------------
	int startx = (camera->virtual_position.x - camera->virtual_size.x / 2)
			/ BLOCK_SIZE - 1;
	int starty = (camera->virtual_position.y - camera->virtual_size.y / 2)
			/ BLOCK_SIZE - 1;

	int endx = (camera->virtual_position.x + camera->virtual_size.x / 2)
			/ BLOCK_SIZE + 1;
	int endy = (camera->virtual_position.y + camera->virtual_size.y / 2)
			/ BLOCK_SIZE + 1;
	//----------------------------------------------------------------------------

	// UPDATE
	//----------------------------------------------------------------------------
	for (int x = startx; x < endx; x++) {
		for (int y = starty; y < endy; y++) {
			if (x < 0 || x >= MAX_LEVEL_SIZE || y < 0 || y >= MAX_LEVEL_SIZE) {
				continue;
			}
			if (wallblocks[x][y]) {
				wallblocks[x][y]->Update();
			}
		}
	}
	//----------------------------------------------------------------------------
}

bool Map::isMayDrawGrid() const {
	return mayDrawGrid;
}

void Map::setMayDrawGrid(bool mayDrawGrid) {
	this->mayDrawGrid = mayDrawGrid;
}

bool Map::isMayDrawBackground() const {
	return mayDrawBackground;
}

void Map::setMayDrawBackground(bool mayDrawBackground) {
	this->mayDrawBackground = mayDrawBackground;
}
