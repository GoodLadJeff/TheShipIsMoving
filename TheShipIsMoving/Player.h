#pragma once
#include "raylib.h"
#include "Vec3.h"
#include "Actor.h"

class Player : public Actor
{
public:
	Player();

	void Move(float dt);
	float walking_speed = 10.0f;
	Vec3 target = {};
	Vec3 up = { 0, 1, 0 };
};

