/*
 * File: LED_Program.c
 *
 * Description:
 * This file contains the implementation of the functions declared in LED_Interface.h
 * The functions defined in this file are used to:
 *   - Initialize an LED
 *   - Turn on an LED
 *   - Turn off an LED
 *   - Blink an LED with a specific blink rate
 *   - Blink two LEDs with a specific blink rate
 *   - Check if an LED is currently on
 *
 * Created on: Jan 13, 2023
 * Author: Maged Magdy Asaad
 * Copyright (c) 2023 Maged Magdy. All rights reserved.
 * This work was developed under the supervision of the egFWD scholarship program (Embedded Systems professional Track).
 */

#include "LED_Interface.h"

/*
 * Function: LED_Init()
 * This function is used to initialize an LED connected to a specified port and pin.
 * It sets the direction of the specified pin to output.
 * Arguments:
 *   - LOC_U8Port: the port of the LED (e.g. PORTA, PORTB, etc.)
 *   - LOC_U8Pin: the pin of the LED (e.g. PIN0, PIN1, etc.)
 * Return value: void
 */
void LED_Init(uint8_t LOC_U8Port, uint8_t LOC_U8Pin){
	GPIO_SetPinDir(LOC_U8Port, LOC_U8Pin, OUTPUT);
}

/*
 * Function: LED_On()
 * This function is used to turn on an LED connected to a specified port and pin.
 * It sets the value of the specified pin to high.
 * Arguments:
 *   - LOC_U8Port: the port of the LED (e.g. PORTA, PORTB, etc.)
 *   - LOC_U8Pin: the pin of the LED (e.g. PIN0, PIN1, etc.)
 * Return value: void
 */
void LED_On(uint8_t LOC_U8Port, uint8_t LOC_U8Pin){
	GPIO_SetPinVal(LOC_U8Port, LOC_U8Pin, HIGH);
}

/*
 * Function: LED_Off()
 * This function is used to turn off an LED connected to a specified port and pin.
 * It sets the value of the specified pin to low.
 * Arguments:
 *   - LOC_U8Port: the port of the LED (e.g. PORTA, PORTB, etc.)
 *   - LOC_U8Pin: the pin of the LED (e.g. PIN0, PIN1, etc.)
 * Return value: void
 */
void LED_Off(uint8_t LOC_U8Port, uint8_t LOC_U8Pin){
	GPIO_SetPinVal(LOC_U8Port, LOC_U8Pin, LOW);
}

/*
 * Function: LED_Blink()
 * This function is used to blink an LED connected to a specified port and pin.
 * It toggles the value of the specified pin, starts the timer and waits for the number of overflows specified in the config struct.
 * After each overflow, it clears the overflow flag.
 * It stops the timer after the specified number of overflows. .
 * Arguments:
 *   - LOC_U8Port: the port of the LED (e.g. PORTA, PORTB, etc.)
 *   - LOC_U8Pin: the pin of the LED (e.g. PIN0, PIN1, etc.)
 *   - config: pointer to timer configuration variable contains (initial value, overflow counts, mode, prescaler.)
 * Return value: void
 */
void LED_Blink(uint8_t LOC_U8Port, uint8_t LOC_U8Pin, ST_TimerConfig_t* config){
	TMR0_Start(config);
	uint8_t overflowCount = 0;
	while(overflowCount < config->overflowNum){
		while(!TMR0_GetState());
		SET_BIT(TIFR, TOV0); // clear overflow flag
		if(overflowCount%3 == 0) GPIO_ToggPin(LOC_U8Port, LOC_U8Pin); // blink LED
		overflowCount++;
	}
	TMR0_Stop();
}

/*
 * Function: LED_TwoBlink()
 * This function is used to blink two LEDs connected to a specified port and pin.
 * It toggles the value of the specified pins, starts the timer and waits for the number of overflows specified in the config struct.
 * After each overflow, it clears the overflow flag.
 * It stops the timer after the specified number of overflows. .
 * Arguments:
 *   - LOC_U8Port: the port of the LED (e.g. PORTA, PORTB, etc.)
 *   - LOC_U8Pin: the pin of the LED (e.g. PIN0, PIN1, etc.)
 *   - config: pointer to timer configuration variable contains (initial value, overflow counts, mode, prescaler.)
 * Return value: void
 */
void LED_TwoBlink(uint8_t LOC_U8CarPort, uint8_t LOC_U8CarPin, uint8_t LOC_U8PedPort, uint8_t LOC_U8PedPin, ST_TimerConfig_t* config){
	TMR0_Start(config);
	uint8_t overflowCount = 0;
	while(overflowCount < config->overflowNum){
		while(!TMR0_GetState());
		SET_BIT(TIFR, TOV0); // clear overflow flag
		if(overflowCount%3 == 0){
			GPIO_ToggPin(LOC_U8CarPort, LOC_U8CarPin); // blink LED
			GPIO_ToggPin(LOC_U8PedPort, LOC_U8PedPin); // blink LED	
		} 
		overflowCount++;
	}
	TMR0_Stop();
}

/*
 * Function: LED_IsOn()
 * This function is used to read the state of an LED connected to a specified port and pin.
 * It returns the value of the specified pin.
 * Arguments:
 *   - LOC_U8Port: the port of the button (e.g. PORTA, PORTB, etc.)
 *   - LOC_U8Pin: the pin of the button (e.g. PIN0, PIN1, etc.)
 * Return value: the value of the LED pin (HIGH or LOW)
 */
uint8_t LED_IsOn(uint8_t LOC_U8Port, uint8_t LOC_U8Pin){
	return GPIO_GetPinVal(LOC_U8Port, LOC_U8Pin);
}