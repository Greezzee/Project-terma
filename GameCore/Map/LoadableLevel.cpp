#include "LoadableLevel.h"

#include "../../Engine/Utility/Coordinate.h"
#include "../LevelCoder/LevelCoder.h"
#include "Map.h"

/*
LoadableLevel::LoadableLevel() {

}
*/

LoadableLevel::LoadableLevel(std::string _path)
{
	level_directory = _path;
}

void LoadableLevel::generate(Map *_map)
{
	std::string _name = level_directory + "/" + TEST_ROOM;
	LevelCoder::DECODE(_name, _map, Vector2I(0, 0));
}
