/*
 * File: TMR0_Private.h
 *
 * Description:
 * This header file contains the addresses of the registers used to control Timer0 in this project.
 * It defines pointers to the registers TCCR0, TCNT0, OCR0, TIMSK, and TIFR which are used for setting the timer's mode,
 * the timer's value, the output compare value, and the timer's interrupt mask and flag respectively.
 *
 * Created on: Jan 13, 2023
 * Author: Maged Magdy Asaad
 * Copyright (c) 2023 Maged Magdy. All rights reserved.
 * This work was developed under the supervision of the egFWD scholarship program (Embedded Systems professional Track).
 */

#ifndef TMR0_PRIVATE_H
#define TMR0_PRIVATE_H

#define TCCR0  *((volatile uint8_t*)(0x53)) // Timer/Counter0 Control Register
#define TCNT0  *((volatile uint8_t*)(0x52)) // Timer/Counter0 Register
#define OCR0   *((volatile uint8_t*)(0x5C)) // Timer/Counter0 Output Compare Register
#define TIMSK  *((volatile uint8_t*)(0x59)) // Timer/Counter Interrupt Mask Register
#define TIFR   *((volatile uint8_t*)(0x58)) // Timer/Counter Interrupt Flag Register

#endif