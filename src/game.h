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

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/html5.h>
#endif

// Internal dependencies
#include "dbg.h"

// standard library
#include <stdbool.h>
#include <stdlib.h>

// External dependencies
#include <SDL2/SDL.h>

// primary game engine functions
bool Init_Game(void);
void Run_Game(void);
void End_Game(void);

// helper functions
struct GameWindow *create_window(char *window_title, int window_width, int window_height, bool is_fullscreen);
void destroy_window(struct GameWindow *game_window);
SDL_Window *create_SDL_window(struct GameWindow *game_window);