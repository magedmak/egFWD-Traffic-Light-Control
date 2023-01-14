/*
 * File: EXTI_Program.c
 *
 * Description:
 * This file contains the implementation of the functions used to interact with the External Interrupt (EXTI) module in this project.
 * It includes the necessary headers and defines the constants used to represent the interrupts, interrupt sense and values.
 * The functions implemented include:
 *   - EXTI_Init: function to initialize the external interrupt
 *   - EXTI_ChooseISC: function to choose the interrupt sense of a specific interrupt
 *
 * Created on: Jan 13, 2023
 * Author: Maged Magdy Asaad
 * Copyright (c) 2023 Maged Magdy. All rights reserved.
 * This work was developed under the supervision of the egFWD scholarship program (Embedded Systems professional Track).
 */

#include "EXTI_Interface.h"

/*
 * Function: EXTI_Init() 
 * Description: This function is used to initialize the External Interrupt and choose the sense of the interrupt.
 * Arguments:
 *   - LOC_U8INTx: the external interrupt number (INT0, INT1, INT2)
 *   - LOC_U8INT_SENSE: the sense of the interrupt (LOW_LEVEL, ANY_LOGICAL_CHANGE, FALLING_EDGE, RISING_EDGE)
 * Return value: void
 */
void EXTI_Init(uint8_t LOC_U8INTx, EN_InterruptSense_t LOC_U8INT_SENSE){
    // Enable global interrupt
    sei(); 
    
    // Choose interrupt sense
    EXTI_ChooseISC(LOC_U8INTx, LOC_U8INT_SENSE);

    // Enable external interrupt
    SET_BIT(GICR, LOC_U8INTx);
}

/*
 * Function: EXTI_ChooseISC()
 * Description: This function is used to choose the sense of the interrupt
 * Arguments:
 *   - LOC_U8INTx: the external interrupt number (INT0, INT1, INT2)
 *   - LOC_U8INT_SENSE: the sense of the interrupt (LOW_LEVEL, ANY_LOGICAL_CHANGE, FALLING_EDGE, RISING_EDGE)
 * Return value: void
 */
void EXTI_ChooseISC(uint8_t LOC_U8INTx, EN_InterruptSense_t LOC_U8INT_SENSE){
    // for INT0
    if(INT0 == LOC_U8INTx){
        switch(LOC_U8INT_SENSE){
            case(LOW_LEVEL): CLR_BIT(MCUCR, ISC00); CLR_BIT(MCUCR, ISC01); break;
            case(ANY_LOGICAL_CHANGE): SET_BIT(MCUCR, ISC00); CLR_BIT(MCUCR, ISC01); break;
            case(FALLING_EDGE): CLR_BIT(MCUCR, ISC00); SET_BIT(MCUCR, ISC01); break;
            case(RISING_EDGE): SET_BIT(MCUCR, ISC00); SET_BIT(MCUCR, ISC01); break;
        }
    }

    // for INT1
    if(INT1 == LOC_U8INTx){
        switch(LOC_U8INT_SENSE){
            case(LOW_LEVEL): CLR_BIT(MCUCR, ISC10); CLR_BIT(MCUCR, ISC11); break;
            case(ANY_LOGICAL_CHANGE): SET_BIT(MCUCR, ISC10); CLR_BIT(MCUCR, ISC11); break;
            case(FALLING_EDGE): CLR_BIT(MCUCR, ISC10); SET_BIT(MCUCR, ISC11); break;
            case(RISING_EDGE): SET_BIT(MCUCR, ISC10); SET_BIT(MCUCR, ISC11); break;
        }
    }

    // for INT2
    if(INT2 == LOC_U8INTx){
        switch(LOC_U8INT_SENSE){
            case(FALLING_EDGE): CLR_BIT(MCUCSR, ISC2); break;
            case(RISING_EDGE): SET_BIT(MCUCSR, ISC2); break;
        }
    }
}