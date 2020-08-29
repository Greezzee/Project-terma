#include "Blocks.h"

#include "../ProjectTerma.h"

Block *Blocks::DIRT_BLOCK = nullptr;
Block *Blocks::GRASS_BLOCK = nullptr;

Block *Blocks::LANTERN = nullptr;
Block *Blocks::TREE = nullptr;

bool Blocks::blocksInitPhaseInProgres = true;
std::map<int, Block*> Blocks::ALL_BLOCKS = { };

bool Blocks::isBlocksInitPhaseInProgres() {
	return blocksInitPhaseInProgres;
}

void Blocks::finishBlocksInitPhase() {
	blocksInitPhaseInProgres = false;
}

void Blocks::LOAD_ALL_BLOCKS() {
	DIRT_BLOCK = new DirtBlock();
	GRASS_BLOCK = new GrassBlock();

	LANTERN = new Lantern();
	TREE = new Tree();

	finishBlocksInitPhase();
}

void Blocks::registerBlock(int id, Block *block) {
	if (ALL_BLOCKS.count(id) > 0) {
		ProjectTerma::report_error("Block is trying to init again!");
	}

	ALL_BLOCKS[id] = block;
}

void Blocks::collectOnlyBlocks(void (* consumer(Block *block))) {for (auto it = ALL_BLOCKS.begin(); it != ALL_BLOCKS.end(); it++) {
	Block * bl = it->second;
	if (dynamic_cast<Multiblock*>(bl) == nullptr) {
		consumer(bl);
	}
}
}

void Blocks::collectOnlyMultiblocks(void (* consumer(Multiblock *block))) {for (auto it = ALL_BLOCKS.begin(); it != ALL_BLOCKS.end(); it++) {
	Block * bl = it->second;
	Multiblock * mbl = nullptr;
	if ((mbl = dynamic_cast<Multiblock*>(bl)) != nullptr) {
		consumer(mbl);
	}
}
}

int Blocks::getBlocksDatabaseSize() {
	return ALL_BLOCKS.size();
}

Block* Blocks::createBlock(int id) {
	return (Block*) ALL_BLOCKS[id]->Clone();
}

void Blocks::DELETE_ALL_BLOCKS() {
	delete DIRT_BLOCK;
	delete GRASS_BLOCK;

	delete LANTERN;
	delete TREE;
}
