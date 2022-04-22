/*
    main -- program entry point

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

#include "game.h"

int main(void)
{

    bool game_should_run = true;

    if (Init_Game())
    {
        debug("Run_Game");

        #ifdef __EMSCRIPTEN__
        emscripten_set_main_loop(Run_Game, 0, true);
        #else
        while (game_should_run)
        {
            Run_Game();
        }
        #endif
    }
    atexit(End_Game);
    return 0;
}