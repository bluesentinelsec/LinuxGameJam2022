#pragma once

// Internal dependencies
#include "dbg.h"
#include "game.h"

// External dependencies
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL2_gfxPrimitives.h>

void init_splash_screen(void);
void update_splash_screen(void);
void quit_splash_screen(void);
void draw_splash_screen_scene(void);