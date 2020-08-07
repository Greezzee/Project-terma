#pragma once

#include <string>

#include "../../Engine/Gameplay/GameObject.h"

class SquareCollider;

class Block : public GameObject {
public:
	void Draw();
	void Destroy();
	void Init(GameObject *owner);
	void Update();
	int getSpriteId() const;
	bool isPassable() const;
	void setPassable(bool passable);
	const std::string& getName() const;
	void setName(const std::string &name);
	float getLightLevel() const;
	void setLightLevel(float lightLevel = 1.0f);
	void addLightLevel(float add);

protected:
	void setSpriteId(int spriteId);

	//! ��������� �� ������, ������� �������� ������������ ��������� ������� �����
	int sprite_id;
	//! ����� �� ����� ���� ������
	bool passable = 0;

	float lightLevel = 1.0f;
};
