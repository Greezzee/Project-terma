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
	FILE *settings_file = freopen("./settings.cfg", "r", stdin);

	if (settings_file == nullptr) {
		std::cerr << "Failed to open the settings.cfg file" << std::endl;
		return;
	}

	// RESOLUTION SETTINGS
	if (scanf("RESOLUTION=%ux%u\n", &resolution.x, &resolution.y) != 2) {
		// ERROR
		std::cerr << "Error loading resolution! Loading default settings...\n"
				<< std::endl;
		LOAD_DEFAULT();
		return;
	}
	GraphicManager::SetResolution(resolution);
	Views::SET_RESOLUTION(resolution);

	// CONTROLS SETTINGS
	scanf("CONTROLS:\n");
	for (unsigned i = 0; i < keys_number; i++) {
		unsigned int game_key = 0;
		unsigned int keyboard_key = 0;

		if (scanf("%u=%u\n", &game_key, &keyboard_key) != 2) {
			// ERROR
			std::cerr << "Error loading controls! Loading default settings...\n" << std::endl;
			LOAD_DEFAULT();
			return;
		}

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
	for (unsigned i = 0; i < keys_number; i++) {
		fprintf(settings_file, "%u=%u\n", i, Controls::linking[i]);
	}

	fclose(settings_file);
}

void Settings::LOAD_DEFAULT() {
	// RESOLUTION
	GraphicManager::SetResolution(default_resolution);
	Views::SET_RESOLUTION(default_resolution);

	// CONTROLS
	for (unsigned i = 0; i < keys_number; i++) {
		Controls::linking[i] = default_linking[i];
	}
}

Settings::~Settings() {
}
