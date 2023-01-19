/*
 * File: APP_Program.c
 *
 * Description:
 * This file implements the main application for on-demand traffic light control
 * it uses LEDs and a button to simulate a traffic light for cars and pedestrians. 
 * The program uses different LEDs for cars and pedestrians, and 
 * uses a timer to control the duration of the different light states (green, yellow, red). 
 * The program also has a button that allows the user to switch between normal mode, 
 * where the traffic light follows a normal sequence, and pedestrian mode, 
 * where the traffic light sequence is adjusted to allow pedestrians to cross.
 *
 * Created on: Jan 13, 2023
 * Author: Maged Magdy Asaad
 * Copyright (c) 2023 Maged Magdy. All rights reserved.
 * This work was developed under the supervision of the egFWD scholarship program (Embedded Systems professional Track).
 */

#include "APP_Interface.h"

ST_TimerConfig_t timerConfig_Halfsec = {INIT_VALUE_HALF_SEC, OVERFLOW_NUM_HALF_SEC, TMR_NORMAL, TMR_PRESCALER};
EN_AppMode_t appMode;
EN_LEDColor_t carLEDColor;

void APP_Init(void){
	// Initialize LEDs for cars 
	LED_Init(PORTA, PIN0);
	LED_Init(PORTA, PIN1);
	LED_Init(PORTA, PIN2);
	
	// Initialize LEDs for pedestrians 
	LED_Init(PORTB, PIN0);
	LED_Init(PORTB, PIN1);
	LED_Init(PORTB, PIN2);
	
	// Initialize Button
	BUTTON_Init(PORTD, PIN2);
	
	// Initialize Timer (Normal mode)
	TMR0_Init(&timerConfig_Halfsec);
	
	// Initialize INT0 to sense a rising edge 
	EXTI_Init(INT0, RISING_EDGE);
	
	// Initialize the application mode to normal
	appMode = NORMAL;
}

void APP_Start(void){
	switch(appMode){
		case NORMAL:
			/* 1. Car's green LED on for 5 seconds */
			LED_On(PORTA, PIN2); // turn car's green LED on
			LED_On(PORTB, PIN0); // turn pedestrian's red LED on
			for(uint8_t i=0; i<10; i++){ 
				TMR0_Delay(&timerConfig_Halfsec); // delay 0.5 second
				
				/* Check if button pressed and mode changed */
				if(PEDESTRIAN == appMode) break;
			}
			LED_Off(PORTA, PIN2); // turn car's green LED off
			LED_Off(PORTB, PIN0); // turn pedestrian's red LED off
			
			
			/* Check if button pressed and mode changed */
			if(PEDESTRIAN == appMode) break;
			
			/* 2. Car's yellow LED blinks for 5 seconds */
			for(uint8_t i=0; i<10; i++){
				if(0 == i%2){
					LED_Blink(PORTA, PIN1); // toggle car's yellow LED
					LED_Blink(PORTB, PIN1); // toggle pedestrian's yellow LED
				}
				TMR0_Delay(&timerConfig_Halfsec); // delay 0.5 second
				
				/* Check if button pressed and mode changed */
				if(PEDESTRIAN == appMode) break;
			}
			LED_Off(PORTA, PIN1); // turn car's yellow LED off
			LED_Off(PORTB, PIN1); // turn pedestrian's yellow LED off
			
			/* Check if button pressed and mode changed */
			if(PEDESTRIAN == appMode) break;
			
			/* 3. Car's red LED on for 5 seconds */
			LED_On(PORTA, PIN0); // turn car's red LED on
			LED_On(PORTB, PIN2); // turn pedestrian's green LED on
			for(uint8_t i=0; i<10; i++){
				TMR0_Delay(&timerConfig_Halfsec); // delay 0.5 second
				
				/* Check if button pressed and mode changed */
				if(PEDESTRIAN == appMode) break;
			}
			LED_Off(PORTA, PIN0); // turn car's red LED off
			LED_Off(PORTB, PIN2); // turn pedestrian's green LED off
			
			/* Check if button pressed and mode changed */
			if(PEDESTRIAN == appMode) break;
			
			/* 4. Car's yellow LED blinks for 5 seconds */
			for(uint8_t i=0; i<10; i++){
				if(0 == i%2){
					LED_Blink(PORTA, PIN1); // toggle car's yellow LED
					LED_Blink(PORTB, PIN1); // toggle pedestrian's yellow LED
				}
				TMR0_Delay(&timerConfig_Halfsec); // delay 0.5 second
							
				/* Check if button pressed and mode changed */
				if(PEDESTRIAN == appMode) break;
			}
			LED_Off(PORTA, PIN1); // turn car's yellow LED off
			LED_Off(PORTB, PIN1); // turn pedestrian's yellow LED off
		break;
		
		case PEDESTRIAN:
			/* Car's and pedestrian's yellow LEDs blink for 5 seconds */
			for(uint8_t i=0; i<10; i++){
				if(0 == i%2){
					LED_Blink(PORTA, PIN1); // toggle car's yellow LED
					LED_Blink(PORTB, PIN1); // toggle pedestrian's yellow LED
				}
				TMR0_Delay(&timerConfig_Halfsec); // delay 0.5 second
			}
			LED_Off(PORTA, PIN1); // turn car's yellow LED off
			LED_Off(PORTB, PIN1); // turn pedestrian's yellow LED off				
			
			/* Car's red and pedestrian's green LEDs are on for 5 seconds */
			LED_On(PORTA, PIN0); // turn car's red LED on
			LED_On(PORTB, PIN2); // turn pedestrian's green LED on
			for(uint8_t i=0; i<10; i++) TMR0_Delay(&timerConfig_Halfsec); // delay 5 seconds
			LED_Off(PORTA, PIN0); // turn car's red LED off
			
			/* Car's and pedestrian's yellow LEDs blink for 5 seconds */
			for(uint8_t i=0; i<10; i++){
				if(0 == i%2){
					LED_Blink(PORTA, PIN1); // toggle car's yellow LED
					LED_Blink(PORTB, PIN1); // toggle pedestrian's yellow LED
				}
				TMR0_Delay(&timerConfig_Halfsec); // delay 0.5 second
			}
			LED_Off(PORTA, PIN1); // turn car's yellow LED off
			LED_Off(PORTB, PIN1); // turn pedestrian's yellow LED off
			LED_Off(PORTB, PIN2); // turn pedestrian's green LED off
			
			/* Back to normal mode */
			appMode = NORMAL;
		break;
	}
}

ISR(EXTI0){
	// Get the color of car's LED when the button is pressed
	if(LED_IsOn(PORTA, PIN0)) carLEDColor = RED;
	else if(LED_IsOn(PORTA, PIN2)) carLEDColor = GREEN;
	else carLEDColor = YELLOW;
	
	// Change the mode to pedestrian when the button is pressed
	if(RED != carLEDColor) appMode = PEDESTRIAN;
}
