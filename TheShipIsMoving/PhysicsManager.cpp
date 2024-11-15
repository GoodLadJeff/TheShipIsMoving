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

		actor->rotation = Vector3Add(actor->rotation, { 1,1,1 });
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

				// Claculate distance

				/*float ySqr = (B->position.y - A->position.y) * (B->position.y - A->position.y);
				float zSqr = (B->position.z - A->position.z) * (B->position.z - A->position.z);
				float xSqr = (B->position.x - A->position.x) * (B->position.x - A->position.x);

				float mySqr = xSqr + ySqr + zSqr;

				float myDistance = sqrt(mySqr);*/

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

				float vf = 25;
				Vector3 v = { vf,vf,vf };
				Vector3 zero = { 0,0,0 };

				//using the speed and the mass to calculate physics

				float BandASpeed = A_Speed + B_Speed;

				Vector3 A_Inertia = Vector3Multiply(A->velocity, { A->mass, A->mass, A->mass });
				Vector3 B_Inertia = Vector3Multiply(B->velocity, { B->mass, B->mass, B->mass });

				//A->AddForce(Vector3Multiply(Vector3Multiply(BtoA, B_Inertia), v));
				//B->AddForce(Vector3Multiply(Vector3Multiply(AtoB, A_Inertia), v));

				A->AddForce(Vector3Multiply(BtoA, v));
				B->AddForce(Vector3Multiply(AtoB, v));

				A->AddForce(Vector3Multiply(B->velocity, v));
				B->AddForce(Vector3Multiply(A->velocity, v));

				/*A->AddForce(Vector3Multiply(Vector3Multiply(BtoA, { B->mass * B_Speed,B->mass * B_Speed,B->mass * B_Speed }), v));
				B->AddForce(Vector3Multiply(Vector3Multiply(AtoB, { A->mass * A_Speed,A->mass * A_Speed,A->mass * A_Speed }), v));*/

				A->velocity = zero;
				B->velocity = zero;
				
			}
		}
	}
}
