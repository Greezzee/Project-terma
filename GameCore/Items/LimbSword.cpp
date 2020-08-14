#include "../Textures.h"

#include <cstdio>
#include <iostream>
#include "LimbSword.h"

void LimbSword::Draw()
{
	// TODO Draw sword with the player when equipped
}

void LimbSword::Destroy()
{
	printf("Sword destroyed!\n");
	std::cout.flush();
}

void LimbSword::Init(GameObject *owner)
{
	setIconID(Textures::SWORD);

	printf("Sword created!\n");
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
