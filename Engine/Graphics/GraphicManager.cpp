#pragma once
#include "GraphicManager.h"
#include "../Time/TimeManager.h"
sf::RenderWindow GraphicManager::window;
std::vector<sf::Sprite> GraphicManager::sprites;
std::vector<std::list<sf::Sprite>> GraphicManager::to_draw;
std::vector<sf::Texture> GraphicManager::textures;

std::vector<View> GraphicManager::views;
const unsigned GraphicManager::LAYER_COUNT = 20;

void GraphicManager::Init()
{
	window.create(sf::VideoMode(1600, 900), "Test");
	//window.setFramerateLimit(65);

	sprites.resize(SPRITES_COUNT);
	textures.resize(SPRITES_COUNT);
	to_draw.resize(LAYER_COUNT);

	views.resize(VIEWS_COUNT);
	views[Views::BASIC] = { {1600, 900}, {1600, 900}, {0, 0} };
	views[Views::TEST] = { {1600, 900}, {800, 450}, {100, 100} };

	// TODO а вот тут нужно прописывать загрузку текстур

	for (int i = 0; i < SPRITES_COUNT; i++) {
		sprites[i].setTexture(textures[i]);
	}
}

bool GraphicManager::Update()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			return true;
	}

	window.clear();
	
	for (int i = 0; i < LAYER_COUNT; i++) {
		for (auto obj = to_draw[i].begin(); obj != to_draw[i].end(); obj++) {
			window.draw(*obj);
		}
		to_draw[i].clear();
	}
	
	window.display();
	return false;
}

void GraphicManager::Exit()
{
	window.close();
}

void GraphicManager::Draw(DrawData& data, Views view_id)
{
	SetView(data, view_id);
	sprites[data.spriteID].setPosition(sf::Vector2f(data.position.x, data.position.y));
	sprites[data.spriteID].setRotation(data.rotation);
	sprites[data.spriteID].setOrigin(sf::Vector2f(data.origin.x, data.origin.y));
	sprites[data.spriteID].setScale(sf::Vector2f(data.scale.x, data.scale.y));
	to_draw[data.layer].push_back(sprites[data.spriteID]);
	
}

void GraphicManager::SetView(DrawData& data, Views view_id)
{
	View& view = views[view_id];
	data.position = view.position + data.position * view.real_size / view.virtual_size;
	data.scale = data.scale * view.real_size / view.virtual_size;
}
