/*
 * File: BUTTON_Program.c
 *
 * Description:
 * This file contains the implementation of the functions declared in BUTTON_Interface.h
 * The functions defined in this file are used to initialize and read the state of a button connected to a specified port and pin.
 *
 * Created on: Jan 13, 2023
 * Author: Maged Magdy Asaad
 * Copyright (c) 2023 Maged Magdy. All rights reserved.
 * This work was developed under the supervision of the egFWD scholarship program (Embedded Systems professional Track).
 */

#include "BUTTON_Interface.h"

/*
 * Function: BUTTON_Init()
 * This function is used to initialize a button connected to a specified port and pin.
 * It sets the direction of the specified pin to input.
 * Arguments:
 *   - LOC_U8Port: the port of the button (e.g. PORTA, PORTB, etc.)
 *   - LOC_U8Pin: the pin of the button (e.g. PIN0, PIN1, etc.)
 * Return value: void
 */
void BUTTON_Init(uint8_t LOC_U8Port, uint8_t LOC_U8Pin){
    GPIO_SetPinDir(LOC_U8Port, LOC_U8Pin, INPUT);
}

/*
 * Function: BUTTON_IsPressed()
 * This function is used to read the state of a button connected to a specified port and pin.
 * It returns the value of the specified pin.
 * Arguments:
 *   - LOC_U8Port: the port of the button (e.g. PORTA, PORTB, etc.)
 *   - LOC_U8Pin: the pin of the button (e.g. PIN0, PIN1, etc.)
 * Return value: the value of the button pin (HIGH or LOW)
 */
uint8_t BUTTON_IsPressed(uint8_t LOC_U8Port, uint8_t LOC_U8Pin){
    return GPIO_GetPinVal(LOC_U8Port, LOC_U8Pin);
}