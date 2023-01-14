/*
 * File: LED_Interface.h
 *
 * Description:
 * This header file contains the function prototypes for the LED driver.
 * The LED driver is responsible for controlling the state of an LED connected to a specific port and pin on the microcontroller.
 * The functions provided by the LED driver include:
 *  - Initializing an LED
 *  - Turning on an LED
 *  - Turning off an LED
 *  - Blinking an LED with a specific blink rate
 *  - Blinking two LEDs with a specific blink rate
 *  - Checking if an LED is currently on
 *
 * Created on: Jan 13, 2023
 * Author: Maged Magdy Asaad
 * Copyright (c) 2023 Maged Magdy. All rights reserved.
 * This work was developed under the supervision of the egFWD scholarship program (Embedded Systems professional Track).
 */

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/TMR0/TMR0_Interface.h"

void LED_Init(uint8_t LOC_U8Port, uint8_t LOC_U8Pin);
void LED_On(uint8_t LOC_U8Port, uint8_t LOC_U8Pin);
void LED_Off(uint8_t LOC_U8Port, uint8_t LOC_U8Pin);
void LED_Blink(uint8_t LOC_U8Port, uint8_t LOC_U8Pin, ST_TimerConfig_t* config);
void LED_TwoBlink(uint8_t LOC_U8CarPort, uint8_t LOC_U8CarPin, uint8_t LOC_U8PedPort, uint8_t LOC_U8PedPin, ST_TimerConfig_t* config);
uint8_t LED_IsOn(uint8_t LOC_U8Port, uint8_t LOC_U8Pin);

#endif