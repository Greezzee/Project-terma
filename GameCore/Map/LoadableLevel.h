#pragma once

#include <string>

#include "Level.h"

const std::string TEST_ROOM = "new_level.PTRoom";

class LoadableLevel : public Level {
	std::string level_directory;
public:
	//LoadableLevel();
	LoadableLevel(std::string _path);

	void generate(Map* _map) override;

	~LoadableLevel() {}
};
