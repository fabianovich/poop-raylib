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

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextEx(comicFont, message, position, fontSize, spacing, tint);

        EndDrawing();
    }

    UnloadFont(comicFont);
    CloseWindow();

    return 0;
}
