#include "raylib.h"
int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "eat shit");

    SetTargetFPS(60);              
    while (!WindowShouldClose())    // window close button / esc key
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("poop!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    
    CloseWindow();        
    return 0;
}