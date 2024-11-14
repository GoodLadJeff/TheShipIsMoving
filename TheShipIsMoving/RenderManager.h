#pragma once
#include "Actor.h"
#include <vector>

class RenderManager
{
private:
	std::vector<Actor*> actors;

public:

	RenderManager();

	void AddActor(Actor* actor);
	void Render();
};

