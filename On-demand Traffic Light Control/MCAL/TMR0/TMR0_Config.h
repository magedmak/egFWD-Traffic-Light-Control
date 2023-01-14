/*
 * File: TMR0_Config.h
 *
 * Description:
 * This header file contains the configuration macros for Timer0 in this project.
 * It defines the F_CPU macro which represents the frequency of the microcontroller,
 * the TMR_PRESCALER macro which represents the prescaler value used for the timer,
 * the OVERFLOW_NUM_5_SEC macro which represents the number of overflow needed to reach 5 seconds,
 * and the INIT_VALUE_5_SEC macro which represents the initial value to be loaded into the timer to reach 5 seconds
 *
 * Created on: Jan 13, 2023
 * Author: Maged Magdy Asaad
 * Copyright (c) 2023 Maged Magdy. All rights reserved.
 * This work was developed under the supervision of the egFWD scholarship program (Embedded Systems professional Track).
 */

#ifndef TMR0_CONFIG_H_
#define TMR0_CONFIG_H_

#define F_CPU 1000000U
#define TMR_PRESCALER TMR0_PRE_1024
#define OVERFLOW_NUM_5_SEC 19
#define INIT_VALUE_5_SEC 0x00

#endif