#include "Actor.h"
#include "raymath.h"
#include "rlgl.h"
#include "Game.h"
#include "PhysicsManager.h"
#include "RenderManager.h"

Actor::Actor(Game* game, bool in_simulate_physics)
{
	position = { 0,0,0 };
	velocity = { 0,0,0 };
	acceleration = { 0,0,0 };
	rotation = { 0,0,0 };

	mass = 1;

	simulate_physics = in_simulate_physics;
	render = true;

	_ASSERT(Game::GetRef());
	_ASSERT(game->GetPhysicsManager());

	if (simulate_physics)
	{
		Game::GetRef()->GetPhysicsManager()->AddActor(this);
	}
	if (render) Game::GetRef()->GetRenderManager()->AddActor(this);
}

void Actor::DrawSelf()
{
	rlPushMatrix();
	rlTranslatef(position.x, position.y, position.z);
	rlRotatef(rotation.x, 1, 0, 0);
	rlRotatef(rotation.y, 0, 1, 0);
	rlRotatef(rotation.z, 0, 0, 1);
	DrawSphere({ 0, 0, 0 }, 1, DARKBLUE);
	DrawSphereWires({ 0, 0, 0 }, 1.1f, 3, 10, RAYWHITE);
	rlPopMatrix();
}

void Actor::SetVelocity(Vec3 in_velocity)
{
	velocity = in_velocity;
}

void Actor::AddForce(Vec3 in_force)
{
	acceleration += in_force;
}
