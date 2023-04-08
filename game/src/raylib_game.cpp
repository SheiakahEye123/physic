/*******************************************************************************************
*
*   raylib [shapes] example - Draw Textured Polygon
*
*   Example originally created with raylib 3.7, last time updated with raylib 3.7
*
*   Example contributed by Chris Camacho (@codifies) and reviewed by Ramon Santamaria (@raysan5)
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2021-2023 Chris Camacho (@codifies) and Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

#include "rlgl.h"
#include "raymath.h"
#include "Polygon.h"
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - textured polygon");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    Image image = LoadImage("resources/cat.png");
    Texture texture = LoadTextureFromImage(image);
    auto p = kdn::Polygon(0, 0, { {0,100},{100,100},{100,0},{0,0},{0,100} }, texture);
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("textured polygon", 20, 20, 20, DARKGRAY);

        p.Draw();

        EndDrawing();
    }

    UnloadTexture(texture);

    CloseWindow();

    return 0;
}