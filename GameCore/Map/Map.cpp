#include "Map.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
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
#include "../ProjectTerma.h"
#include "../PTC.h"
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
	this->addEntity( { 1500 / 40 * BLOCK_SIZE, 800 / 40 * BLOCK_SIZE },
			this->player);

	for (int i = 1; i < MAX_LAYER; i++) {
		GraphicManager::SetLayerShader(i, &currentShader);
	}

	// WIREFRAME
	for (int x = 0; x < MAX_LEVEL_SIZE; x++) {
		for (int y = 0; y < MAX_LEVEL_SIZE; y++) {
			colliders_wireframe[x][y] = new SquareCollider();
			colliders_wireframe[x][y]->Init(Vector2F(x, y) * BLOCK_SIZE,
					Vector2F(1, 1) * BLOCK_SIZE);
		}
	}

	genTestStuff();
	setPlayersView(Views::PLAYER_CAM);
	LightManager::SetGlobalLight(Color(0, 0, 0));

	PTC::sayCreated("Map");
}

void Map::Update() {
	if (!ignoreLight) {
		LightManager::ClearLightSource();
	} else {
		LightManager::SetGlobalLight(Color(255, 255, 255));
	}

	updateWallblocks();
	updateBlocks();
	updateEntities();

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

	for (int i = 1; i < MAX_LAYER; i++) {
		GraphicManager::SetLayerShader(i, NULL);
	}

	PTC::sayDestroyed("Destroyed");
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

			info.layer = BLOCKS_LAYER;

			info.frame = 0;

			info.spriteID = currBlock->getSpriteId();
			GraphicManager::Draw(info, this->player->getCamera());
		}
	}
}

