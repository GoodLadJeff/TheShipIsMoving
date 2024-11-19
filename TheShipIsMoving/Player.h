#pragma once
#include "raylib.h"

class Player
{
public:
	Player();

	void UpdatePlayer(float dt);
	Camera* GetCamera() { return &camera; }
private:
	Camera camera;
	float speed = 5;
};

