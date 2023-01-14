/*
 * File: GPIO_Private.h
 *
 * Description:
 * This header file contains the addresses of the registers used to control the General Purpose Input/Output (GPIO) module in this project.
 * It defines pointers to the registers:
 * PORTA_REG, PORTB_REG, PORTC_REG, PORTD_REG, DDRA_REG, DDRB_REG, DDRC_REG, DDRD_REG, PINA_REG, PINB_REG, PINC_REG, and PIND_REG.
 * These registers are used to configure and control the GPIO module in a microcontroller.
 *
 * Created on: Jan 13, 2023
 * Author: Maged Magdy Asaad
 * Copyright (c) 2023 Maged Magdy. All rights reserved.
 * This work was developed under the supervision of the egFWD scholarship program (Embedded Systems professional Track).
 */

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#define PORTA_REG *((volatile uint8_t*)(0x3B))
#define PORTB_REG *((volatile uint8_t*)(0x38))
#define PORTC_REG *((volatile uint8_t*)(0x35))
#define PORTD_REG *((volatile uint8_t*)(0x32))

#define DDRA_REG  *((volatile uint8_t*)(0x3A))
#define DDRB_REG  *((volatile uint8_t*)(0x37))
#define DDRC_REG  *((volatile uint8_t*)(0x34))
#define DDRD_REG  *((volatile uint8_t*)(0x31))

#define PINA_REG  *((volatile uint8_t*)(0x39))
#define PINB_REG  *((volatile uint8_t*)(0x36))
#define PINC_REG  *((volatile uint8_t*)(0x33))
#define PIND_REG  *((volatile uint8_t*)(0x30))

#endif