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
	static Game* ref;

	static Game* GetRef() { return ref; }

	PhysicsManager* GetPhysicsManager() { return physics_manager; }
	RenderManager* GetRenderManager() { return render_manager; }
	Camera main_camera;

private:
	PhysicsManager* physics_manager;
	RenderManager* render_manager;
	Player* player;
	
	float counter;

};