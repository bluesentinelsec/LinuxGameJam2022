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

#include "gameplay_screen.h"
#include "entity.h"

// give entities file scope
cvector_vector_type(Entity_T *) Gameplay_Entities;

Entity_T *Background;
int BackgroundID = 0;

Entity_T *Player;
int PlayerID = 1;

Entity_T *Enemy;
int EnemyID = 2;

Entity_T *PlayerLaser;
int PlayerLaserID = 3;

Entity_T *EnemyLaser;
int EnemyLaserID = 4;

void init_gameplay_screen(void)
{
    debug("init_gameplay_screen");

    // create entity list to hold each entity in scene
    debug("declaring Gameplay_Entities");
    Gameplay_Entities = NULL;

    // create each individual entity
    debug("Background = Create_Entity(BackgroundID, img, xPos, yPos, isActive);");
    char *img = "media/images/game_screen.png";
    int xPos = 0;
    int yPos = 0;
    bool isActive = true;
    Background = Create_Entity(BackgroundID, img, xPos, yPos, isActive);

    // add entities to list
    debug("cvector_push_back(Gameplay_Entities, Background)");
    cvector_push_back(Gameplay_Entities, Background);
    return;
}

void update_gameplay_screen(void)
{
    // debug("update instructions screen");
    if (is_enter_pressed() == true)
    {
        // goto win screen
        quit_gameplay_screen();
        int win_screen = 5;
        Set_Current_Scene(win_screen);
        Init_Scene(win_screen);
    }

    if (is_space_pressed() == true)
    {
        // goto lose screen
        quit_gameplay_screen();
        int lose_screen = 6;
        Set_Current_Scene(lose_screen);
        Init_Scene(lose_screen);
    }
    // if up pressed
        // move player up

    // if down pressed
        // move player down

    // if space pressed and player laser is not active
        // play sound
        // set laser to active
        // create laster entity

    // if laser entity is not off screen
        // move right

    // if laser entity collides with enemy entity
        // kill enemy, remove laser

    // if laser is off screen
        // kill laser

    // if enemy is at top screen
        // move down

    // if enemey is at bottom screen
        // move up

    // if its been 3-5 seconds
        // enemy fires laser

    // if enemey dies, goto win screen
    // if player dies, goto lose screen
    
    return;
}

void draw_gameplay_screen(void)
{
    // draw each entity in scene
    size_t i = 0;
    for (i = 0; i < cvector_size(Gameplay_Entities); i++)
    {
        SDL_RenderCopy(Get_Renderer(), Gameplay_Entities[i]->texture, NULL, NULL);
    }
    return;
}

void quit_gameplay_screen(void)
{
    debug("quit_gameplay_screen");
    size_t i = 0;
    for (i = 0; i < cvector_size(Gameplay_Entities); i++)
    {
        Free_Entity(Gameplay_Entities[i]);
    }

    cvector_free(Gameplay_Entities);
    return;
}