#pragma once

#include "DirtBlock.h"
#include "GrassBlock.h"
#include "MultiblockStructures/Lantern.h"
#include "MultiblockStructures/Tree.h"
#include <map>

class Blocks {
public:
	// BLOCKS
	//-----------------------------------------------------
	static Block *DIRT_BLOCK;
	static Block *GRASS_BLOCK;
	//-----------------------------------------------------

	// Multiblocks
	//-----------------------------------------------------
	static Block *TREE;
	static Block *LANTERN;
	//-----------------------------------------------------

	// INIT PHASE
	//-----------------------------------------------------
	static bool isBlocksInitPhaseInProgres();
	static void finishBlocksInitPhase();
	static void registerBlock(int id, Block* block);
	static void LOAD_ALL_BLOCKS();
	//-----------------------------------------------------

	// GETTERS AND SETTERS
	//-----------------------------------------------------
	static void collectOnlyBlocks(void (*consumer(Block* block))); //! �������� �������� ������� �� ����� �������, �� � �������������
	static void collectOnlyMultiblocks(void (*consumer(Multiblock* block))); //! �������� �������� ������� �� ����� �������������.
	static int getBlocksDatabaseSize();
	static Block* createBlock(int id); //! ������� ����� ���� �� ��������� id
	//-----------------------------------------------------

	// DELETE ALL BLOCKS
	//-----------------------------------------------------
	static void DELETE_ALL_BLOCKS();
	//-----------------------------------------------------

	static std::map<int, Block*> ALL_BLOCKS;

private:

	static bool blocksInitPhaseInProgres;
};
