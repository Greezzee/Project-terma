#include "Sword.h"

#include "../Textures.h"

#include <cstdio>
#include <iostream>

void Sword::Draw()
{
	// TODO Draw sword with the player when equipped
}

void Sword::Destroy()
{
	printf("Sword destroyed!\n");
	std::cout.flush();
}

void Sword::Init(GameObject *owner)
{
	setIconID(Textures::SWORD);

	printf("Sword created!\n");
}

void Sword::Update()
{
	// TODO Update sword
}

Sword::Sword()
{
	type = MELEE_WEAPON;
}
