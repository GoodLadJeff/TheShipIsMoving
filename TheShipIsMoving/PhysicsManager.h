#pragma once
#include "Actor.h"
#include <vector>

class PhysicsManager
{
private:
	std::vector<Actor*> actors;
	Vec3 gravity = { 0.0f, -9.81f, 0.0f };

public:

	PhysicsManager();

	void AddActor(Actor* actor);
	void Compute(float dt);
	
};

