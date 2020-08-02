#include "GraphicManager.h"
#include "../Time/TimeManager.h"

Vector2F GraphicManager::ConvertRealToView(Vector2F pos, Views view_id)
{
	View& view = views[view_id];
	pos -= view.real_position;
	pos += view.real_size * (view.unit_vector - Vector2F(1, 1));
	pos = pos / view.real_size * view.virtual_size / view.unit_vector;
	pos = pos + view.virtual_position - view.virtual_size / 2.f;
	return pos;
}


sf::RenderWindow GraphicManager::window;
std::vector<GraphicPrefab> GraphicManager::sprites;
std::vector<std::list<sf::Sprite>> GraphicManager::to_draw;
unsigned GraphicManager::_sprites_count;

std::vector<View> GraphicManager::views;
const unsigned GraphicManager::LAYER_COUNT = 20;

void GraphicManager::Init()
{
	window.create(sf::VideoMode(1024, 576), "Test");
	//window.setFramerateLimit(65);

	_sprites_count = 0;
	sprites.resize(0);
	to_draw.resize(LAYER_COUNT);

	views.resize(VIEWS_COUNT);
	views[Views::BASIC] = { {0, 0}, {1024, 576}, {0, 0}, {1024, 576}, {1, 1} };
	views[Views::TEST] = { {0, 0}, {1024, 576}, {0, 0}, {16, 9}, {1, 1}};
	views[Views::PLAYER_CAM] = { {0, 0}, {1024, 576}, {0, 0}, {1600, 900}, {1, -1}};
	views[Views::MAIN_MENU] = { {0, 0}, {1024, 576}, {800, 450}, {1600, 900}, {1, -1}};
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

bool GraphicManager::Draw(DrawData& data, Views view_id)
{
	if (data.spriteID >= _sprites_count)
		return false;
	SetView(data, view_id);

	if (data.spriteID == -1)
		return false;

	GraphicPrefab& spr = sprites[data.spriteID];

	spr.sprite.setPosition(sf::Vector2f(data.position.x, data.position.y));
	spr.sprite.setRotation(data.rotation);
	spr.sprite.setOrigin(sf::Vector2f(data.origin.x * spr.size.x, data.origin.y * spr.size.y));
	spr.sprite.setScale(sf::Vector2f(data.size.x / spr.size.x, data.size.y / spr.size.y));
	spr.sprite.setTextureRect(sf::IntRect(spr.size.x * (data.frame % spr.frames_count), 0, (int)spr.size.x, (int)spr.size.y));
	to_draw[data.layer].push_back(sprites[data.spriteID].sprite);
	return true;
}

void GraphicManager::SetView(DrawData& data, Views view_id)
{
	View& view = views[view_id];
	Vector2F obj_pos = data.position - view.virtual_position + view.virtual_size / 2.f;
	data.position = (obj_pos * view.real_size / view.virtual_size) * view.unit_vector;
	data.position -= view.real_size * (view.unit_vector - Vector2F(1, 1)) / 2.f;
	data.position += view.real_position;
	data.size = data.size * view.real_size / view.virtual_size;

	if (data.position.x + data.size.x < 0 ||
		data.position.y + data.size.y < 0 ||
		data.position.x - data.size.x > view.real_position.x + view.real_size.x - 0 ||
		data.position.y - data.size.y > view.real_position.y + view.real_size.y - 0)
		data.spriteID = -1;

}

View* GraphicManager::GetView(Views view_id)
{
	return &(views[view_id]);
}

void GraphicManager::ClearSprites()
{
	_sprites_count = 0;
}

unsigned GraphicManager::GetSpritesCount()
{
	return _sprites_count;
}

unsigned GraphicManager::GetSpritesMaxCount()
{
	return sprites.size();
}

void GraphicManager::SetSpritesMaxCount(unsigned count)
{
	sprites.resize(count);
	if (_sprites_count > count)
		_sprites_count = count;
}

int GraphicManager::LoadSprite(GraphicPrefabData data)
{
	if (_sprites_count >= GetSpritesMaxCount())
		return -1;
	bool text_success = sprites[_sprites_count].texture.loadFromFile(data.file);
	if (!text_success)
		return -1;
	sprites[_sprites_count].sprite.setTexture(sprites[_sprites_count].texture);
	sprites[_sprites_count].size = data.size;
	sprites[_sprites_count].sprite.setTextureRect(sf::IntRect(0, 0, (int)data.size.x, (int)data.size.y));
	sprites[_sprites_count].frames_count = data.frames_count;
	_sprites_count++;
	return _sprites_count - 1;
}

bool GraphicManager::LoadSprite(GraphicPrefabData& data, unsigned id)
{
	if (id >= GetSpritesMaxCount()) 
		return false;
	bool text_success = sprites[id].texture.loadFromFile(data.file);
	if (!text_success)
		return false;
	sprites[id].sprite.setTexture(sprites[id].texture);
	sprites[id].size = data.size;
	sprites[_sprites_count].sprite.setTextureRect(sf::IntRect(0, 0, (int)data.size.x, (int)data.size.y));
	sprites[_sprites_count].frames_count = data.frames_count;
	return true;
}

sf::RenderWindow* GraphicManager::GetWindow()
{
	return &window;
}