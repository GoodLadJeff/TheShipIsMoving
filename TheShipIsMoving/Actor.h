#pragma once
#include "raylib.h"

class Actor
{
public:
	Vector3 position;
	Vector3 velocity;
	Vector3 acceleration;
	Vector3 rotation;

	float mass;

public:
	Actor();

	void DrawSelf();
	void SetVelocity(Vector3 in_velocity);
	void AddForce(Vector3 in_force);

};

