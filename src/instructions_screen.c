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

#include "title_screen.h"

// give entities file scope
cvector_vector_type(Entity_T *) Instructionscreen_Entities;

Entity_T *instructionscreen_entity;
int instructionscreen_id = 0;

void init_instructions_screen(void)
{
    debug("init_instructions_screen");

    // create entity list to hold each entity in scene
    debug("declaring Instructionscreen_Entities");
    Instructionscreen_Entities = NULL;

    // create each individual entity
    debug("instructionscreen_entity = Create_Entity(instructionscreen_id, img, xPos, yPos, isActive);");
    char *img = "media/images/instructions_screen.png";
    int xPos = 0;
    int yPos = 0;
    bool isActive = true;
    instructionscreen_entity = Create_Entity(instructionscreen_id, img, xPos, yPos, isActive);

    // add entities to list
    debug("cvector_push_back(Instructionscreen_Entities, instructionscreen_entity)");
    cvector_push_back(Instructionscreen_Entities, instructionscreen_entity);
    return;
}

void update_instructions_screen(void)
{
    // debug("update instructions screen");
    if (is_enter_pressed() == true)
    {
        // goto game screen
    }
    return;
}

void draw_instructions_screen(void)
{
    // draw each entity in scene
    size_t i = 0;
    for (i = 0; i < cvector_size(Instructionscreen_Entities); i++)
    {
        SDL_RenderCopy(Get_Renderer(), Instructionscreen_Entities[i]->texture, NULL, NULL);
    }
    return;
}

void quit_instructions_screen(void)
{
    debug("quit_instructions_screen");
    size_t i = 0;
    for (i = 0; i < cvector_size(Instructionscreen_Entities); i++)
    {
        Free_Entity(Instructionscreen_Entities[i]);
    }

    cvector_free(Instructionscreen_Entities);
    return;
}