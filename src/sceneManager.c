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
    default:
        break;
    };
    return;
}

void Quit_Scene_Manager(void)
{
    Quit_Current_Scene();
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

void Init_Scene(int scene)
{
    debug("Initializing scene: %d", scene);
    switch (scene)
    {
    default:
        break;
    };
    return;
}

void Quit_Current_Scene(void)
{
    // quit the specified scene
    switch (Get_Current_Scene())
    {
    default:
        break;
    };
    return;
}