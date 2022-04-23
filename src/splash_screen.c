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

SDL_Surface *background_surface;
SDL_Texture *background_texture;

void init_splash_screen(void)
{
    // load graphics
    background_surface = NULL;
    background_texture = NULL;
    background_surface = IMG_Load("media/images/splash_screen_background.png");
    check_mem(background_surface);

    background_texture = SDL_CreateTextureFromSurface(Get_Renderer(), background_surface);
    check_mem(background_texture);

    // initialize each game entity
    // add each game entity to an array
    // load and start music
    return;
error:
    log_err("unable to initialize splash screen");
    return;
}

void update_splash_screen(void)
{
    // if enter key is released or left mouse is clicked
        // quit this scene
        // set next scene: instructions

    // if hyperlink is clicked
        // open browser to github page

    return;
}

void draw_splash_screen_scene(void)
{
    // for each object in scene
        // draw object
    SDL_RenderCopy(Get_Renderer(), background_texture, NULL, NULL);
    return;
}

void quit_splash_screen(void)
{
    // clear object positions
    // free game objects
    // free graphics
    SDL_DestroyTexture(background_texture);
    SDL_FreeSurface(background_surface);
    background_surface = NULL;
    return;
}