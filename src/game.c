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

#include "game.h"

struct GameWindow
{
    char *window_title;
    int window_height;
    int window_width;
    int window_is_fullscreen;
    SDL_Window *window_p;
    SDL_Renderer *renderer_p;
};

// global variables
struct GameWindow *game_window;
bool game_should_run = true;
Mix_Music *song = NULL;

bool Init_Game(void)
{
    debug("Init_Game");

    // create game window object with Commodore 64 resolution
    char *game_title = "Liberty Space Battle";
    const int width = 1920;
    int height = 1080;
    bool fullscreen = true;
    game_window = create_window(game_title, width, height, fullscreen);

    // initialize SDL subsystems
    int rc = 0;
    rc = SDL_Init(SDL_INIT_EVERYTHING);
    check(rc == 0, "Unable to initialize SDL2");

    rc = IMG_Init(IMG_INIT_PNG);
    check(rc != 0, "Unable to initialize SDL2_Image");

    rc = Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048);
    check(rc == 0, "Unable to open audio device");

    song = Mix_LoadMUS("media/music/music.wav");
    Mix_PlayMusic(song, -1);

    // create SDL window
    game_window->window_p = create_SDL_window(game_window);
    check(game_window->window_p != NULL, "Unable to create game window %s", SDL_GetError());

    // create renderer
    int auto_select_rendering_driver = -1;
    game_window->renderer_p = SDL_CreateRenderer(game_window->window_p, auto_select_rendering_driver,
                                                 SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    check(game_window->renderer_p != NULL, "Unable to create SDL renderer: %s", SDL_GetError());

    SDL_RenderSetLogicalSize(game_window->renderer_p, width, height);
    
    Init_Scene_Manager();

    return true;

error:
    log_err("Unable to launch game. Check that you have SDL2 runtime libraries installed. More info available here: "
            "https://www.libsdl.org/download-2.0.php");
    log_err("Also check that you have runtime libraries for: SDL2_image SDL2_mixer SDL2_gfx");
    return false;
}

void Run_Game(void)
{
    int FPS = 30;
    int frame_delay = 1000 / FPS;
    debug("Run_Game");
    while (game_should_run)
    {
        int frame_start = SDL_GetTicks();

        process_event_loop();

        Update_Current_Scene();

        draw_sceen();

        int frame_time = frame_start - SDL_GetTicks();
        if (frame_time < frame_delay)
        {
            SDL_Delay(frame_delay - frame_time);
        }
    }
}

void process_event_loop(void)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        check_keyboard_input(&event);
    }
}

void draw_sceen(void)
{
    SDL_SetRenderDrawColor(game_window->renderer_p, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(game_window->renderer_p);
    Draw_Current_Scene();
    SDL_RenderPresent(game_window->renderer_p);
}

void End_Game(void)
{
    debug("End_Game");
    Quit_Scene_Manager();
    Mix_HaltMusic();
    Mix_FreeMusic(song);
    Mix_CloseAudio();
    IMG_Quit();
    SDL_DestroyRenderer(game_window->renderer_p);
    SDL_DestroyWindow(game_window->window_p);
    destroy_window(game_window);
    SDL_Quit();
    return;
}

struct GameWindow *create_window(char *window_title, int window_width, int window_height, bool is_fullscreen)
{
    struct GameWindow *gw = malloc(sizeof(struct GameWindow) * 1);
    check_mem(gw);

    gw->window_title = window_title;
    gw->window_width = window_width;
    gw->window_height = window_height;
    gw->window_is_fullscreen = is_fullscreen;
    gw->window_p = NULL;

    return gw;

error:
    return NULL;
}

void destroy_window(struct GameWindow *game_window)
{
    free(game_window);
    game_window = NULL;
    return;
}

SDL_Window *create_SDL_window(struct GameWindow *game_window)
{
    SDL_Window *sdl_window = NULL;
    if (game_window->window_is_fullscreen)
    {
        sdl_window = SDL_CreateWindow(game_window->window_title, 0, 0,
                                      game_window->window_width, game_window->window_height, SDL_WINDOW_FULLSCREEN_DESKTOP);
    }
    else // not full screen
    {
        sdl_window = SDL_CreateWindow(game_window->window_title, 0, 0,
                                      game_window->window_width, game_window->window_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    }
    SDL_ShowCursor(SDL_DISABLE);
    return sdl_window;
}

SDL_Renderer *Get_Renderer(void)
{
    return game_window->renderer_p;
}
