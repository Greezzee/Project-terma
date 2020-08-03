#pragma once

#include <map>

#include "../../Engine/Gameplay/GameObject.h"

class Block : public GameObject {
public:
	void Draw();
	void Destroy();
	void Init(GameObject *owner);
	void Update();
	int getSpriteId() const;
	bool isPassable() const;
	void setPassable(bool passable);

protected:
	void setSpriteId(int spriteId);

	//! ��������� �� ������, ������� �������� ������������ ��������� ������� �����
	int sprite_id;

	bool passable = 0;
};
