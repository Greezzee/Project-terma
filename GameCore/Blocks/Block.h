#pragma once

#include <string>

#include "../../Engine/Gameplay/GameObject.h"
#include "../../Engine/Gameplay/ObjectsArray.h"

class SquareCollider;

class Block : public GameObject {
protected:
	unsigned int id;
public:

	// CONSTRUCTOR AND DESTRUCTOR
	//--------------------------------------
	Block();
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
	unsigned int getID() const;
	void setID(unsigned int id);

	//--------------------------------------

protected:


	//! ��������� �� ������, ������� �������� ������������ ��������� ������� �����
	int sprite_id = -1;
	//! ����� �� ����� ���� ������
	bool passable = 0;
};
