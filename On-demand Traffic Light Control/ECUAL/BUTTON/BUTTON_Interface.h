/*
 * File: BUTTON_Interface.h
 *
 * Description:
 * This header file contains the interfaces of the functions used to interact with the buttons in this project.
 * It includes the necessary headers and defines the constants used to represent the buttons.
 * The functions prototypes defined in this file include:
 *   - BUTTON_Init: function to initialize the button
 *   - BUTTON_IsPressed: function to check if the button is pressed
 *
 * Created on: Jan 13, 2023
 * Author: Maged Magdy Asaad
 * Copyright (c) 2023 Maged Magdy. All rights reserved.
 * This work was developed under the supervision of the egFWD scholarship program (Embedded Systems professional Track).
 */

#ifndef BUTTON_INTERFACE_H
#define BUTTON_INTERFACE_H

#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/EXTI/EXTI_Interface.h"

void BUTTON_Init(uint8_t LOC_U8Port, uint8_t LOC_U8Pin);
uint8_t BUTTON_IsPressed(uint8_t LOC_U8Port, uint8_t LOC_U8Pin);

#endif
