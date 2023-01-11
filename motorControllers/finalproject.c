
#include <wiringPi.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <wiringSerial.h>
#include <softPwm.h>
#include <signal.h>
#include "motor.h"
#include "echoSensor.h"

//assign pins
#define LINE_SENSOR_ONE 0
#define LINE_SENSOR_TWO 4
//#define OBSTACLE_SENSOR 27//PIN#

//values of linesensor to to know wether on or off line
//0 == on the line
//1 == off the line
int leftLineOuput ;
int rightLineOuput ;

void lineInterrupt(void);

PI_THREAD (myThread){
        for (;;){

            if (wiringPiISR(LINE_SENSOR_ONE, INT_EDGE_BOTH, &lineInterrupt) < 0) {
                printf("error");
            }
            delay(300);

            if (wiringPiISR(LINE_SENSOR_TWO, INT_EDGE_BOTH, &lineInterrupt) < 0) {
                printf("error");
            }
            delay(1000);

        }
        return NULL;

}

int main(int argc, char const *argv[])
{
   wiringPiSetupGpio();
   PWMInit();
   // moveForward(100, 100);
   // moveBackward(100, 100);
   // ################# beginning of line sensor code ########################
            int x = piThreadCreate(myThread);


            if (x != 0) {
                printf("it didn't start\n");
            }

            printf("Calibrating... \n");

            if(leftLineOuput == 0){
                printf("...\n");
            }
            delay(500*4);

            if(rightLineOuput == 0){
                printf("...\n ");
            }
            delay(500*4);
            printf("Calibrating done\n");


            for(;;){

                if(leftLineOuput == 1 && rightLineOuput == 1){
                  moveForward(100, 100);
                }
                delay(10);
                if (leftLineOuput == 0 && rightLineOuput == 1){
                  moveForward(0, 80);
                }
                delay(10);

                if (leftLineOuput == 1 && rightLineOuput == 0){
                  moveForward(80,0);
                }
                delay(10);

                if(leftLineOuput == 0 && rightLineOuput == 0){
                  moveForward(0, 0);
                    printf("both 0:\n" );
                }
                delay(10);

            }

}


void lineInterrupt(void){
    leftLineOuput = 0;
    rightLineOuput = 0;
    if(digitalRead(LINE_SENSOR_ONE) == 1){
        leftLineOuput = 1;
    }
    if(digitalRead(LINE_SENSOR_TWO) == 1){
        rightLineOuput = 1;
    }

}
