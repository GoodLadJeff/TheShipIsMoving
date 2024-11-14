#include "RenderManager.h"

RenderManager::RenderManager()
{
	actors = std::vector<Actor*>();
}

void RenderManager::AddActor(Actor* actor)
{
	actors.emplace_back(actor);
}

void RenderManager::Render()
{
	for (auto actor : actors)
	{
		actor->DrawSelf();
	}
}
