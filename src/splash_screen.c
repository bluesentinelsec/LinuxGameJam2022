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

#include "sceneManager.h"

// give entities file scope
cvector_vector_type(Entity_T *) Splashscreen_Entities;

Entity_T *splashscreen_entity;
int SplashBackground_ID = 0;

void init_splash_screen(void)
{
    debug("init_splash_screen");

    // create entity list to hold each entity in scene
    Splashscreen_Entities = NULL;

    // create each individual entity
    char *img = "media/images/splash_screen_background.png";
    int xPos = 0;
    int yPos = 0;
    bool isActive = true;
    splashscreen_entity = Create_Entity(SplashBackground_ID, img, xPos, yPos, isActive);
    // Set_Entity_Update_Method(splashscreen_entity, NULL);

    // add entities to list
    cvector_push_back(Splashscreen_Entities, splashscreen_entity);
    return;
}

void update_splash_screen(void)
{

    if (is_enter_pressed() == true)
    {

        int title_scene = 2;
        Set_Current_Scene(title_scene);
        Init_Scene(title_scene);
        quit_splash_screen();
    }
    return;
}

void draw_splash_screen_scene(void)
{
    // draw each entity in scene
    size_t i = 0;
    for (i = 0; i < cvector_size(Splashscreen_Entities); i++)
    {
        SDL_RenderCopy(Get_Renderer(), Splashscreen_Entities[i]->texture, NULL, NULL);
    }
    return;
}

void quit_splash_screen(void)
{
    debug("quit_splash_screen");
    size_t i = 0;
    for (i = 0; i < cvector_size(Splashscreen_Entities); i++)
    {
        Free_Entity(Splashscreen_Entities[i]);
    }

    cvector_free(Splashscreen_Entities);
    return;
}