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

#include "win_screen.h"

// give entities file scope
cvector_vector_type(Entity_T *) Winscreen_Entities;

Entity_T *Win_Background;
int Win_BackgroundID = 0;

void init_win_screen(void)
{
    debug("init_instructions_screen");

    // create entity list to hold each entity in scene
    debug("declaring Gameplay_Entities");
    Winscreen_Entities = NULL;

    // create each individual entity
    debug("Background = Create_Entity(BackgroundID, img, xPos, yPos, isActive);");
    char *img = "media/images/win_screen.png";
    int xPos = 0;
    int yPos = 0;
    bool isActive = true;
    Win_Background = Create_Entity(Win_BackgroundID, img, xPos, yPos, isActive);

    // add entities to list
    debug("cvector_push_back(Gameplay_Entities, Background)");
    cvector_push_back(Winscreen_Entities, Win_Background);
    return;
}

void update_win_screen(void)
{
    // debug("update instructions screen");
    if (is_enter_pressed() == true)
    {
        // do stuff
    }
    return;
}

void draw_win_screen(void)
{
    // draw each entity in scene
    size_t i = 0;
    for (i = 0; i < cvector_size(Winscreen_Entities); i++)
    {
        SDL_RenderCopy(Get_Renderer(), Winscreen_Entities[i]->texture, NULL, NULL);
    }
    return;
}

void quit_win_screen(void)
{
    debug("quit_instructions_screen");
    size_t i = 0;
    for (i = 0; i < cvector_size(Winscreen_Entities); i++)
    {
        Free_Entity(Winscreen_Entities[i]);
    }

    cvector_free(Winscreen_Entities);
    return;
}