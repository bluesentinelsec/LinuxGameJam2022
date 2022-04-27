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

#include "splash_screen.h"
#include "sceneManager.h"

// give entities file scope
cvector_vector_type(Entity_T *) Entity_List;

Entity_T *splashscreen_entity;
int BACKGROUND_ID = 0;

void init_splash_screen(void)
{
    // create entity list to hold each entity in scene
    Entity_List = NULL;

    // create each individual entity
    char *img = "media/images/splash_screen_background.png";
    int xPos = 0;
    int yPos = 0;
    bool isActive = true;
    splashscreen_entity = Create_Entity(BACKGROUND_ID, img, xPos, yPos, isActive);
    // Set_Entity_Update_Method(splashscreen_entity, NULL);

    // add entities to list
    cvector_push_back(Entity_List, splashscreen_entity);
    return;
}

void update_splash_screen(void)
{

    if (is_enter_pressed() == true)
    {
        int title_scene = 2;
        Set_Current_Scene(title_scene);
        quit_splash_screen();
        Init_Scene(title_scene);
    }
    return;
}

void draw_splash_screen_scene(void)
{
    // draw each entity in scene
    size_t i = 0;
    for (i = 0; i < cvector_size(Entity_List); i++)
    {
        SDL_RenderCopy(Get_Renderer(), Entity_List[i]->texture, NULL, NULL);
    }
    return;
}

void quit_splash_screen(void)
{
    Free_Entity(splashscreen_entity);
    cvector_free(Entity_List);
    return;
}