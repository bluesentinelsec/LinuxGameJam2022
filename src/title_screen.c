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
cvector_vector_type(Entity_T *) Titlescreen_Entities;

Entity_T *titlescreen_entity;
int titlescreen_id = 0;

void init_title_screen(void)
{
    debug("init_title_screen");
    // create entity list to hold each entity in scene
    Titlescreen_Entities = NULL;

    // create each individual entity
    char *img = "media/images/title_screen.png";
    int xPos = 0;
    int yPos = 0;
    bool isActive = true;
    titlescreen_entity = Create_Entity(titlescreen_id, img, xPos, yPos, isActive);
    // Set_Entity_Update_Method(splashscreen_entity, NULL);

    // add entities to list
    cvector_push_back(Titlescreen_Entities, titlescreen_entity);
    return;
    return;
}
void update_title_screen(void)
{
    debug("update title screen");
    return;
}

void draw_title_screen_scene(void)
{
    // draw each entity in scene
    size_t i = 0;
    for (i = 0; i < cvector_size(Titlescreen_Entities); i++)
    {
        SDL_RenderCopy(Get_Renderer(), Titlescreen_Entities[i]->texture, NULL, NULL);
    }
    return;
}

void quit_title_screen(void)
{
    debug("quit_title_screen");
    size_t i = 0;
    for (i = 0; i < cvector_size(Titlescreen_Entities); i++)
    {
        Free_Entity(Titlescreen_Entities[i]);
    }

    cvector_free(Titlescreen_Entities);
    return;
}