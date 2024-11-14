#include "Actor.h"
#include "raymath.h"

Actor::Actor()
{
	position = { 0,0,0 };
    velocity = { 0,0,0 };
	acceleration = { 0,0,0 };

	mass = 1;
}

void Actor::DrawSelf()
{
	DrawSphere(position, 1, DARKBLUE);
}

void Actor::SetVelocity(Vector3 in_velocity)
{
	velocity = in_velocity;
}

void Actor::AddForce(Vector3 in_force)
{
	acceleration = Vector3Add(acceleration, in_force);
}
