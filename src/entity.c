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

#include "entity.h"

Entity_T *Create_Entity(int id, char *img, int xPos, int yPos, bool isActive)
{
    Entity_T *entity = malloc(sizeof(Entity_T) * 1);
    check_mem(entity);

    entity->image = IMG_Load(img);
    check_mem(entity->image);

    entity->texture = SDL_CreateTextureFromSurface(Get_Renderer(), entity->image);
    check_mem(entity->texture);

    entity->id = id;
    entity->xPos = xPos;
    entity->yPos = yPos;
    entity->isActive = isActive;

    entity->update_fp = update;

    return entity;
error:
    log_err("unable to create entity: %s", SDL_GetError());
    return NULL;
}

void Free_Entity(Entity_T *entity)
{
    SDL_DestroyTexture(entity->texture);
    SDL_FreeSurface(entity->image);
    free(entity);
    entity = NULL;
    return;
}

void update(void)
{
    return;
}

void Set_Entity_Update_Method(Entity_T *entity, update_cb update_fp)
{
    entity->update_fp = update_fp;
}