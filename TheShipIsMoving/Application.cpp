#include "raylib.h"
#include <iostream>
#include "Actor.h"
#include "PhysicsManager.h"
#include "RenderManager.h"
#include "rlgl.h"

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

    Camera3D camera = Camera3D();
    camera.position = { -20.0f, 8.0f, 0.0f };    // Camera position
    camera.target = { 0.0f, 2.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;

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

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);

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