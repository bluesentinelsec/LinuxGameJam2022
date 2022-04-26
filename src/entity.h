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

// todo - need to add a src and dst rect
struct Entity
{
    int id;
    int xPos;
    int yPos;
    bool isActive;
    SDL_Surface *image;
    SDL_Texture *texture;
};
typedef struct Entity Entity_T;

Entity_T *Create_Entity(int id, char *img, int xPos, int yPos, bool isActive);
void Free_Entity(Entity_T *entity);

// ToDo:
// enable entity
// disable entity
// get entity x
// get entity y
// set entity x
// set entity y
