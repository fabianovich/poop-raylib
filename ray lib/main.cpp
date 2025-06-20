﻿#include "raylib.h"
#include <stdio.h>

const int MAX_ENTITIES = 420;
const float GRAVITY = 0.5f;

const int screenWidth = 1920;
const int screenHeight = 1080;

const int poopWidth = (screenWidth / 2) - 175;
const int poopHeight = (screenHeight / 2) - 125;

const int constipatedWidth = (screenWidth / 2) - 310;
const int constipatedHeight = (screenHeight / 2) - 58;

const char* poopText = "poop";
const char* pToPoop = "press p to poop";
const char* constipatedText = "CONSTIPATED!!!!";

int main(void)
{
    ToggleFullscreen();
    InitWindow(screenWidth, screenHeight, "eat shit");

    Font comicFont = LoadFont("resources/comic.ttf");

    Model poop = LoadModel("resources/og_poop.glb");

    Vector3 positions[MAX_ENTITIES];
    bool isActive[MAX_ENTITIES] = { false };
    int entityCount = 0;
    
    Vector2 constipatedTextPos = { constipatedWidth, constipatedHeight };
    Vector2 poopTextPosition = { poopWidth, poopHeight };
    Vector2 pToPoopPosition = { 75, 75 };
    Vector2 poopCountPos = { 1375, 75 };
    float fontSize = 200.0f;
    float spacing = 2.0f;
    Color tint = GREEN;

    Camera3D camera = { 0 };
    camera.position = { 0.0f, 30.0f, 10.0f };
    camera.target = { 0.0f, 10, 0.0f };      
    camera.up = { 0.0f, 1.0f, 0.0f };          
    camera.fovy = 50.0f;                                
    camera.projection = CAMERA_PERSPECTIVE;             

    Vector3 cubePosition = { 0.0f, 10, 0.0f };
    bool drawPoop = false;
    int poopAmount = 1;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if ((IsKeyPressed(KEY_P) || IsKeyPressed(KEY_SPACE)) && entityCount < MAX_ENTITIES) {
            positions[entityCount] = cubePosition;
            positions[entityCount].y -= 1.0f;
            isActive[entityCount] = true;
            entityCount++;
        }

        //gravity
        for (int i = 0; i < entityCount; i++) {
            if (isActive[i]) {
                if (positions[i].y == 1.0f) {
                    positions[i].y = 1.0f;
                }
                else {
                    positions[i].y -= GRAVITY;
                }
            }
        }

        BeginDrawing();
        ClearBackground(WHITE);

        BeginMode3D(camera);
        
        float offsetThisFrame = 15.0f * GetFrameTime();

        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        {
            cubePosition.x += offsetThisFrame;
            camera.target.x = cubePosition.x;
            camera.position.x = cubePosition.x;
        }
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_Q) || IsKeyDown(KEY_A))
        {
            cubePosition.x -= offsetThisFrame;
            camera.target.x = cubePosition.x;
            camera.position.x = cubePosition.x;
        }
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_Z) || IsKeyDown(KEY_W))
        {
            cubePosition.z -= offsetThisFrame;
            camera.target.z = cubePosition.z;
            camera.position.z -= offsetThisFrame;
        }
        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
        {
            cubePosition.z += offsetThisFrame;
            camera.target.z = cubePosition.z;
            camera.position.z += offsetThisFrame;
        }
        
        if (drawPoop == true)
        {
            for (int i = 0; i < MAX_ENTITIES; i++) {
                DrawModel(poop, positions[i], 1.0f, WHITE);
            }
        }
        
        for (int i = 0; i < entityCount; i++) {
            if (isActive[i]) {
                DrawModel(poop, positions[i], 1.0f, WHITE);
            }
        }


        DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, BROWN);
        DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, BLACK);

        DrawGrid(10000, 1.0f);

        EndMode3D();
        
        DrawTextEx(comicFont, pToPoop, pToPoopPosition, 60, spacing, BLACK);
        char poopCount[32];
        snprintf(poopCount, sizeof(poopCount), "poop count: %d/420", entityCount);
        DrawTextEx(comicFont, poopCount, poopCountPos, 60, spacing, BLACK);
        if (entityCount == 420) {
            DrawTextEx(comicFont, constipatedText, constipatedTextPos, 100, spacing, BLACK);
        }
        if (entityCount < 420) {

            DrawTextEx(comicFont, poopText, poopTextPosition, fontSize, spacing, tint);
        }

        EndDrawing();
    }

    UnloadFont(comicFont);
    CloseWindow();

    return 0;
}
