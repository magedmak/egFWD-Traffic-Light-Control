/*
 * File: EXTI_Interface.h
 *
 * Description:
 * This header file contains the interfaces of the functions used to interact with the External Interrupt (EXTI) module in this project.
 * It includes the necessary headers and defines the constants used to represent the interrupts, interrupt sense and values.
 * The functions prototypes and macros defined in this file include:
 *   - EXTI_Init: function to initialize the external interrupt
 *   - EXTI_ChooseISC: function to choose the interrupt sense of a specific interrupt
 *   - ISR: macro to define the ISR function for external interrupt
 *   - sei, cli: macros to enable and disable global interrupts
 *
 * Created on: Jan 13, 2023
 * Author: Maged Magdy Asaad
 * Copyright (c) 2023 Maged Magdy. All rights reserved.
 * This work was developed under the supervision of the egFWD scholarship program (Embedded Systems professional Track).
*/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "../../utils/STD_TYPES.h"
#include "../../utils/BIT_MATH.h"
#include "EXTI_Private.h"

// Enable bits in GICR register
#define INT0 6
#define INT1 7
#define INT2 5

// Interrupt Sense
typedef enum sense{
    LOW_LEVEL,
    HIGH_LEVEL,
    RISING_EDGE,
    FALLING_EDGE,
    ANY_LOGICAL_CHANGE
} EN_InterruptSense_t;

// ISC bits
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define ISC2  6

// Flags
#define INTF0 6
#define INTF1 7
#define INTF2 5 

// Interrupts vector
#define EXTI0 __vector_1
#define EXTI1 __vector_2
#define EXTI2 __vector_3

// Set global interrupt
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

// Clear global interrupt
#define cli() __asm__ __volatile ("cli" ::: "memory")

// Interrupt prototype and definition
#define ISR(INT_VECT)\
void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void) 

// EXTI function prototypes
void EXTI_Init(uint8_t LOC_U8INTx, EN_InterruptSense_t LOC_U8INT_SENSE);
void EXTI_ChooseISC(uint8_t LOC_U8INTx, EN_InterruptSense_t LOC_U8INT_SENSE);

#endif