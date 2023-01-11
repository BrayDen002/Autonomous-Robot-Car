# /**************************************************************
# * Class: CSC-615-01 Fall 2021
# * Name: Antonino Calabrese
# * Student ID: 920831285
# * Github ID: ringnino
# * Project: Assignment 3 - Start your Motors
# *
# * File: assignment3.c
# *
# * Description: This file is the main file that needs to be executed
# * to run the motors. We need to initialize the GPIO pins and PCA9685
# * controller for use. After that we have a infinite while loop waiting
# * for the button to be pressed to start the motor in the foward direction.
# * After running foward for at least 2 seconds we slow down to 15% duty
# * cycle and then stop for 1 second. When we start back up again we will
# * be moving in the reverse direction and speed up until we hit 100%
# * duty cycle. Finally we stop the motors so they dont continue to run
# * after the program completes.
# **************************************************************/

#include <stdio.h>
#include "DEV_Config.h"
#include "PCA9685.h"
#include "wiringPi.h"

void setupInit();
void motorMovement(int direction);
void slowDown(int currSpeed);
void speedUp(int currSpeed);
void stopMotor();

int main(int argc, char** argv)
{
  setupInit();
  pinMode(18, OUTPUT);
  digitalWrite(18, HIGH);

  while(1)
    {
      if(digitalRead(18) == LOW)
  		  {
          // forward direction (1)
          motorMovement(1);
          PCA9685_SetPwmDutyCycle(0, 100);

          // run for at least 2 seconds
          DEV_Delay_ms(2000);

          // slowdown
          slowDown(100);

          // stop for 1 second
          stopMotor();
          DEV_Delay_ms(1000);

          // reverse direction (0)
          motorMovement(0);
          PCA9685_SetPwmDutyCycle(0, 25);

          // speed up
          speedUp(25);

          // run at 100% for 2 seconds
          DEV_Delay_ms(2000);

          // stop motor
          stopMotor();
  		    break;
  	   }
   }
//stopMotor();
      return 0;
  }

  // initialize our wiringpi gpio pins
  void setupInit(){
    wiringPiSetupGpio();
    // The address range from 0x40 to 0x5F.
    PCA9685_Init(0x40);
  }

  // changes direction based on integer 1 - forward, 0 - reverse
  void motorMovement(int direction){
    if (direction == 1){
      printf("Foward Direction: \n");
      PCA9685_SetLevel(PCA_CHANNEL_1, 0);
      PCA9685_SetLevel(PCA_CHANNEL_2, 1);
    }
    else if (direction == 0){
      printf("Reverse Direction: \n");
      PCA9685_SetLevel(PCA_CHANNEL_1, 1);
      PCA9685_SetLevel(PCA_CHANNEL_2, 0);
    }
    else{
      printf("No valid direction given!");
    }
  }

  // sets duty cycle to 0 to stop the motor
  void stopMotor(){
    printf("stop \n");
    PCA9685_SetPwmDutyCycle(PCA_CHANNEL_0, 0);
    PCA9685_SetPwmDutyCycle(PCA_CHANNEL_5, 0);
  }

  // speed up function to satisfy the assignment 3 requirements
  void speedUp(int currSpeed){
    for (int x = currSpeed; x < 125; x+=20) {
      if (x >= 100){
        DEV_Delay_ms(1000);
        PCA9685_SetPwmDutyCycle(0, 100);
        printf("speed up: %d%\n", 100);
        break;
      }
      printf("speed up: %d%\n", x );
      DEV_Delay_ms(1000);
      PCA9685_SetPwmDutyCycle(0, x);
    }
  }

  // slow down function to satisfy the assignment 3 requirements
  void slowDown(int currSpeed){
    for (int x = currSpeed; x > 0; x-=15) {
      if (x <= 15){
        DEV_Delay_ms(1000);
        PCA9685_SetPwmDutyCycle(0, 15);
        printf("slow down: %d%\n", 15);
        break;
      }
      printf("slow down: %d%\n", x );
      DEV_Delay_ms(1000);
      PCA9685_SetPwmDutyCycle(0, x);
    }
  }