void Map::drawEntities() {
	for (Entity *ent : entities) {
		ent->Draw();
		SolidEntity *sent = NULL;
		if (mayDrawColliders && (sent = dynamic_cast<SolidEntity*>(ent)) != NULL) {
			Debugger::DrawCollider(*sent->getCollider(), 2, 2,
					player->getCamera(), Color(0, 255, 0), COLLIDERS_LAYER);
		}
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
	info.layer = BACKGROUND_LAYER;

	info.spriteID = Textures::TEST_BACKGROUND;
	GraphicManager::Draw(info, this->player->getCamera());
}

void Map::updateBlocks() {
	View *camera = GraphicManager::GetView(this->player->getCamera());

	//----------------------------------------------------------------------------
	int startx = (camera->virtual_position.x - camera->virtual_size.x / 2)
			/ BLOCK_SIZE - 1 - BLOCKS_UPDATE_SEARCH_RADIUS;
	int starty = (camera->virtual_position.y - camera->virtual_size.y / 2)
			/ BLOCK_SIZE - 1 - BLOCKS_UPDATE_SEARCH_RADIUS;

	int endx = (camera->virtual_position.x + camera->virtual_size.x / 2)
			/ BLOCK_SIZE + 1 + BLOCKS_UPDATE_SEARCH_RADIUS;
	int endy = (camera->virtual_position.y + camera->virtual_size.y / 2)
			/ BLOCK_SIZE + 1 + BLOCKS_UPDATE_SEARCH_RADIUS;
	//----------------------------------------------------------------------------

	// UPDATE
	//----------------------------------------------------------------------------
	for (int x = startx; x < endx; x++) {
		for (int y = starty; y < endy; y++) {
			if (x < 0 || x >= MAX_LEVEL_SIZE || y < 0 || y >= MAX_LEVEL_SIZE) {
				continue;
			}

			if (blocks[x][y]) {
				LightSource *lgt = dynamic_cast<LightSource*>(blocks[x][y]);
				if (lgt != NULL && lgt->getLightRadius() != 0) {
					LightData data = { };
					data.pos = Vector2F(x, y);

					Multiblock *mlt = dynamic_cast<Multiblock*>(blocks[x][y]);
					if (mlt != NULL) {
						Vector2F size = mlt->getSize().to2F();
						data.pos += ((size) / 2.0f);
					}

					data.pos = data.pos * BLOCK_SIZE;
					data.color = Color(255, 255, 255);
					data.full_dist = lgt->getLightRadius() * BLOCK_SIZE / 2;
					data.any_dist = lgt->getLightRadius() * BLOCK_SIZE;
					data.softness = 1;
					if (!ignoreLight) {
						LightManager::AddLightSource(data);
					}
				}
				if (!is_paused) {
					blocks[x][y]->Update();
				}
			}
		}
	}

	//----------------------------------------------------------------------------
}

void Map::genTestStuff() {
	for (int x = 0; x < MAX_LEVEL_SIZE; x++) {
		for (int y = 0; y < MAX_LEVEL_SIZE; y++) {
			placeWallblock(Vector2I(x, y), new DirtBlock());
		}
	}
	for (int y = 0; y < 14; y++) {
		for (int x = 0; x < MAX_LEVEL_SIZE; x++) {
			placeBlock(Vector2I(x, y), new DirtBlock());
		}
	}
	for (int y = 10; y < 14; y++) {
		for (int x = 0; x < MAX_LEVEL_SIZE; x++) {
			int token = rand() % 3;
			if (token == 1 || token == 2)
				replaceWithBlock(Vector2I(x, y), new GrassBlock());
		}
	}
	for (int y = 13; y < 14; y++) {
		for (int x = 0; x < MAX_LEVEL_SIZE; x++) {
			replaceWithBlock(Vector2I(x, y), new GrassBlock());
		}
	}

	// TREES
	for (int x = 0; x < MAX_LEVEL_SIZE - 20; x++) {
		if (x % 15 == 0) {
			if (x % 2 == 0) {
				replaceWithMultiblock( { x, 14 }, new Lantern());
			} else {
				replaceWithMultiblock( { x, 14 }, new Tree());
			}
		}
	}
}

float Map::testCollision(SquareCollider *col, Vector2F dir) {
	float dir_len = dir.Magnitude();
	float result = 10000000.0f;

	if (mayDrawColliders) {
		Debugger::DrawLine(player->GetPos(),
				player->GetPos() + dir.Normalized() * 4 * BLOCK_SIZE, 5,
				player->getCamera(), Color(0, 0, 255), COLLIDERS_LAYER);
	}

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

			float dist = Collider::DistanceBetween(col,
					colliders_wireframe[x][y], dir);

			if (!std::isnan(dist)) {
				if (dist >= 0.0f) {
					result = std::min(result, dist);
					// DEBUG
					//------------------------------
					if (mayDrawColliders) {
						Debugger::DrawCollider(*colliders_wireframe[x][y], 10,
								4, this->player->getCamera(), Color(255, 0, 0),
								COLLIDERS_LAYER);
					}
					//------------------------------
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
			info.layer = 3;

			info.spriteID = currBlock->getSpriteId();
			GraphicManager::Draw(info, this->player->getCamera());
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
	if (is_paused) {
		return;
	}
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
			info.layer = WALLBLOCKS_LAYER;

			// TODO
			//info.color.b = info.color.r = info.color.g = 255.0f * 0.5f;
			//????????

			if (mayDrawWallBlockCrosses) {

				Debugger::DrawLine(info.position - Vector2F(BLOCK_SIZE, BLOCK_SIZE) * 0.4, info.position + Vector2F(BLOCK_SIZE, BLOCK_SIZE) * 0.4, 2, player->getCamera(), Color(0, 255, 0), WALLBLOCKS_CROSSES_LAYER);
				Debugger::DrawLine(info.position - Vector2F(-BLOCK_SIZE, BLOCK_SIZE) * 0.4, info.position + Vector2F(-BLOCK_SIZE, BLOCK_SIZE) * 0.4, 2, player->getCamera(), Color(0, 255, 0), WALLBLOCKS_CROSSES_LAYER);

			}

			info.spriteID = currBlock->getSpriteId();
			GraphicManager::Draw(info, this->player->getCamera());
		}
	}
}

void Map::setPlayersView(unsigned view) {
	player->setCamera(view);
	LightManager::SetView(this->player->getCamera());
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

			int layer = GRID_LAYER;

			if (currBlock != NULL
					&& (dynamic_cast<StructureBlock*>(currBlock) != NULL
							|| dynamic_cast<Multiblock*>(currBlock) != NULL)) {
				co.r = 255;
				layer = MULTIBLOCKS_GRID_LAYER;
			}

			Debugger::DrawLine( { x0, y0 }, { x0, y1 }, th,
					this->player->getCamera(), co, layer);
			Debugger::DrawLine( { x0, y0 }, { x1, y0 }, th,
					this->player->getCamera(), co, layer);
			Debugger::DrawLine( { x1, y1 }, { x0, y1 }, th,
					this->player->getCamera(), co, layer);
			Debugger::DrawLine( { x1, y1 }, { x1, y0 }, th,
					this->player->getCamera(), co, layer);
		}
	}
}

