#include "splash_screen.h"

SDL_Surface *background_surface;
SDL_Texture *background_texture;

void init_splash_screen(void)
{
    // load graphics
    background_surface = NULL;
    background_texture = NULL;
    background_surface = IMG_Load("media/images/splash_screen_background.png");
    check_mem(background_surface);

    background_texture = SDL_CreateTextureFromSurface(Get_Renderer(), background_surface);
    check_mem(background_texture);

    // create game objects
    // set object positions
    return;
error:
    log_err("unable to initialize splash screen");
    return;
}

void update_splash_screen(void)
{
    // check input
    // update objects/logic in this scene
    return;
}

void draw_splash_screen_scene(void)
{
    // for each object in scene
        // draw object
    SDL_RenderCopy(Get_Renderer(), background_texture, NULL, NULL);
    return;
}

void quit_splash_screen(void)
{
    // clear object positions
    // free game objects
    // free graphics
    SDL_DestroyTexture(background_texture);
    SDL_FreeSurface(background_surface);
    background_surface = NULL;
    return;
}