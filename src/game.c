/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

    Written by Michael Long <bluesentinel@protonmail.com>
    Copyright (C) 2022 Blue Sentinel Security LLC
*/

#include <math.h>

#include "game.h"

void RunGame(void)
{

    // this might look wrong on higher display resolutions (>_>)
    // why doesn't raylib have a virtual screen resolution function?
    // I think I'm just going to re-do this in SDL
    int screenWidth = 1920;
    int screenHeight = 1080;
    const int canvasWidth = 320;
    int canvasHeight = 200;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    RenderTexture2D renderTexture = LoadRenderTexture(screenWidth, screenHeight);
    Rectangle source = {0, (float)-canvasHeight, (float)canvasWidth, (float)-canvasHeight}; // - Because OpenGL coordinates are inverted
    Rectangle dest = {0, 0, (float)screenWidth, (float)screenHeight};
    ToggleFullscreen();

    while (!WindowShouldClose())
    {
        BeginTextureMode(renderTexture); // Enable drawing to texture
        ClearBackground(RAYWHITE);       // Clear texture background
        DrawText("test", 30, 30, 30, BLACK);
        EndTextureMode();

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexturePro(renderTexture.texture, source, dest, (Vector2){0, 0}, 0.0f, WHITE);
        DrawFPS(16, 16);
        EndDrawing();
    }
    UnloadRenderTexture(renderTexture);
    CloseWindow(); // Close window and OpenGL context
}