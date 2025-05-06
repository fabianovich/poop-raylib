#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "eat shit");

    Font comicFont = LoadFont("resources/comic.ttf");

    const char* message = "poop";
    Vector2 position = { 200, 100 };
    float fontSize = 200.0f;
    float spacing = 2.0f;
    Color tint = DARKGRAY;

    Camera3D camera = { 0 };
    camera.position = { 0.0f, 10.0f, 10.0f };  // Camera position
    camera.target = { 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, BROWN);
        DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, BLACK);

        DrawGrid(10, 1.0f);

        EndMode3D();

        DrawTextEx(comicFont, message, position, fontSize, spacing, tint);
        DrawFPS(10, 10);

        EndDrawing();
    }

    UnloadFont(comicFont);
    CloseWindow();

    return 0;
}
