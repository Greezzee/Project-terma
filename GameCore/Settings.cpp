#include "Settings.h"

#include <bits/types/FILE.h>
#include <cstdio>
#include <iostream>

#include "../Engine/Graphics/GraphicManager.h"
#include "../Engine/Utility/Coordinate.h"
#include "Views.h"

Vector2U Settings::resolution = { 0, 0 };

Settings::Settings() {
	resolution = { 0, 0 };
}

void Settings::LOAD_SETTINGS() {
	char temp_string[256] = {};

	FILE *settings_file = freopen("./settings.cfg", "r", stdin);

	if (settings_file == nullptr) {
		std::cerr << "Failed to open the settings.cfg file" << std::endl;
		return;
	}

	// RESOLUTION SETTINGS
	scanf("RESOLUTION=%ux%u\n", &resolution.x, &resolution.y);
	GraphicManager::SetResolution(resolution);
	Views::SET_RESOLUTION(resolution);

	// CONTROLS SETTINGS
	scanf("CONTROLS:\n");
	for (unsigned i = 0; i < keys_number; i++) {
		unsigned int game_key = 0;
		unsigned int keyboard_key = 0;

		scanf("%u=%u\n", &game_key, &keyboard_key);
		Controls::linking[game_key] = static_cast<KeyboardKey>(keyboard_key);
	}

	fclose(settings_file);
}

void Settings::SAVE_SETTINGS() {
	FILE *settings_file = fopen("./settings.cfg", "w");

	if (settings_file == nullptr) {
		std::cerr << "Failed to open the settings.cfg file" << std::endl;
		return;
	}

	// RESOLUTION
	resolution = GraphicManager::GetResolution();
	fprintf(settings_file, "RESOLUTION=%ux%u\n", resolution.x, resolution.y);

	// CONTROLS
	for (int i = 0; i < keys_number; i++) {
		fprintf(settings_file, "%u=%u\n", i, Controls::linking[i]);
	}

	fclose(settings_file);
}

Settings::~Settings() {
}
