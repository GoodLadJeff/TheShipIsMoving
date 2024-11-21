#include "PhysicsManager.h"
#include "raymath.h"
#include "Vec3.h"

PhysicsManager::PhysicsManager()
{
	std::cout << "PhysicsManager" << std::endl;
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
		actor->acceleration += actor->mass * gravity;
		actor->velocity += (actor->acceleration / actor->mass) * dt;
		actor->position += actor->velocity * dt;

		actor->acceleration = { 0,0,0 };

		actor->rotation += { 1,1,1 };
	}

	for (size_t i = 0; i < actors.size(); ++i)
	{
		Actor* A = actors[i];

		for (size_t j = i + 1; j < actors.size(); ++j) // j starts from i+1
		{  
			Actor* B = actors[j];

			if (CheckCollisionSpheres(A->position.GetRayVec(), 1, B->position.GetRayVec(), 1))
			{
				Vec3 AtoB = B->position - A->position;
				Vec3 BtoA = A->position - B->position;

				float x = A->velocity.x * A->velocity.x;
				float y = A->velocity.y * A->velocity.y;
				float z = A->velocity.z * A->velocity.z;

				float myRealSqrt = x + y + z;
				float A_Speed = sqrt(myRealSqrt);

				x = B->velocity.x * B->velocity.x;
				y = B->velocity.y * B->velocity.y;
				z = B->velocity.z * B->velocity.z;
				myRealSqrt = x + y + z;
				float B_Speed = sqrt(myRealSqrt);

				float vf = 3.f;
				Vec3 zero = { 0,0,0 };

				//using the speed and the mass to calculate physics

				float BandASpeed = A_Speed + B_Speed;

				Vec3 A_Inertia = A->velocity * A->mass;
				Vec3 B_Inertia = B->velocity * B->mass;
				  
				Vec3 A_ForceApplied = (BtoA * A_Speed) + B_Inertia;
				Vec3 B_ForceApplied = (AtoB * B_Speed) + A_Inertia;

				//A->AddForce(Vector3Multiply(Vector3Multiply(BtoA, B_Inertia), v));
				//B->AddForce(Vector3Multiply(Vector3Multiply(AtoB, A_Inertia), v));

				A->SetVelocity(A_ForceApplied / vf);
				B->SetVelocity(B_ForceApplied / vf);

				/*A->AddForce(Vector3Multiply(Vector3Add(Vector3Multiply(BtoA, A_SpeedVector), B_Inertia), v));
				B->AddForce(Vector3Multiply(Vector3Add(Vector3Multiply(AtoB, B_SpeedVector), A_Inertia), v));*/



				/*A->AddForce(Vector3Multiply(Vector3Multiply(BtoA, { B->mass * B_Speed,B->mass * B_Speed,B->mass * B_Speed }), v));
				B->AddForce(Vector3Multiply(Vector3Multiply(AtoB, { A->mass * A_Speed,A->mass * A_Speed,A->mass * A_Speed }), v));*/

				/*A->velocity = zero;
				B->velocity = zero;
				*/
			}
		}
	}
}
