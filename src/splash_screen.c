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

#include "splash_screen.h"

Entity_T *background;

int BACKGROUND_ID = 0;

void init_splash_screen(void)
{
    char *img = "media/images/splash_screen_background.png";
    int xPos = 0;
    int yPos = 0;
    bool isActive = true;
    background = Create_Entity(BACKGROUND_ID, img, xPos, yPos, isActive);

    // ToDo: add each game entity to a dynamic array
    return;
}

void update_splash_screen(void)
{
    // if enter key is released or left mouse is clicked
        // quit this scene
        // set next scene: instructions

    return;
}

void draw_splash_screen_scene(void)
{
    // for each object in scene
        // draw object    
    SDL_RenderCopy(Get_Renderer(), background->texture, NULL, NULL);
    return;
}

void quit_splash_screen(void)
{
    // clear object positions
    // free game objects
    // free graphics
    Free_Entity(background);
    return;
}