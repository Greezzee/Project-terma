#include "Map.h"

#include <iterator>

#include "../Engine/Utility/Coordinate.h"
#include "Blocks/DirtBlock.h"
#include "Level.h"
#include "player/Player.h"

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
	this->addEntity({0, 0}, this->player);
	this->addBlock({1, 1},  new DirtBlock());
}

void Map::Update() {
	// Entities
	for (Entity *ent : entities) {
		ent->Update();
	}
	for (Entity *ent : entities) {
		ent->Draw();
	}

	// Blocks
	for (int i = 0; i < MAX_LEVEL_SIZE; i++) {
		for (int j = 0; j < MAX_LEVEL_SIZE; j++) {
			if (blocks[i][j])
				blocks[i][j]->Update();
		}
	}
}

void Map::Destroy() {
}

void Map::addEntity(Vector2F pos, Entity *entity) {
	entity->SetPos( { pos.x, pos.y });
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
