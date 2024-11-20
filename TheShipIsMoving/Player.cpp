#include "Player.h"
#include "raymath.h"
#include <iostream>

Player::Player() : Actor()
{
    
}

void Player::Move(float dt)
{
    Vec3 direction = {};

    Vec3 forward = target - position;
    Vec3 right = forward.cross(up);

    if (IsKeyDown(KEY_W))
    {
        direction += forward.normalized();
    }
    if (IsKeyDown(KEY_S))
    {
        direction -= forward.normalized();
    }
    if (IsKeyDown(KEY_D))
    {
        direction += right.normalized();
    }
    if (IsKeyDown(KEY_A))
    {
        direction -= right.normalized();
    }

    direction = direction.normalized();
    position += direction * walking_speed * dt;
}