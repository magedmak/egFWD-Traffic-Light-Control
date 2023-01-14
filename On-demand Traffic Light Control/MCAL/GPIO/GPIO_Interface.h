/*
 * File: GPIO_Interface.h
 *
 * Description:
 * This header file contains the prototypes of the functions used to interact with the General Purpose Input/Output (GPIO) module in this project.
 * It includes the necessary headers and defines the constants used to represent the ports and pins, direction, and values.
 * The functions prototypes include:
 *   - GPIO_SetPinDir: function to set the direction of a specific pin
 *   - GPIO_SetPinVal: function to set the value of a specific pin
 *   - GPIO_SetPortDir: function to set the direction of a specific port
 *   - GPIO_SetPortVal: function to set the value of a specific port
 *   - GPIO_ToggPin: function to toggle the value of a specific pin
 *   - GPIO_GetPinVal: function to get the value of a specific pin
 *
 * Created on: Jan 13, 2023
 * Author: Maged Magdy Asaad
 * Copyright (c) 2023 Maged Magdy. All rights reserved.
 * This work was developed under the supervision of the egFWD scholarship program (Embedded Systems professional Track).
 */

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "../../utils/STD_TYPES.h"
#include "../../utils/BIT_MATH.h"
#include "GPIO_Private.h"

// GPIO Ports
#define PORTA  0
#define PORTB  1
#define PORTC  2
#define PORTD  3

// GPIO Pins
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

// PIN or PORT direction
#define INPUT  0
#define OUTPUT 1

// PIN value
#define HIGH 1
#define LOW  0

// GPIO function prototypes
void GPIO_SetPinDir(uint8_t LOC_U8Port, uint8_t LOC_U8Pin, uint8_t LOC_U8dir);
void GPIO_SetPinVal(uint8_t LOC_U8Port, uint8_t LOC_U8Pin, uint8_t LOC_U8Value);
void GPIO_SetPortDir(uint8_t LOC_U8Port, uint8_t LOC_U8dir);
void GPIO_SetPortVal(uint8_t LOC_U8Port, uint8_t LOC_U8Value);
void GPIO_ToggPin(uint8_t LOC_U8Port, uint8_t LOC_U8Pin);
uint8_t GPIO_GetPinVal(uint8_t LOC_U8Port, uint8_t LOC_U8Pin);

#endif