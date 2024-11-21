#include "Game.h"
#include "rlgl.h"
#include "PhysicsManager.h"
#include "RenderManager.h"
#include "Player.h"
#include <iostream>

Game::Game() :
	physics_manager(new PhysicsManager()),
	render_manager(new RenderManager()),
	counter(0.0f)
{
	main_camera = Camera3D();
	std::cout << "Game" << std::endl;
}

void Game::Init()
{
	std::cout << "Game::Init" << std::endl;
	SetupScreen();

	player = new Player();
	std::cout << "new Player()" << std::endl;
	SetupCamera();

	
	
	const Actor just_an_object = new Actor();
	std::cout << "just_an_object" << std::endl;
}

void Game::SetupCamera()
{
	main_camera.position = player->position.GetRayVec();
	main_camera.target.x -= 5.0f;
	main_camera.up = { 0,1,0 };
	main_camera.fovy = 90.0f;
	main_camera.projection = CAMERA_PERSPECTIVE;

	DisableCursor();
}

void Game::SetupScreen()
{
	
}

void Game::PhysicsUpdate(float dt)
{
	physics_manager->Compute(dt);
}

void Game::Update(float dt)
{
	counter += dt;
	if (counter >= 1)
	{
		counter = 0;

		float velocity_to_add = 20.0f;

		const auto just_an_object = new Actor();
		just_an_object->position = { 0, 5, -10 };
		just_an_object->SetVelocity({
			(float)GetRandomValue(0, velocity_to_add) / 10.0f,
			velocity_to_add / 1.5f,
			velocity_to_add });


		const auto another_object = new Actor();
		another_object->position = { 0, 5, 10 };
		another_object->SetVelocity({
		   (float)GetRandomValue(0, velocity_to_add) / 10.0f,
			velocity_to_add / 1.5f,
			-velocity_to_add });
	}

	player->target = { main_camera.target.x, main_camera.target.y, main_camera.target.z };
	player->Update(dt);
	main_camera.position = player->position.GetRayVec();
}

void Game::Render()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	BeginMode3D(main_camera);

	DrawGrid(10, 2);

	render_manager->Render();

	EndMode3D();
	EndDrawing();
}