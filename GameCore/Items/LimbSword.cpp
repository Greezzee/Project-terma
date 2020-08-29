#include "LimbSword.h"

#include <cstdio>

#include "../PTC.h"
#include "../Textures.h"

void LimbSword::Draw()
{
	// TODO Draw sword with the player when equipped
}

void LimbSword::Destroy()
{
	PTC::sayDestroyed("LimbSword");
}

void LimbSword::Init(GameObject *owner)
{
	setIconID(Textures::SWORD);

	PTC::sayCreated("LimbSword");
}

void LimbSword::Update()
{
	// TODO Update sword
}

LimbSword::LimbSword() {}

void LimbSword::rightClickReact()
{
	// TODO Attack
}

void LimbSword::leftClickReact()
{
	// TODO Something
}

GameObject* LimbSword::Clone() const
{
	return new LimbSword();
}
