#include <iostream>
#include "ProjectTerma.h"
#include "../Engine/GameManagment/GameManager.h"
#include "Scenes/MainMenuScene.h"
#include "../Engine/SceneManagment/SceneManager.h"
#include "../Engine/Graphics/GraphicManager.h"
#include "../Engine/Graphics/DrawData.h"
#include "../Engine/Colliders/SquareCollider.h"
#include "../Engine/Colliders/EllipseCollider.h"
#include "../Engine/Colliders/Collider.h"
#include "../Engine/Time/TimeManager.h"

void ProjectTerma::Init()
{
	printf("Game started!\n");
	GraphicManager::SetSpritesMaxCount(1);
	if (GraphicManager::LoadSprite("basic square.png") == -1) {
		printf("failed to load");
		SceneManager::CloseScene(this);
	}
	SquareCollider a, b;

	a.Init(nullptr, Vector2F(2.5, 2), Vector2F(1, sqrtf(5) / 2.f), 0, 0);
	b.Init(nullptr, Vector2F(3, 3.6), Vector2F(sqrtf(2.f), 0.5f), -PI / 4, 3 * PI / 4);

	if (Collider::IsCollide(&a, &b))
		printf("YES\n");
	else
		printf("NO\n");

}

void ProjectTerma::Update()
{
	
	SquareCollider a, b;
	for (int i = 0; i < 20000; i++) {
		float x1, x2, x3, x4, y1, y2, y3, y4;
		x1 = (float)(rand() % 1000000) / 1000.f;
		x2 = (float)(rand() % 1000000) / 1000.f;
		x3 = (float)(rand() % 1000000) / 1000.f;
		x4 = (float)(rand() % 1000000) / 1000.f;
		y1 = (float)(rand() % 1000000) / 1000.f;
		y2 = (float)(rand() % 1000000) / 1000.f;
		y3 = (float)(rand() % 1000000) / 1000.f;
		y4 = (float)(rand() % 1000000) / 1000.f;

		a.Init(nullptr, Vector2F(x1, y1), Vector2F(x2, y2));
		b.Init(nullptr, Vector2F(x3, y3), Vector2F(x4, y4));

		Collider::IsCollide(&a, &b);
	}
	
	EllipseCollider c, d;
	for (int i = 0; i < 20000; i++)
	{
		float x1, x2, x3, x4, y1, y2, y3, y4;
		x1 = (float)(rand() % 1000000) / 1000.f;
		x2 = (float)(rand() % 1000000) / 1000.f;
		x3 = (float)(rand() % 1000000) / 1000.f;
		x4 = (float)(rand() % 1000000) / 1000.f;
		y1 = (float)(rand() % 1000000) / 1000.f;
		y2 = (float)(rand() % 1000000) / 1000.f;
		y3 = (float)(rand() % 1000000) / 1000.f;
		y4 = (float)(rand() % 1000000) / 1000.f;
		c.Init(Vector2F(x1, y1), 0, Vector2F(x2, y2), nullptr);
		d.Init(Vector2F(x3, y3), 0, Vector2F(x4, y4), nullptr);

		Collider::IsCollide(&c, &d);
	}
	
}

void ProjectTerma::Destroy()
{
	printf("Game ended!\n");
}
