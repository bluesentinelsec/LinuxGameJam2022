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

extern bool game_should_run;

bool up_arrow_is_pressed = false;
bool down_arrow_is_pressed = false;

void check_keyboard_input(SDL_Event *event)
{
  switch (event->type)
  {
  case SDL_QUIT:
    game_should_run = false;
    break;
  // check for key release
  case SDL_KEYUP:
    // escape
    if (event->key.keysym.sym == SDLK_ESCAPE)
    {
      debug("escape was pressed");
      game_should_run = false;
    }
    // enter / return
    if (event->key.keysym.sym == SDLK_RETURN)
    {
      debug("enter/return was pressed");
    }
    // space
    if (event->key.keysym.sym == SDLK_SPACE)
    {
      debug("space was pressed");
    }
    // 1
    if (event->key.keysym.sym == SDLK_1)
    {
      debug("'1' was pressed");
    }
    // 2
    if (event->key.keysym.sym == SDLK_2)
    {
      debug("'2' was pressed");
    }
    // 3
    if (event->key.keysym.sym == SDLK_3)
    {
      debug("'3' was pressed");
    }
    // 4
    if (event->key.keysym.sym == SDLK_4)
    {
      debug("'4' was pressed");
    }
    // 5
    if (event->key.keysym.sym == SDLK_5)
    {
      debug("'5' was pressed");
    }
    // 6
    if (event->key.keysym.sym == SDLK_6)
    {
      debug("'6' was pressed");
    }
    // 7
    if (event->key.keysym.sym == SDLK_7)
    {
      debug("'7' was pressed");
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

bool is_up_pressed(void) { return up_arrow_is_pressed; }
bool is_down_pressed(void) { return down_arrow_is_pressed; }