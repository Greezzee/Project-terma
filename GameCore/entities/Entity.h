#pragma once

#include "../../Engine/AllEngine.h"

class Map;

class Entity : public GameObject {
public:
	// CONSTRUCTOR AND DESTRUCTOR
	//------------------------------------------
	Entity() {};
	~Entity() {};
	//------------------------------------------

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
	void setColliderSize(const Vector2F &colliderSize = { 0, 0 });
	void setTextureSize(const Vector2F &textureSize = { 0, 0 });
	//------------------------------------------

protected:
	//! Razmer objekta. V IGROVYH COORDINATAH!
	Vector2F texture_size = {0, 0};
	//! Razmer objekta. V IGROVYH COORDINATAH!
	Vector2F collider_size = {0, 0};

	//! Skorost objekta
	Vector2F speed = {0, 0};
	//! Uskorenie objekta
	Vector2F externalForce = {0, 0};
private:
	Map* map = NULL;
};
