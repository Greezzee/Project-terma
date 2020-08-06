#pragma once

#include "DirtBlock.h"
#include "GrassBlock.h"
#include "multiblockStructures/Lantern.h"
#include "multiblockStructures/Tree.h"

const Block * DIRT_BLOCK = new DirtBlock();
const Block * GRASS_BLOCK = new GrassBlock();

const Block * TREE = new Tree();
const Block * LANTERN = new Lantern();
