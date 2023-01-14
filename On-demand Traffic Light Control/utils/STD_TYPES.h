/*
 * File: STD_TYPES.h
 *
 * Description:
 * This header file contains the standard data types used in this project.
 * It defines the standard integer types (e.g. uint8_t, int16_t) and floating-point types (e.g. float32_t, float64_t).
 * These types are defined using the typedef keyword to make them more readable and portable across different platforms.
 * The standard integer types are:
 *		- uint8_t: Unsigned 8-bit integer
 *		- int8_t: Signed 8-bit integer
 *		- uint16_t: Unsigned 16-bit integer
 *		- int16_t: Signed 16-bit integer 
 *		- uint32_t: Unsigned 32-bit integer
 *		- int32_t: Signed 32-bit integer
 *		- uint64_t: Unsigned 64-bit integer
 *		- int64_t: Signed 64-bit integer
 * The standard floating-point types are:
 *		- float32_t: 32-bit floating-point number
 *		- float64_t: 64-bit floating-point number
 *		- float128_t: 128-bit floating-point number
 *
 * Created on: Jan 13, 2023
 * Author: Maged Magdy Asaad
 * Copyright (c) 2023 Maged Magdy. All rights reserved.
 * This work was developed under the supervision of the egFWD scholarship program (Embedded Systems professional Track).
 */

#ifndef STD_TYPES_H
#define STD_TYPES_H
  
typedef unsigned            char   uint8_t;
typedef signed              char   int8_t;

typedef unsigned short      int    uint16_t;
typedef signed   short      int    int16_t;

typedef unsigned long       int    uint32_t;
typedef signed   long       int    int32_t;

typedef unsigned long long  int    uint64_t;
typedef signed   long long  int    int64_t;

typedef                     float  float32_t;
typedef                     double float64_t;
typedef          long       double float128_t;

#endif