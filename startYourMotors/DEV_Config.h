# /**************************************************************
# * Class: CSC-615-01 Fall 2021
# * Name: Antonino Calabrese
# * Student ID: 920831285
# * Github ID: ringnino
# * Project: Assignment 3 - Start your Motors
# *
# * File: DEV_Config.h
# *
# * Description: header file that is used to declare functions
# * that we need to use in our PCA9685 functions.
# **************************************************************/

/*****************************************************************************
* | File        :   DEV_Config.h
* | Author      :   Waveshare team
* | Function    :   Hardware underlying interface
* | Info        :
*                Used to shield the underlying layers of each master
*                and enhance portability
*----------------
* |	This version:   V1.0
* | Date        :   2018-09-03
* | Info        :   Basic version
*
******************************************************************************/
#ifndef __DEV_CONFIG_H_
#define __DEV_CONFIG_H_

#include <wiringPi.h>
#include <stdint.h>

/**
 * data
**/
#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t

/*------------------------------------------------------------------------------------------------------*/

UBYTE DEV_ModuleInit(void);
void DEV_ModuleExit(void);

void DEV_I2C_Init(char addr);
void DEV_I2C_WriteByte(UBYTE reg, UBYTE value);
UBYTE DEV_I2C_ReadByte(UBYTE reg);

void DEV_Delay_ms(UDOUBLE xms);
void DEV_Delay_us(UDOUBLE xus);

#endif