Vector2I Map::getGridCoords(Vector2F pos) {
	int x = pos.x / BLOCK_SIZE;
	int y = pos.y / BLOCK_SIZE;
	if (!ensureInGrid( { x, y })) {
		return {-1, -1};
	}
	return {x, y};
}

bool Map::placeMultiblock(Vector2I pos, Multiblock *block) {
	if (!ensureInGrid(pos) || blocks[pos.x][pos.y] != NULL) {
		return 0;
	}

	for (int x = 0; x < block->getSize().x; x++) {
		for (int y = 0; y < block->getSize().y; y++) {
			if (blocks[pos.x + x][pos.y + y] != NULL
					|| !ensureInGrid(pos + Vector2I(x, y))) {
				return 0;
			}
		}
	}

	blocks[pos.x][pos.y] = block;

	for (int x = 0; x < block->getSize().x; x++) {
		for (int y = 0; y < block->getSize().y; y++) {
			if (x == 0 && y == 0) {
				continue;
			}

			blocks[x + pos.x][y + pos.y] = new StructureBlock(block);
		}
	}

	return 1;
}

bool Map::placeWallblock(Vector2I pos, Block *block) {
	if (!ensureInGrid(pos) || wallblocks[pos.x][pos.y] != NULL) {
		return 0;
	}

	wallblocks[pos.x][pos.y] = block;
	return 1;
}

bool Map::placeBlock(Vector2I pos, Block *block) {
	if (!ensureInGrid(pos) || blocks[pos.x][pos.y] != NULL) {
		return 0;
	}

	blocks[pos.x][pos.y] = block;
	return 1;
}

bool Map::replaceWithBlock(Vector2I pos, Block *block) {
	if (!ensureInGrid(pos)) {
		return 0;
	}

	if (blocks[pos.x][pos.y] != NULL) {
		delete blocks[pos.x][pos.y];
	}
	blocks[pos.x][pos.y] = block;
	return 1;
}

bool Map::replaceWithMultiblock(Vector2I pos, Multiblock *block) {
	if (!ensureInGrid(pos) || !ensureInGrid(pos + block->getSize())) {
		return 0;
	}
	for (int x = 0; x < block->getSize().x; x++) {
		for (int y = 0; y < block->getSize().y; y++) {
			removeBlock(pos + Vector2I(x, y));
		}
	}

	return placeMultiblock(pos, block);
}

bool Map::replaceWithWallBlock(Vector2I pos, Block *block) {
	if (!ensureInGrid(pos)) {
		return 0;
	}

	if (wallblocks[pos.x][pos.y] != NULL) {
		delete wallblocks[pos.x][pos.y];
	}
	wallblocks[pos.x][pos.y] = block;
	return 1;
}

