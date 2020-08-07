#pragma once

#include "../../Engine/Gameplay/GameObject.h"
#include "../../Engine/Utility/Coordinate.h"

class Map;

class Entity : public GameObject {
public:

	// BASE
	//------------------------------------------
	void Destroy() override;
	void Init(GameObject *owner) override;
	void Update();
	//------------------------------------------

	// GETTERS AND SETTERS
	//------------------------------------------
	Map* getMap();
	void setMap(Map *map);
	void SetSize(Vector2F size = { 0, 0 });
	//------------------------------------------

protected:
	//! Razmer objekta. V IGROVYH COORDINATAH!
	Vector2F size = {0, 0};
	//! Skorost objekta
	Vector2F speed = {0, 0};
	//! Uskorenie objekta
	Vector2F acceleration = {0, 0};
private:
	Map* map;
};
