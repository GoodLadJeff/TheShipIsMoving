#include "raylib.h"
#include <iostream>
#include "Actor.h"
#include "PhysicsManager.h"
#include "RenderManager.h"
#include "rlgl.h"
#include "raymath.h"
#include "Player.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
//void Init();
//void PhysicsUpdate(float dt);
//void Update(float dt);
//void RenderUpdate(float dt);

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    float dt = 0.0f;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    Player player = Player();
    
    // Disable cursor for FPS-style camera
    DisableCursor();

    // Variables for movement
    float speed = 5.0f;  // Movement speed
    float mouseSensitivity = 0.01f;
    Vector2 mouseDelta = {0.0f, 0.0f}; // To store mouse movement
    Vector2 mousePosition = GetMousePosition(); // Starting mouse position

    PhysicsManager phys_man = PhysicsManager();

    float counter = 0.0f;

    RenderManager rend_man = RenderManager();

    Mesh mesh = GenMeshCube(2, 2, 2);
    Model model = LoadModelFromMesh(mesh);
    Image image = LoadImage("D:/PersonalProjects/TheShipIsMoving/ressources/Wood_Crate_001_basecolor.png");
    Texture2D texture = LoadTexture("D:/PersonalProjects/TheShipIsMoving/ressources/Wood_Crate_001_basecolor.png");
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    Vector3 position = { 0.0f, 0.0f, 0.0f };
    BoundingBox bounds = GetMeshBoundingBox(model.meshes[0]);
    float x = 0.0f;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        dt = GetFrameTime();
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        phys_man.Compute(dt);

        // LE CANON
        counter += dt;
        if (counter >= 1)
        {
            counter = 0;

            float velocity_to_add = 10.0f;

            const auto just_an_object = new Actor();
            just_an_object->position = { 0, 0, 0 };
            just_an_object->SetVelocity({
                (float)GetRandomValue(0, 10) / 10.0f,
                velocity_to_add,
                velocity_to_add });

            
            const auto another_object = new Actor();
            another_object->position = { 0, 0, 10 };
            another_object->SetVelocity({
               (float)GetRandomValue(0, 10) / 10.0f,
                velocity_to_add,
                -velocity_to_add });

            phys_man.AddActor(just_an_object);
            phys_man.AddActor(another_object);

            rend_man.AddActor(just_an_object);
            rend_man.AddActor(another_object);
        }

        player.UpdatePlayer(dt);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(*player.GetCamera());

        x += 0.5f;
        DrawGrid(10, 2);
        rend_man.Render();

        rlPushMatrix();
        rlTranslatef(0, 3, 0);
        rlRotatef(30, 0, 0, 1);
        rlRotatef(30, 0, 1, 0);
        DrawModel(model, position, 1.0f, WHITE);
        rlPopMatrix();

        EndMode3D();
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}