/*
 * File: TEST_Program.c
 *
 * Description:
 * This file contains the implementation of the functions declared in TEST_Interface.h
 * The functions defined in this file are used to test and validate the functionality of every driver in the project.
 *
 * Created on: Jan 13, 2023
 * Author: Maged Magdy Asaad
 * Copyright (c) 2023 Maged Magdy. All rights reserved.
 * This work was developed under the supervision of the egFWD scholarship program (Embedded Systems professional Track).
 */

#include "TEST_Interface.h"

uint8_t flag = 0;

/*
 * Function: GPIO_Test()
 * This function is used to test GPIO driver functions.
 * The test is using a LED connected to PIN0 in PORTA and toggles the pin
 * according to its value in order to make the LED blink.
 * Arguments: void
 * Return value: void
 */
void GPIO_Test(void){
	GPIO_SetPinDir(PORTA, PIN0, OUTPUT);
	while(1){
		if(LOW == GPIO_GetPinVal(PORTA, PIN0)){
			GPIO_ToggPin(PORTA, PIN0);
		}
		// _delay_ms(5000);
		if(HIGH == GPIO_GetPinVal(PORTA, PIN0)){
			GPIO_ToggPin(PORTA, PIN0);
		}
		// _delay_ms(5000);
	}
}

/*
 * Function: TMR0_Test()
 * This function is used to test timer0 driver functions.
 * The test is using a LED connected to PIN0 in PORTA and blinks every 5 seconds.
 * Arguments: void
 * Return value: void
 */
void TMR0_Test(void){
	ST_TimerConfig_t timerConfig_5sec = {INIT_VALUE_5_SEC, OVERFLOW_NUM_5_SEC, TMR_NORMAL, TMR_PRESCALER};
	GPIO_SetPinDir(PORTA, PIN0, OUTPUT);
	TMR0_InitNormalMode(&timerConfig_5sec);
	while(1){
		GPIO_ToggPin(PORTA, PIN0);
		TMR0_Delay(&timerConfig_5sec);
	}
}

/*
 * Function: LED_Test()
 * This function is used to test LED driver functions.
 * The test is using 2 LEDs connected to PIN0 and PIN1 in PORTA, 
 * and if LED1 is on, LED0 blinks for 5 seconds then all LEDs turned off.
 * Arguments: void
 * Return value: void
 */
void LED_Test(void){
	ST_TimerConfig_t timerConfig_5sec = {INIT_VALUE_5_SEC, OVERFLOW_NUM_5_SEC, TMR_NORMAL, TMR_PRESCALER};
	LED_Init(PORTA, PIN0); // LED0
	LED_Init(PORTA, PIN1); // LED1
	while(1){
		LED_On(PORTA, PIN1); 
		if(LED_IsOn(PORTA, PIN1)) LED_Blink(PORTA, PIN0, &timerConfig_5sec); //
		LED_Off(PORTA, PIN0);
		LED_Off(PORTA, PIN1);
		
	}
}

/*
 * Function: EXTI_Test()
 * This function is used to test External Interrupt and Button drivers functions.
 * The test is using 1 LED connected to PIN0 in PORTA and button connected to PIN3 in PORTD
 * with pull-up resistance. When the button is pressed, the pin is connected to ground
 * and interrupt fires its flag and turns the LED on.
 * Arguments: void
 * Return value: void
 */
void EXTI_Test(void){
	ST_TimerConfig_t timerConfig_5sec = {INIT_VALUE_5_SEC, OVERFLOW_NUM_5_SEC, TMR_NORMAL, TMR_PRESCALER};
	TMR0_InitNormalMode(&timerConfig_5sec);
	GPIO_SetPinDir(PORTA, PIN0, OUTPUT);
	EXTI_Init(INT1, LOW_LEVEL);
	BUTTON_Init(PORTD, PIN3);
	while(1){
		while(!flag) GPIO_SetPinVal(PORTA, PIN0, LOW);
		GPIO_SetPinVal(PORTA, PIN0, HIGH);
		TMR0_Delay(&timerConfig_5sec);
		flag = 0;
	}
}

ISR(EXTI1){
	flag = 1;
}
