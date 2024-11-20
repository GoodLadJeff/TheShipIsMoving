#pragma once
#include "raylib.h"
#include "Vec3.h"

class Actor
{
public:
	Vec3 position;
	Vec3 velocity;
	Vec3 acceleration;
	Vec3 rotation;

	float mass;

public:
	Actor();

	void DrawSelf();
	void SetVelocity(Vec3 in_velocity);
	void AddForce(Vec3 in_force);

};

