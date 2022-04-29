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

#include "input.h"
#include "SDL2/SDL.h"
#include "sceneManager.h"
#include <SDL2/SDL_events.h>

extern bool game_should_run;

bool up_arrow_is_pressed = false;
bool down_arrow_is_pressed = false;
bool return_is_pressed = false;
bool escape_is_pressed = false;
bool space_is_pressed = false;

void check_keyboard_input(SDL_Event *event)
{
    switch (event->type)
    {
    case SDL_QUIT:
        game_should_run = false;
        break;

    // KEY UP
    case SDL_KEYUP:
        // escape
        if (event->key.keysym.sym == SDLK_ESCAPE)
        {
            debug("escape was pressed");
            escape_is_pressed = true;
            int gamestate = Get_Current_Scene();
            if (gamestate == 2) // on title screen
            {
                game_should_run = false;
            }
        }
        // enter / return
        if (event->key.keysym.sym == SDLK_RETURN)
        {
            return_is_pressed = true;
        }
        // space
        if (event->key.keysym.sym == SDLK_SPACE)
        {
            space_is_pressed = true;
        }
        break;
    default:
        break;
    }

    // buffered keyboard input
    // check if key is held down
    const Uint8 *keys = SDL_GetKeyboardState(NULL);

    // up arrow key
    if (keys[SDL_SCANCODE_UP])
    {
        up_arrow_is_pressed = true;
        debug("up arrow key is pressed");
    }
    else
    {
        up_arrow_is_pressed = false;
    }

    // down arrow key
    if (keys[SDL_SCANCODE_DOWN])
    {
        down_arrow_is_pressed = true;
        debug("down arrow key is pressed");
    }
    else
    {
        down_arrow_is_pressed = false;
    }
    return;
}

bool is_up_pressed(void)
{
    return up_arrow_is_pressed;
}
bool is_down_pressed(void)
{
    return down_arrow_is_pressed;
}

bool is_enter_pressed(void)
{
    // reset return key
    bool temp = return_is_pressed;
    return_is_pressed = false;
    return temp;
}

bool is_escape_pressed(void)
{
    // reset return key
    bool temp = escape_is_pressed;
    escape_is_pressed = false;
    return temp;
}

bool is_space_pressed(void)
{
    // reset return key
    bool temp = space_is_pressed;
    space_is_pressed = false;
    return temp;
}