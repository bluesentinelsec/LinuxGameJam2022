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

const int SCENE_SPLASH_SCREEN = 1;
const int SCENE_TITLE_SCREEN = 2;
const int SCENE_INSTRUCTIONS_SCREEN = 3;
const int SCENE_GAME_SCREEN = 4;
const int SCENE_WIN_SCREEN = 5;
const int SCENE_LOSE_SCREEN = 6;
const int SCENE_CREDITS_SCREEN = 7;

int current_scene = 0;

void Init_Scene_Manager(void)
{
    Set_Current_Scene(SCENE_SPLASH_SCREEN);
    Init_Scene(Get_Current_Scene());
    return;
}

void Update_Scene_Manager(void)
{
    // update the current scene
    switch (current_scene)
    {
    case SCENE_SPLASH_SCREEN:
        update_splash_screen();
        break;

    default:
        log_err("trying to update invalid scene");
        break;
    };
    return;
}

void Quit_Scene_Manager(void)
{
    Quit_Current_Scene();
    return;
}

void Init_Scene(int scene)
{
    debug("Initializing scene: %d", scene);
    switch (scene)
    {
    case SCENE_SPLASH_SCREEN:
        init_splash_screen();
        break;

    default:
        log_err("trying to initialize invalid scene");
        break;
    };
    return;
}

void Quit_Current_Scene(void)
{
    // quit the specified scene
    switch (Get_Current_Scene())
    {
    case SCENE_SPLASH_SCREEN:
        quit_splash_screen();
        break;

    default:
        log_err("trying to quit invalid scene");
        break;
    };
    return;
}

void Draw_Current_Scene(void)
{
    switch (Get_Current_Scene())
    {
    case SCENE_SPLASH_SCREEN:
        draw_splash_screen_scene();
        break;

    default:
        log_err("trying to quit invalid scene");
        break;
    };
    return;
}

int Get_Current_Scene(void)
{
    return current_scene;
}

void Set_Current_Scene(int scene)
{
    current_scene = scene;
}