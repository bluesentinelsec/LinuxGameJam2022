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

#include "credits_screen.h"

// give entities file scope
cvector_vector_type(Entity_T *) Credits_Entities;

Entity_T *Credits_Background;
int Credits_BackgroundID = 0;

void init_credits_screen(void)
{
    debug("init_instructions_screen");

    // create entity list to hold each entity in scene
    debug("declaring Credits_Entities");
    Credits_Entities = NULL;

    // create each individual entity
    debug("Credits_Background = Create_Entity(Credits_BackgroundID, img, xPos, yPos, isActive);");
    char *img = "media/images/credits_screen.png";
    int xPos = 0;
    int yPos = 0;
    bool isActive = true;
    Credits_Background = Create_Entity(Credits_BackgroundID, img, xPos, yPos, isActive);

    // add entities to list
    debug("cvector_push_back(Credits_Entities, Credits_Background)");
    cvector_push_back(Credits_Entities, Credits_Background);
    return;
}

void update_credits_screen(void)
{
    // debug("update instructions screen");
    if (is_enter_pressed() == true)
    {
        // goto title screen
    }
    return;
}

void draw_credits_screen(void)
{
    // draw each entity in scene
    size_t i = 0;
    for (i = 0; i < cvector_size(Credits_Entities); i++)
    {
        SDL_RenderCopy(Get_Renderer(), Credits_Entities[i]->texture, NULL, NULL);
    }
    return;
}

void quit_credits_screen(void)
{
    debug("quit_instructions_screen");
    size_t i = 0;
    for (i = 0; i < cvector_size(Credits_Entities); i++)
    {
        Free_Entity(Credits_Entities[i]);
    }

    cvector_free(Credits_Entities);
    return;
}