bool Map::removeBlock(Vector2I pos) {
	if (!ensureInGrid(pos) || !blocks[pos.x][pos.y]) {
		return 0;
	}

	if (dynamic_cast<Multiblock*>(blocks[pos.x][pos.y]) != NULL
			|| dynamic_cast<StructureBlock*>(blocks[pos.x][pos.y]) != NULL) {
		return flushMutliblockStructure(pos);
	}

	delete blocks[pos.x][pos.y];
	blocks[pos.x][pos.y] = NULL;
	return 1;
}

bool Map::removeWallBlock(Vector2I pos) {
	if (!ensureInGrid(pos) || !wallblocks[pos.x][pos.y]) {
		return 0;
	}
	delete wallblocks[pos.x][pos.y];
	wallblocks[pos.x][pos.y] = NULL;
	return 1;
}

bool Map::ensureInGrid(Vector2I pos) {
	return (pos.x >= 0 && pos.y >= 0 && pos.x < MAX_LEVEL_SIZE
			&& pos.y < MAX_LEVEL_SIZE);
}

bool Map::flushMutliblockStructure(Vector2I pos_) {
	if (!ensureInGrid(pos_) || !blocks[pos_.x][pos_.y]) {
		return 0;
	}

	Vector2I pos = findStructureblockParent(pos_);
	Multiblock *mblock = dynamic_cast<Multiblock*>(blocks[pos.x][pos.y]);

	if (mblock == NULL) {
		return 0;
	}

	for (int x = 0; x < mblock->getSize().x; x++) {
		for (int y = 0; y < mblock->getSize().y; y++) {
			if (x == 0 && y == 0) {
				continue;
			}

			StructureBlock *sblock = dynamic_cast<StructureBlock*>(blocks[pos.x
					+ x][pos.y + y]);
			if (sblock == NULL) {
				ProjectTerma::report_error(
						"No structure block found in multiblock structure!");
			}
			delete sblock;
			blocks[x + pos.x][y + pos.y] = NULL;
		}
	}

	delete mblock;
	blocks[pos.x][pos.y] = NULL;

	return 1;
}

Vector2I Map::findStructureblockParent(Vector2I pos) {
	if (!ensureInGrid(pos) || !blocks[pos.x][pos.y]) {
		return {-1, -1};
	}

	StructureBlock *start = dynamic_cast<StructureBlock*>(blocks[pos.x][pos.y]);
	Multiblock *mblock = dynamic_cast<Multiblock*>(blocks[pos.x][pos.y]);
	if (mblock != NULL) {
		return pos;
	}
	if (start == NULL) {
		return {-1, -1};
	}

	Block *curr = start;
	StructureBlock *scurr = start;
	int x = pos.x;
	int y = pos.y;
	for (;
			((curr = blocks[x][y]) != NULL) && ((scurr =
					dynamic_cast<StructureBlock*>(curr)) != NULL)
					&& scurr->getParent() == start->getParent(); x--) {
	}
	x++;
	for (;
			((curr = blocks[x][y]) != NULL) && ((scurr =
					dynamic_cast<StructureBlock*>(curr)) != NULL)
					&& scurr->getParent() == start->getParent(); y--) {
	}

	return {x, y};
}

void Map::updateWallblocks() {
	if (is_paused) {
		return;
	}

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

bool Map::isMayDrawColliders() const {
	return mayDrawColliders;
}

void Map::setMayDrawColliders(bool mayDrawColliders) {
	this->mayDrawColliders = mayDrawColliders;
}

bool Map::isMayDrawWallBlockCrosses() const {
	return mayDrawWallBlockCrosses;
}

void Map::setMayDrawWallBlockCrosses(bool mayDrawWallBlockCrosses) {
	this->mayDrawWallBlockCrosses = mayDrawWallBlockCrosses;
}
