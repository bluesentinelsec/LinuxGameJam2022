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

// don't change these constants or everything will break
// bad design and I don't have time to fix it :(
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
    // ToDo: preload music
    Set_Current_Scene(SCENE_SPLASH_SCREEN);
    Init_Scene(Get_Current_Scene());
    return;
}

void Quit_Scene_Manager(void)
{
    return;
}

void Init_Scene(int scene)
{
    debug("Initializing scene: %d", scene);
    if (current_scene == SCENE_SPLASH_SCREEN)
    {
        init_splash_screen();
    }
    else if (current_scene == SCENE_TITLE_SCREEN)
    {
        init_title_screen();
    }
    else if (current_scene == SCENE_INSTRUCTIONS_SCREEN)
    {
        init_instructions_screen();
    }
    else if (current_scene == SCENE_GAME_SCREEN)
    {
        init_gameplay_screen();
    }
    else if (current_scene == SCENE_WIN_SCREEN)
    {
        init_win_screen();
    }
    else if (current_scene == SCENE_LOSE_SCREEN)
    {
        init_lose_screen();
    }
    else if (current_scene == SCENE_CREDITS_SCREEN)
    {
        init_credits_screen();
    }
    else
    {
        debug("not a valid scene");
    }
    return;
}

void Update_Current_Scene(void)
{
    // update the current scene
    int current_scene = Get_Current_Scene();
    if (current_scene == SCENE_SPLASH_SCREEN)
    {
        update_splash_screen();
    }
    else if (current_scene == SCENE_TITLE_SCREEN)
    {
        update_title_screen();
    }
    else if (current_scene == SCENE_INSTRUCTIONS_SCREEN)
    {
        update_instructions_screen();
    }
    else if (current_scene == SCENE_GAME_SCREEN)
    {
        update_gameplay_screen();
    }
    else if (current_scene == SCENE_WIN_SCREEN)
    {
        update_win_screen();
    }
    else if (current_scene == SCENE_LOSE_SCREEN)
    {
        update_lose_screen();
    }
    else if (current_scene == SCENE_CREDITS_SCREEN)
    {
        update_credits_screen();
    }
    else
    {
        debug("not a valid scene");
    }
    return;
}

void Draw_Current_Scene(void)
{
    int current_scene = Get_Current_Scene();

    if (current_scene == SCENE_SPLASH_SCREEN)
    {
        draw_splash_screen_scene();
    }
    else if (current_scene == SCENE_TITLE_SCREEN)
    {
        draw_title_screen_scene();
    }
    else if (current_scene == SCENE_INSTRUCTIONS_SCREEN)
    {
        draw_instructions_screen();
    }
    else if (current_scene == SCENE_GAME_SCREEN)
    {
        draw_gameplay_screen();
    }
    else if (current_scene == SCENE_WIN_SCREEN)
    {
        draw_win_screen();
    }
    else if (current_scene == SCENE_LOSE_SCREEN)
    {
        draw_lose_screen();
    }
    else if (current_scene == SCENE_CREDITS_SCREEN)
    {
        draw_credits_screen();
    }
    else
    {
        debug("not a valid scene");
    }
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