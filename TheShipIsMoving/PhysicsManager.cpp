#include "PhysicsManager.h"
#include "raymath.h"

PhysicsManager::PhysicsManager()
{
	actors = std::vector<Actor*>();
}

void PhysicsManager::AddActor(Actor* actor)
{
	actors.emplace_back(actor);
}

void PhysicsManager::Compute(float dt)
{
	for (Actor* actor : actors)
	{
		actor->acceleration = Vector3Add(actor->acceleration, Vector3Multiply({ actor->mass,actor->mass,actor->mass }, gravity));
		actor->velocity = Vector3Add(actor->velocity, Vector3Multiply(Vector3Divide(actor->acceleration, { actor->mass, actor->mass, actor->mass }), { dt,dt,dt }));
		actor->position = Vector3Add(actor->position, Vector3Multiply(actor->velocity, { dt, dt, dt }));

		actor->acceleration = { 0,0,0 };
	}

	for (size_t i = 0; i < actors.size(); ++i)
	{
		Actor* A = actors[i];

		for (size_t j = i + 1; j < actors.size(); ++j) // j starts from i+1
		{  
			Actor* B = actors[j];

			if (CheckCollisionSpheres(A->position, 1, B->position, 1))
			{
				Vector3 AtoB = Vector3Subtract(B->position, A->position);
				Vector3 BtoA = Vector3Subtract(A->position, B->position);

				A->SetVelocity(BtoA);
				B->SetVelocity(AtoB);
			}
		}
	}
}
