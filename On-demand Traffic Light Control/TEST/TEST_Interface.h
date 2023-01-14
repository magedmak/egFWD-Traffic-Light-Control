/*
 * File: TEST_Interface.h
 *
 * Description:
 * This header file contains the interfaces of the functions used to test the project drivers.
 * The functions prototypes defined in this file include:
 *   - GPIO_Test: function to test GPIO driver
 *   - TMR0_Test: function to test timer0 driver
 *   - LED_Test: function to test LED driver
 *   - EXTI_Test: function to text external interrupt and button driver
 *
 * Created on: Jan 13, 2023
 * Author: Maged Magdy Asaad
 * Copyright (c) 2023 Maged Magdy. All rights reserved.
 * This work was developed under the supervision of the egFWD scholarship program (Embedded Systems professional Track).
 */



#ifndef TEST_INTERFACE_H_
#define TEST_INTERFACE_H_

// MCAL
#include "../MCAL/GPIO/GPIO_Interface.h"
#include "../MCAL/TMR0/TMR0_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"

// ECUAL
#include "../ECUAL/LED/LED_Interface.h"
#include "../ECUAL/BUTTON/BUTTON_Interface.h"

// #include "util/delay.h"

void GPIO_Test(void);
void TMR0_Test(void);
void LED_Test(void);
void EXTI_Test(void);

#endif