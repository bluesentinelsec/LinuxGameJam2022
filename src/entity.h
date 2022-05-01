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

#pragma once

// standard library
#include <stdbool.h>

// Internal dependencies
#include "dbg.h"
#include "game.h"

// External dependencies
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef void (*update_cb)(void);

struct Entity
{
    int id;
    bool isActive;
    int xSpeed;
    int ySpeed;
    SDL_Rect Src_Rect;
    SDL_Rect Dst_Rect;
    SDL_Surface *image;
    SDL_Texture *texture;
    update_cb update_fp;
};

typedef struct Entity Entity_T;

Entity_T *Create_Entity(int id, char *img, int xPos, int yPos, bool isActive);
void Free_Entity(Entity_T *entity);
void update(void);
void Set_Entity_Update_Method(Entity_T *entity, update_cb update_fp);
void Set_Entity_Position(Entity_T *entity, int x, int y);