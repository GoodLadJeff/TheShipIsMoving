#include "raylib.h"
#include "Game.h"
#include "Actor.h"

int main(void)
{
    float dt = 0.0f;
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
    Game* game = new Game();

    std::cout << "World::game" << std::endl;

    game->Init();

    while (!WindowShouldClose())
    {
        dt = GetFrameTime();

        game->PhysicsUpdate(dt);

        game->Update(dt);

        game->Render();
    }

    CloseWindow();

    return 0;
}