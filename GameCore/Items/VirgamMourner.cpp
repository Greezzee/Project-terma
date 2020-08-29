#include "VirgamMourner.h"

#include "../Entities/Entity.h"
#include "../PTC.h"

VirgamMourner::VirgamMourner(Entity* _missile)
{
	missile = _missile;
}

void VirgamMourner::rightClickReact()
{
	// TODO Attack
}

void VirgamMourner::leftClickReact()
{
	// TODO Something
}

void VirgamMourner::Draw()
{
	// TODO Draw
}

void VirgamMourner::Destroy()
{
	// TODO Destroy it and all missiles
	PTC::sayDestroyed("VirgamMourner");
}

void VirgamMourner::Init(GameObject *owner)
{
	attack_speed = VIRGAM_MOURNER_ATTACK_SPEED;

	PTC::sayCreated("VirgamMourner");
}

void VirgamMourner::Update()
{
	// TODO Update item
}

GameObject* VirgamMourner::Clone() const
{
	return new VirgamMourner(missile);
}

VirgamMourner::~VirgamMourner() {}
