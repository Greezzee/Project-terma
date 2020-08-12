#pragma once

#include "DirtBlock.h"
#include "GrassBlock.h"
#include "MultiblockStructures/Lantern.h"
#include "MultiblockStructures/Tree.h"

const Block * DIRT_BLOCK = new DirtBlock();
const Block * GRASS_BLOCK = new GrassBlock();

const Block * TREE = new Tree();
const Block * LANTERN = new Lantern();
