#include "raylib.h"
#include "raymath.h"

int main(void)
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    void ToggleFullscreen(void);

    InitWindow(screenWidth, screenHeight, "eat shit");

    Font comicFont = LoadFont("resources/comic.ttf");

    Model poop = LoadModel("resources/poop.glb"); // load model
    Texture2D texture = LoadTexture("resources/poop.jpg"); // load model texture

    Vector3 poopPos = { 0.0f, 0.0f, 0.0f };

    const int poopWidth = (screenWidth / 2) - 175;
    const int poopHeight = (screenHeight / 2) - 125;


    const char* poopText = "poop";
    const char* pToPoop = "PRESS P TO POOP";

    Vector2 poopTextPosition = { poopWidth, poopHeight };
    Vector2 pToPoopPosition = { 75, 75 };
    float fontSize = 200.0f;
    float spacing = 2.0f;
    Color tint = GREEN;

    Camera3D camera = { 0 };
    camera.position = { 0.0f, 10.0f, 10.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };      
    camera.up = { 0.0f, 1.0f, 0.0f };          
    camera.fovy = 45.0f;                                
    camera.projection = CAMERA_PERSPECTIVE;             

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    SetTargetFPS(60);


    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        BeginMode3D(camera);

        DrawModel(poop, poopPos, 1.0f, WHITE);
        
        float offsetThisFrame = 15.0f * GetFrameTime();

        if (IsKeyDown(KEY_RIGHT))
        {
            cubePosition.x += offsetThisFrame;
            camera.target.x = cubePosition.x;
            camera.position.x = cubePosition.x;
        }
        if (IsKeyDown(KEY_LEFT))
        {
            cubePosition.x -= offsetThisFrame;
            camera.target.x = cubePosition.x;
            camera.position.x = cubePosition.x;

        }
        if (IsKeyDown(KEY_UP))
        {
            cubePosition.z -= offsetThisFrame;
            camera.target.z = cubePosition.z;
            camera.position.z -= offsetThisFrame;

        }
        if (IsKeyDown(KEY_DOWN))
        {
            cubePosition.z += offsetThisFrame;
            camera.target.z = cubePosition.z;
            camera.position.z += offsetThisFrame;
        }
        if (IsKeyDown(KEY_SPACE))
        {
            cubePosition.y += offsetThisFrame;
            camera.target.y = cubePosition.y;
            camera.position.y += offsetThisFrame;
        }
        if (IsKeyDown(KEY_D))
        {
            cubePosition.y -= offsetThisFrame;
            camera.target.y = cubePosition.y;
            camera.position.y -= offsetThisFrame;
        }


        DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, BROWN);
        DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, BLACK);

        DrawFPS(10, 10);

        DrawGrid(100, 1.0f);

        EndMode3D();
        
        
        DrawTextEx(comicFont, poopText, poopTextPosition, fontSize, spacing, tint);
        DrawText(pToPoop, 75, 75, 30, BLACK);
        

        EndDrawing();
    }

    UnloadFont(comicFont);
    CloseWindow();

    return 0;
}
