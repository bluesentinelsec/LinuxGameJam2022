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

#pragma once

#include "dbg.h"
#include "splash_screen.h"

void Init_Scene_Manager(void);
void Update_Scene_Manager(void);
void Quit_Scene_Manager(void);

int Get_Current_Scene(void);
void Set_Current_Scene(int);
void Init_Scene(int);
void Quit_Current_Scene(void);
void Draw_Current_Scene(void);