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

// give entities file scope
cvector_vector_type(Entity_T *) Gameplay_Entities;

Entity_T *Background;
int BackgroundID = 0;

Entity_T *Player;
int PlayerID = 1;
int PlayerHealth = 3;
bool PlayerShouldTakeDamage = true;

Entity_T *Enemy;
int EnemyID = 2;
int EnemyHealth = 3;
bool EnemyShouldTakeDamage = true;

// move up if below top screen
int Enemydirection = 1;
int EnemymoveUp = -1;
int EnemyMoveDown = 1;

Entity_T *PlayerLaser;
int PlayerLaserID = 3;

Entity_T *EnemyLaser;
int EnemyLaserID = 4;

// sound effects
Mix_Chunk *Sound_Effects[3];
Mix_Chunk *sound_laser = NULL;
Mix_Chunk *enemy_laser = NULL;
Mix_Chunk *explosion = NULL;

// level state
bool shouldWin = false;
bool shouldLose = false;

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

    // player
    char *player_img = "media/images/player_ship.png";
    int playerX = 0;
    int playerY = 0;
    bool isPlayerActive = true;
    Player = Create_Entity(PlayerID, player_img, playerX, playerY, isPlayerActive);
    Player->xSpeed = 50;
    Player->ySpeed = 50;
    Set_Entity_Position(Player, 128, 500);

    // player laser
    char *player_laser_img = "media/images/player_laser.png";
    PlayerLaser = Create_Entity(PlayerLaserID, player_laser_img, 0, 0, false);
    PlayerLaser->xSpeed = 50;
    Set_Entity_Position(PlayerLaser, 0, 0);

    // enemy
    char *enemy_img = "media/images/enemy_ship.png";
    Enemy = Create_Entity(EnemyID, enemy_img, 0, 0, true);
    Enemy->xSpeed = 25;
    Enemy->ySpeed = 25;
    Set_Entity_Position(Enemy, 1664, 500);
    Enemydirection = EnemymoveUp;

    // enemy laser
    char *enemy_laser_img = "media/images/enemy_laser.png";
    EnemyLaser = Create_Entity(EnemyLaserID, enemy_laser_img, 0, 0, false);
    EnemyLaser->xSpeed = 80;
    Set_Entity_Position(EnemyLaser, 0, 0);

    // add entities to list
    debug("cvector_push_back(Gameplay_Entities, Background)");
    cvector_push_back(Gameplay_Entities, Background);
    cvector_push_back(Gameplay_Entities, Player);
    cvector_push_back(Gameplay_Entities, PlayerLaser);
    cvector_push_back(Gameplay_Entities, Enemy);
    cvector_push_back(Gameplay_Entities, EnemyLaser);

    // load sounds
    sound_laser = Mix_LoadWAV("media/sound/laser.wav");
    enemy_laser = Mix_LoadWAV("media/sound/enemy_laser.wav");
    explosion = Mix_LoadWAV("media/sound/explosion.wav");

    Sound_Effects[0] = sound_laser;
    Sound_Effects[1] = enemy_laser;
    Sound_Effects[2] = explosion;
    return;
}

void update_gameplay_screen(void)
{
    size_t i = 0;
    for (i = 0; i < cvector_size(Gameplay_Entities); i++)
    {
        if (Gameplay_Entities[i]->id == PlayerID)
        {
            update_player_entity(i);
        }
        else if (Gameplay_Entities[i]->id == PlayerLaserID)
        {
            update_player_laser(i);
        }
        else if (Gameplay_Entities[i]->id == EnemyID)
        {
            update_enemy(i);
        }
        else if (Gameplay_Entities[i]->id == EnemyLaserID)
        {
            update_enemy_laser(i);
        }
        else
        {
            continue;
        }
    }

    if (shouldWin)
    {
        // goto win screen
        quit_gameplay_screen();
        int win_screen = 5;
        Set_Current_Scene(win_screen);
        Init_Scene(win_screen);
    }

    if (shouldLose)
    {
        // goto lose screen
        quit_gameplay_screen();
        int lose_screen = 6;
        Set_Current_Scene(lose_screen);
        Init_Scene(lose_screen);
    }
    return;
}

