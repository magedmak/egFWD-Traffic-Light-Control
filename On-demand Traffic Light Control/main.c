/*
 * File: main.c
 *
 * Description:
 * This file is the main entry point to the "on-demand traffic light control"
 * it calls the APP_init function to initialize the application
 * and calls APP_Start in an infinite loop to start the application 
 *
 * Created on: Jan 13, 2023
 * Author: Maged Magdy Asaad
 * Copyright (c) 2023 Maged Magdy. All rights reserved.
 * This work was developed under the supervision of the egFWD scholarship program (Embedded Systems professional Track).
 */

#include "APP/APP_Interface.h"

int main(void)
{
	APP_Init();
	
    while (1) 
    {
		APP_Start();	
    }
}

