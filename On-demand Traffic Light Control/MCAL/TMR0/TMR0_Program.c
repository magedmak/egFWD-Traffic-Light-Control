/*
 * File: TMR0_Program.c
 *
 * Description:
 * This file contains the implementation of the functions defined in TMR0_Interface.h.
 * These functions provide an interface for configuring and controlling the Timer0 module in AVR microcontroller.
 * The functions include initialization, starting, stopping, reading status and generating delays.
 * The functions use macros defined in BIT_MATH.h for bit manipulation operations.
 *
 * Created on: Jan 13, 2023
 * Author: Maged Magdy Asaad
 * Copyright (c) 2023 Maged Magdy. All rights reserved.
 * This work was developed under the supervision of the egFWD scholarship program (Embedded Systems professional Track).
*/

#include "TMR0_Interface.h"

/************************************************************************/
/*                Initialization Functions                              */
/************************************************************************/
/*
 * This section includes functions responsible for initializing and configuring the Timer0 module.
 */

/*
 * Function: TMR0_InitNormalMode()
 * Description: This function is responsible for initializing the Timer0 module in Normal mode.
 * It takes a pointer to a struct of type ST_TimerConfig_t, which contains the initial value,
 * overflow number, mode and prescaler.
 * The function sets the waveform generation mode bits in TCCR0 register according to the mode in the config struct.
 * Returns: void
 */
void TMR0_InitNormalMode(ST_TimerConfig_t* config){
    switch(config->mode){
		case TMR_NORMAL:
			CLR_BIT(TCCR0, WGM00);
			CLR_BIT(TCCR0, WGM01);
		break;
		
		case TMR_CTC:
			// handle CTC mode
		break;
		
		case PWM_FAST:
			// handle Fast PWM mode
		break; 
	}
}


/************************************************************************/
/*                       Control Functions                              */
/************************************************************************/
/*
 * This section includes functions responsible for controlling the Timer0 module, such as starting and stopping it.
 */

/*
 * Function: TMR0_Start()
 * Description: This function is responsible for starting the Timer0 module.
 * It takes a pointer to a struct of type ST_TimerConfig_t, which contains the initial value,
 * overflow number, mode and prescaler.
 * The function sets the initial value of TCNT0, and the prescaler bits in TCCR0 register according to the prescaler in the config struct.
 * Returns: void
 */
void TMR0_Start(ST_TimerConfig_t* config){
	TCNT0 = config->initVal;
    switch(config->prescaler){
        case TMR0_NO_PRE: 
            SET_BIT(TCCR0, CS00);
            CLR_BIT(TCCR0, CS01);
            CLR_BIT(TCCR0, CS02);
            break;

        case TMR0_PRE_8: 
            CLR_BIT(TCCR0, CS00);
            SET_BIT(TCCR0, CS01);
            CLR_BIT(TCCR0, CS02);
            break;

        case TMR0_PRE_64: 
            SET_BIT(TCCR0, CS00);
            SET_BIT(TCCR0, CS01);
            CLR_BIT(TCCR0, CS02);
            break;

        case TMR0_PRE_256: 
            CLR_BIT(TCCR0, CS00);
            CLR_BIT(TCCR0, CS01);
            SET_BIT(TCCR0, CS02);
            break;

        case TMR0_PRE_1024: 
            SET_BIT(TCCR0, CS00);
            CLR_BIT(TCCR0, CS01);
            SET_BIT(TCCR0, CS02);
            break;
    }
}

/*
 *Function: TMR0_Stop()
 * Description: This function is responsible for stopping the Timer0 module.
 * It sets all the bits in the TCCR0 register to 0, effectively stopping the timer.
 * Returns: void
 */
void TMR0_Stop(void){
	TCCR0 = 0x00; // stop TIMER0
}


/************************************************************************/
/*                        Status Functions                              */
/************************************************************************/
/*
 * This section includes functions responsible for reading the status of the Timer0 module.
*/

/*
 *Function: TMR0_GetState()
 *Description: This function is responsible for getting the state of the Timer0 overflow flag.
 *It reads the TOV0 bit in the TIFR register and returns its value.
 *Returns: uint8_t (1 if overflow occurred, 0 if no overflow)
 */
uint8_t TMR0_GetState(void){
    return GET_BIT(TIFR,TOV0);
}


/************************************************************************/
/*                       Delay Functions                                */
/************************************************************************/
/*
 * This section includes functions responsible for generating a delay using the Timer0 module.
 */

/*
 * Function: TMR0_Delay
 * Description: This function is responsible for generating a delay using the Timer0 module.
 * It takes a pointer to a struct of type ST_TimerConfig_t, which contains the initial value,
 * overflow number, mode and prescaler.
 * The function starts the timer and waits for the number of overflows specified in the config struct.
 * After each overflow, it clears the overflow flag.
 * It stops the timer after the specified number of overflows.
 * Returns: void
 */
void TMR0_Delay(ST_TimerConfig_t* config){
	TMR0_Start(config);
	uint8_t overflowCount = 0;
	while(overflowCount < config->overflowNum){
		while(!TMR0_GetState());
		SET_BIT(TIFR, TOV0); // clear overflow flag
		overflowCount++;
	}
	TMR0_Stop();
}