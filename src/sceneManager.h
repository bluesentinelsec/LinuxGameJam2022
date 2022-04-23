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