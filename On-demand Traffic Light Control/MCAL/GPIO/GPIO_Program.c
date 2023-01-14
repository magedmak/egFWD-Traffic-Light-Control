/*
 * File: GPIO_Program.c
 *
 * Description:
 * This file contains the implementation of the functions defined in GPIO_Interface.h.
 * These functions provide an interface for configuring and controlling the General Purpose Input/Output (GPIO) pins in AVR microcontroller. 
 * The functions include setting the direction and value of a single pin, setting the direction and value of a whole port, and toggling a pin.
 * The functions use macros defined in BIT_MATH.h for bit manipulation operations.
 *
 * Created on: Jan 13, 2023
 * Author: Maged Magdy Asaad
 * Copyright (c) 2023 Maged Magdy. All rights reserved.
 * This work was developed under the supervision of the egFWD scholarship program (Embedded Systems professional Track).
*/

#include "GPIO_Interface.h"

/*
 * Function: GPIO_SetPinDir()
 * Description:
 * This function sets the direction (input or output) of a specific pin on a specific port. 
 * Inputs:
 *  - uint8_t LOC_U8Port: the port of the pin (PORTA, PORTB, PORTC, or PORTD)
 *  - uint8_t LOC_U8Pin: the number of the pin (0 to 7)
 *  - uint8_t LOC_U8dir: the direction of the pin (INPUT or OUTPUT)
 * Outputs: None
 */
void GPIO_SetPinDir(uint8_t LOC_U8Port, uint8_t LOC_U8Pin, uint8_t LOC_U8dir){
	if(INPUT == LOC_U8dir){
		switch(LOC_U8Port){
			case PORTA: CLR_BIT(DDRA_REG, LOC_U8Pin); break;
			case PORTB: CLR_BIT(DDRB_REG, LOC_U8Pin); break;
			case PORTC: CLR_BIT(DDRC_REG, LOC_U8Pin); break;
			case PORTD: CLR_BIT(DDRD_REG, LOC_U8Pin); break;
		}
	}
	else if(OUTPUT == LOC_U8dir){
		switch(LOC_U8Port){
			case PORTA: SET_BIT(DDRA_REG, LOC_U8Pin); break;
			case PORTB: SET_BIT(DDRB_REG, LOC_U8Pin); break;
			case PORTC: SET_BIT(DDRC_REG, LOC_U8Pin); break;
			case PORTD: SET_BIT(DDRD_REG, LOC_U8Pin); break;
		}
	}
}

/*
 * Function: GPIO_SetPinVal()
 * Description:
 * This function sets the value (high or low) of a specific pin on a specific port. 
 * Inputs:
 *  - uint8_t LOC_U8Port: the port of the pin (PORTA, PORTB, PORTC, or PORTD)
 *  - uint8_t LOC_U8Pin: the number of the pin (0 to 7)
 *  - uint8_t LOC_U8Value: the value of the pin (HIGH or LOW)
 * Outputs: None
 */
void GPIO_SetPinVal(uint8_t LOC_U8Port, uint8_t LOC_U8Pin, uint8_t LOC_U8Value){
	if(LOW == LOC_U8Value){
		switch(LOC_U8Port){
			case PORTA: CLR_BIT(PORTA_REG, LOC_U8Pin); break;
			case PORTB: CLR_BIT(PORTB_REG, LOC_U8Pin); break;
			case PORTC: CLR_BIT(PORTC_REG, LOC_U8Pin); break;
			case PORTD: CLR_BIT(PORTD_REG, LOC_U8Pin); break;
		}
	}
	else if(HIGH == LOC_U8Value){
		switch(LOC_U8Port){
			case PORTA: SET_BIT(PORTA_REG, LOC_U8Pin); break;
			case PORTB: SET_BIT(PORTB_REG, LOC_U8Pin); break;
			case PORTC: SET_BIT(PORTC_REG, LOC_U8Pin); break;
			case PORTD: SET_BIT(PORTD_REG, LOC_U8Pin); break;
		}
	}
}

/*
 * Function: GPIO_SetPortDir()
 * Description:
 * This function sets the direction (input or output) of an entire specific port. 
 * Inputs:
 *  - uint8_t LOC_U8Port: the port (PORTA, PORTB, PORTC, or PORTD)
 *  - uint8_t LOC_U8dir: the direction of the port (INPUT or OUTPUT)
 * Outputs: None
 */
void GPIO_SetPortDir(uint8_t LOC_U8Port, uint8_t LOC_U8dir){
	switch(LOC_U8Port){
		case PORTA: DDRA_REG = LOC_U8dir; break;
		case PORTB: DDRB_REG = LOC_U8dir; break;
		case PORTC: DDRC_REG = LOC_U8dir; break;
		case PORTD: DDRD_REG = LOC_U8dir; break;
	}
}

/*
 * Function: GPIO_SetPortVal()
 * Description:
 * This function sets the value (high or low) of an entire specific port. 
 * Inputs:
 *  - uint8_t LOC_U8Port: the port (PORTA, PORTB, PORTC, or PORTD)
 *  - uint8_t LOC_U8Value: the value of the port (HIGH or LOW)
 * Outputs: None
 */
void GPIO_SetPortVal(uint8_t LOC_U8Port, uint8_t LOC_U8Value){
	switch(LOC_U8Port){
		case PORTA: PORTA_REG = LOC_U8Value; break;
		case PORTB: PORTB_REG = LOC_U8Value; break;
		case PORTC: PORTC_REG = LOC_U8Value; break;
		case PORTD: PORTD_REG = LOC_U8Value; break;
	}
}

/*
 * Function: GPIO_ToggPin()
 * Description:
 * This function toggles the value (high or low) of a specific pin on a specific port. 
 * Inputs:
 *  - uint8_t LOC_U8Port: the port of the pin (PORTA, PORTB, PORTC, or PORTD)
 *  - uint8_t LOC_U8Pin: the number of the pin (0 to 7)
 * Outputs: None
 */
void GPIO_ToggPin(uint8_t LOC_U8Port, uint8_t LOC_U8Pin){
	switch(LOC_U8Port){
		case PORTA: TOGG_BIT(PORTA_REG, LOC_U8Pin); break;
		case PORTB: TOGG_BIT(PORTB_REG, LOC_U8Pin); break;
		case PORTC: TOGG_BIT(PORTC_REG, LOC_U8Pin); break;
		case PORTD: TOGG_BIT(PORTD_REG, LOC_U8Pin); break;
	}
}

/*
 * Function: GPIO_GetPinVal()
 * Description:
 * This function gets the value (high or low) of a specific pin on a specific port. 
 * Inputs:
 *  - uint8_t LOC_U8Port: the port of the pin (PORTA, PORTB, PORTC, or PORTD)
 *  - uint8_t LOC_U8Pin: the number of the pin (0 to 7)
 * Outputs: 
 *  - uint8_t LOC_U8Result: the value of the specified pin 
*/
uint8_t GPIO_GetPinVal(uint8_t LOC_U8Port, uint8_t LOC_U8Pin){
	uint8_t LOC_U8Result;
	switch(LOC_U8Port){
		case PORTA: LOC_U8Result = GET_BIT(PORTA_REG, LOC_U8Pin); break;
		case PORTB: LOC_U8Result = GET_BIT(PORTB_REG, LOC_U8Pin); break;
		case PORTC: LOC_U8Result = GET_BIT(PORTC_REG, LOC_U8Pin); break;
		case PORTD: LOC_U8Result = GET_BIT(PORTD_REG, LOC_U8Pin); break;
	}
	return LOC_U8Result;
}