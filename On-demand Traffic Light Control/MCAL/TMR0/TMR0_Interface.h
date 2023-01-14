/*
 * File: TMR0_Interface.h
 *
 * Description:
 * This header file contains the TMR0_INTERFACE.h, which is responsible for controlling the Timer0 module.
 * It defines macros for waveform generation mode bit (WGM00, WGM01), clock select bit (CS00, CS01, CS02),
 * TIMER0 overflow flag (TOV0), timer prescaler (EN_TimerPrescaler_t), timer mode of operation (EN_TimerMode_t)
 * and timer configuration (ST_TimerConfig_t).
 *
 * Created on: Jan 13, 2023
 * Author: Maged Magdy Asaad
 * Copyright (c) 2023 Maged Magdy. All rights reserved.
 * This work was developed under the supervision of the egFWD scholarship program (Embedded Systems professional Track).
 */

#ifndef TMR0_INTERFACE_H_
#define TMR0_INTERFACE_H_

#include "../../utils/STD_TYPES.h"
#include "../../utils/BIT_MATH.h"
#include "TMR0_Private.h"
#include "TMR0_Config.h"

// Waveform Generation Mode Bit
#define WGM00 6
#define WGM01 3

// Clock Select Bit
#define CS00 0
#define CS01 1
#define CS02 2

// TIMER0 Overflow Flag
#define TOV0 0

// Prescaler
typedef enum scales{
    TMR0_NO_PRE,
    TMR0_PRE_8,
    TMR0_PRE_64,
    TMR0_PRE_256,
    TMR0_PRE_1024
} EN_TimerPrescaler_t;

// Timer mode of operation
typedef enum modes{
	TMR_NORMAL,
	TMR_CTC,
	PWM_FAST
} EN_TimerMode_t;

// Timer Configuration
typedef struct {
	uint8_t initVal;
	uint8_t overflowNum;
	EN_TimerMode_t mode;
	EN_TimerPrescaler_t prescaler;
} ST_TimerConfig_t;

// Timer function prototypes
void TMR0_InitNormalMode(ST_TimerConfig_t* config);
void TMR0_Start(ST_TimerConfig_t* config);
void TMR0_Stop(void);
uint8_t TMR0_GetState(void);
void TMR0_Delay(ST_TimerConfig_t* config);

#endif