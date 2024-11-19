#include "Player.h"
#include "raymath.h"
#include <iostream>

Player::Player()
{
    camera = { 0 };
    camera.position = { 0.0f, 2.0f, 20.0f }; 
    camera.target = camera.position;
    camera.target.z -= 5.0f;
    camera.up = { 0.0f, 1.0f, 0.0f };    
    camera.fovy = 45.0f;         
    camera.projection = CAMERA_PERSPECTIVE;
}

void Player::UpdatePlayer(float dt)
{
    Vector3 towards_target = Vector3Subtract(camera.target, camera.position);
    towards_target.y = 0;
    towards_target = Vector3Normalize(towards_target);

    //std::cout << camera.position.x << std::endl;

    if (IsKeyDown(KEY_W))
    {
       camera.position = Vector3Add(camera.position, Vector3Multiply(towards_target, { speed * dt, speed * dt, speed * dt }));
       camera.target = Vector3Add(camera.target, Vector3Multiply(towards_target, { speed * dt, speed * dt, speed * dt }));
    }
    if (IsKeyDown(KEY_S))
    {
       camera.position = Vector3Subtract(camera.position, Vector3Multiply(towards_target, { speed * dt, speed * dt, speed * dt }));
       camera.target = Vector3Subtract(camera.target, Vector3Multiply(towards_target, { speed * dt, speed * dt, speed * dt }));
    }
}
