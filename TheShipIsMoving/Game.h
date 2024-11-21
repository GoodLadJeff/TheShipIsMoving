#pragma once
#include "raylib.h"
#include <crtdbg.h>
#include <iostream>

class PhysicsManager;
class RenderManager;
class Player;


class Game
{
public:
	Game();

	void Init();

	void SetupCamera();

	void SetupScreen();

	void PhysicsUpdate(float dt);
	void Update(float dt);
	void Render();

	PhysicsManager* GetPhysicsManager() { return physics_manager; }
	RenderManager* GetRenderManager() { return render_manager; }
	Camera main_camera;

private:
	PhysicsManager* physics_manager;
	RenderManager* render_manager;
	Player* player;
	

	float counter;
};


namespace World
{
	static Game* game;
	static void SetGame(Game* in_game) { 
		_ASSERT(in_game);
		game = in_game; 
		std::cout << "game = in_game" << std::endl;
	}
}