void draw_gameplay_screen(void)
{
    // draw each entity in scene
    size_t i = 0;
    for (i = 0; i < cvector_size(Gameplay_Entities); i++)
    {
        if (Gameplay_Entities[i]->isActive == true)
        {
            SDL_RenderCopy(Get_Renderer(), Gameplay_Entities[i]->texture, &Gameplay_Entities[i]->Src_Rect,
                           &Gameplay_Entities[i]->Dst_Rect);
        }
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
    shouldWin = false;
    shouldLose = false;
    PlayerHealth = 3;
    PlayerShouldTakeDamage = true;
    EnemyHealth = 3;
    EnemyShouldTakeDamage = true;
    return;
}

void update_player_entity(size_t i)
{
    // handle input
    if (is_up_pressed())
    {
        int playerYdelta = Gameplay_Entities[i]->Dst_Rect.y - Gameplay_Entities[i]->ySpeed;
        Set_Entity_Position(Gameplay_Entities[i], Gameplay_Entities[i]->Dst_Rect.x, playerYdelta);
    }

    if (is_down_pressed())
    {
        int playerXdelta = Gameplay_Entities[i]->Dst_Rect.x;
        int playerYdelta = Gameplay_Entities[i]->Dst_Rect.y + Gameplay_Entities[i]->ySpeed;
        Set_Entity_Position(Gameplay_Entities[i], playerXdelta, playerYdelta);
    }

    // clamp player height
    if (Gameplay_Entities[i]->Dst_Rect.y < 0)
    {
        Set_Entity_Position(Gameplay_Entities[i], Gameplay_Entities[i]->Dst_Rect.x, 0 + 32);
    }

    if (Gameplay_Entities[i]->Dst_Rect.y > 952)
    {
        Set_Entity_Position(Gameplay_Entities[i], Gameplay_Entities[i]->Dst_Rect.x, 952 - 32);
    }

    // ToDo: if space is pressed, spawn laser
    if (is_space_pressed() == true && Gameplay_Entities[2]->isActive == false)
    {
        // player laser sound and activate laser
        // at player position
        Mix_PlayChannel(-1, Sound_Effects[0], 0);
        int laser_offset_y = Gameplay_Entities[i]->Src_Rect.h / 2;
        Set_Entity_Position(Gameplay_Entities[2], Gameplay_Entities[i]->Dst_Rect.x,
                            Gameplay_Entities[i]->Dst_Rect.y + laser_offset_y);
        // set laster to active
        Gameplay_Entities[2]->isActive = true;
    }

    if (PlayerHealth <= 0)
    {
        shouldLose = true;
    }

    return;
}

void update_player_laser(size_t i)
{
    // if off screen, set inactive
    // else keep moving right
    if (Gameplay_Entities[i]->Dst_Rect.x > 1920)
    {
        Gameplay_Entities[i]->isActive = false;
        EnemyShouldTakeDamage = true;
    }
    else
    {
        int laserXdelta = Gameplay_Entities[i]->Dst_Rect.x + Gameplay_Entities[i]->xSpeed;
        Set_Entity_Position(Gameplay_Entities[i], laserXdelta, Gameplay_Entities[i]->Dst_Rect.y);
    }

    // check collision with enemy
    bool isColliding = SDL_HasIntersection(&Gameplay_Entities[i]->Dst_Rect, &Gameplay_Entities[3]->Dst_Rect);
    if (isColliding && EnemyShouldTakeDamage)
    {
        EnemyHealth -= 1;
        Mix_PlayChannel(-1, Sound_Effects[2], 0);
        EnemyShouldTakeDamage = false;
    }
}

void update_enemy(size_t i)
{

    // move up
    if (Gameplay_Entities[i]->Dst_Rect.y > 0 && Enemydirection == EnemymoveUp)
    {
        int theEnemyYdelta = Gameplay_Entities[i]->Dst_Rect.y - Gameplay_Entities[i]->ySpeed;
        Set_Entity_Position(Gameplay_Entities[i], Gameplay_Entities[i]->Dst_Rect.x, theEnemyYdelta);
    }

    if (Gameplay_Entities[i]->Dst_Rect.y <= 0)
    {
        Enemydirection = EnemyMoveDown;
    }

    // move down
    if (Gameplay_Entities[i]->Dst_Rect.y < 952 && Enemydirection == EnemyMoveDown)
    {
        int theEnemyYdelta = Gameplay_Entities[i]->Dst_Rect.y + Gameplay_Entities[i]->ySpeed;
        Set_Entity_Position(Gameplay_Entities[i], Gameplay_Entities[i]->Dst_Rect.x, theEnemyYdelta);
    }

    if (Gameplay_Entities[i]->Dst_Rect.y >= 952)
    {
        Enemydirection = EnemymoveUp;
    }

    // fire laser
    if (Gameplay_Entities[4]->isActive == false)
    {
        // player laser sound and activate laser
        // at player position
        Mix_PlayChannel(-1, Sound_Effects[1], 0);
        int laser_offset_y = Gameplay_Entities[i]->Src_Rect.h / 2;
        Set_Entity_Position(Gameplay_Entities[4], Gameplay_Entities[i]->Dst_Rect.x,
                            Gameplay_Entities[i]->Dst_Rect.y + laser_offset_y);
        // set laster to active
        Gameplay_Entities[4]->isActive = true;
    }

    if (EnemyHealth <= 0)
    {
        shouldWin = true;
    }
}

void update_enemy_laser(size_t i)
{
    // if off screen, set inactive
    // else keep moving right
    if (Gameplay_Entities[i]->Dst_Rect.x < 0)
    {
        Gameplay_Entities[i]->isActive = false;
        PlayerShouldTakeDamage = true;
    }
    else
    {
        int laserXdelta = Gameplay_Entities[i]->Dst_Rect.x - Gameplay_Entities[i]->xSpeed;
        Set_Entity_Position(Gameplay_Entities[i], laserXdelta, Gameplay_Entities[i]->Dst_Rect.y);
    }

    // check collision with player
    bool isColliding = SDL_HasIntersection(&Gameplay_Entities[i]->Dst_Rect, &Gameplay_Entities[1]->Dst_Rect);
    if (isColliding && PlayerShouldTakeDamage)
    {
        PlayerHealth -= 1;
        Mix_PlayChannel(-1, Sound_Effects[2], 0);
        PlayerShouldTakeDamage = false;
    }
    return;
}