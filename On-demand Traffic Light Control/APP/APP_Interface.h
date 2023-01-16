/*
 * File: APP_Interface.h
 *
 * Description:
 * This header file contains the interfaces of the functions used to implement the main 
 * application for on-demand traffic light control.
 * It includes the necessary headers and defines the constants used to represent the app.
 * The functions prototypes defined in this file include:
 *    - APP_Init: function to initialize the app.
 *    - APP_Start: function to start the functionality of the app.
 *
 * Created on: Jan 13, 2023
 * Author: Maged Magdy Asaad
 * Copyright (c) 2023 Maged Magdy. All rights reserved.
 * This work was developed under the supervision of the egFWD scholarship program (Embedded Systems professional Track).
 */


#ifndef APP_INTERFACE_H_
#define APP_INTERFACE_H_

#include "../ECUAL/LED/LED_Interface.h"
#include "../ECUAL/BUTTON/BUTTON_Interface.h"

typedef enum mode{
	NORMAL,
	PEDESTRIAN
} EN_AppMode_t;

typedef enum color{
	RED,
	YELLOW,
	GREEN	
} EN_LEDColor_t;

void APP_Init(void);
void APP_Start(void);

#endif 
