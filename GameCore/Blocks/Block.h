#pragma once

#include <string>

#include "../../Engine/Gameplay/GameObject.h"
#include "../../Engine/Gameplay/ObjectsArray.h"

using namespace ge;

class SquareCollider;

class Block : public GameObject {
public:

	// CONSTRUCTOR AND DESTRUCTOR
	//--------------------------------------
	Block() {};
	virtual ~Block() {};
	//--------------------------------------

	// BASE
	//--------------------------------------
	void Draw();
	void Destroy();
	void Init(GameObject *owner);
	void Update();
	//--------------------------------------

	// GETTERS AND SETTERS
	//--------------------------------------
	void setSpriteId(int spriteId);
	int getSpriteId() const;
	bool isPassable() const;
	void setPassable(bool passable);
	const std::string& getName() const;
	void setName(const std::string &name);
	float getLightLevel() const;
	void setLightLevel(float lightLevel = 1.0f);
	void addLightLevel(float add);
	//--------------------------------------

protected:


	//! указатель на спрайт, который является ЕДИНСТВЕННОЙ текстурой данного блока
	int sprite_id = -1;
	//! Можно ли через блок пройти
	bool passable = 0;
	//! current light level in [0, 1]
	float lightLevel = 1.0f;
};
