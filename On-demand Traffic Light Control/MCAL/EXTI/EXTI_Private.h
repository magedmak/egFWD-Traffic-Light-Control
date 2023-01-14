/*
 * File: EXTI_Private.h
 *
 * Description:
 * This header file contains the addresses of the registers used to control the External Interrupt (EXTI) module in this project.
 * It defines pointers to the registers MCUCR, MCUCSR, GICR, and GIFR.
 * These registers are used to configure and control the EXTI module in a microcontroller.
 *
 * Created on: Jan 13, 2023
 * Author: Maged Magdy Asaad
 * Copyright (c) 2023 Maged Magdy. All rights reserved.
 * This work was developed under the supervision of the egFWD scholarship program (Embedded Systems professional Track).
 */

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define MCUCR   *((volatile uint8_t*)(0x55))
#define MCUCSR  *((volatile uint8_t*)(0x54))
#define GICR    *((volatile uint8_t*)(0x5B))
#define GIFR    *((volatile uint8_t*)(0x5A))

#endif