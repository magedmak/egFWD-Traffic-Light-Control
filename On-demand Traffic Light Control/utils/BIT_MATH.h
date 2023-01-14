/*
 * File: BIT_MATH.h
 *
 * Description:
 * This header file contains macros that provide bit manipulation functionality.
 * It defines macros for setting a specific bit in a variable (SET_BIT), clearing a specific bit in a variable (CLR_BIT),
 * getting the value of a specific bit in a variable (GET_BIT), and toggling the value of a specific bit in a variable (TOGG_BIT).
 *
 * Created on: Jan 13, 2023
 * Author: Maged Magdy Asaad
 * Copyright (c) 2023 Maged Magdy. All rights reserved.
 * This work was developed under the supervision of the egFWD scholarship program (Embedded Systems professional Track).
 */

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(var, bitNo)  var |= (1<<bitNo)	// Set a specific bit in a variable
#define CLR_BIT(var, bitNo)  var &= ~(1<<bitNo)	// Clear a specific bit in a variable
#define GET_BIT(var, bitNo)  (var>>bitNo)&1		// Get the value of a specific bit in a variable
#define TOGG_BIT(var, bitNo) var ^= (1<<bitNo)	// Toggle the value of a specific bit in a variable

#endif
