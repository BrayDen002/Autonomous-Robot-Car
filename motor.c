#include "motor.h"
#include "softPwm.h"
#include "wiringPi.h"

/****************************
    CAR MOTOR LOCATION
          FRONT
      1           2
 LEFT               RIGHT
      3           4
          BACK
****************************/


void PWMInit()
{
  softPwmCreate(1, 0, 100);
  softPwmWrite(1, 100);
  softPwmCreate(12, 0, 100);
  softPwmWrite(12, 100);
  softPwmCreate(17, 0, 100);
  softPwmWrite(17, 100);
  softPwmCreate(25, 0, 100);
  softPwmWrite(25, 100);
}

// motor 1
void frontLeft(int direction, int speed)
{
  if (direction == 1)
  {
    softPwmCreate(27, 0, 100);
    softPwmWrite(27, 100 -speed);
  }
  if (direction == 0)
  {
    softPwmCreate(22, 0, 100);
    softPwmWrite(22, 100 - speed);
  }
}

// motor 2
void frontRight(int direction, int speed)
{
  if (direction == 1)
  {
    softPwmCreate(24, 0, 100);
    softPwmWrite(24,  100 - speed);
  }
  if (direction == 0)
  {
    softPwmCreate(23, 0, 100);
    softPwmWrite(23,  100 - speed);
  }
}

// motor 3
void rearLeft(int direction, int speed)
{
  if (direction == 1)
  {
    softPwmCreate(9, 0, 100);
    softPwmWrite(9,  100 - speed);
  }
  if (direction == 0)
  {
    softPwmCreate(11, 0, 100);
    softPwmWrite(11,  100 - speed);
  }
}

// motor 4
void rearRight(int direction, int speed)
{
  if (direction == 1)
  {
    softPwmCreate(8, 0, 100);
    softPwmWrite(8,  100 - speed);
  }
  if (direction == 0)
  {
    softPwmCreate(7, 0, 100);
    softPwmWrite(7,  100 - speed);
  }
}

// motor 1
void stopFrontLeft(int direction)
{
  if (direction == 1)
  {
    softPwmCreate(27, 0, 100);
    softPwmWrite(27, 100);
    delay(10);
  }
  if (direction == 0)
  {
    softPwmCreate(22, 0, 100);
    softPwmWrite(22, 100);
    delay(10);
  }
}

// motor 2
void stopFrontRight(int direction)
{
  if (direction == 1)
  {
    softPwmCreate(24, 0, 100);
    softPwmWrite(24, 100);
    delay(10);
  }
  if (direction == 0)
  {
    softPwmCreate(23, 0, 100);
    softPwmWrite(23, 100);
    delay(10);
  }
}

// motor 3
void stopRearLeft(int direction)
{
  if (direction == 1)
  {
    softPwmCreate(9, 0, 100);
    softPwmWrite(9, 100);
    delay(10);
  }
  if (direction == 0)
  {
    softPwmCreate(11, 0, 100);
    softPwmWrite(11, 100);
    delay(10);
  }
}

// motor 4
void stopRearRight(int direction)
{
  if (direction == 1)
  {
    softPwmCreate(8, 0, 100);
    softPwmWrite(8, 100);
    delay(10);
  }
  if (direction == 0)
  {
    softPwmCreate(7, 0, 100);
    softPwmWrite(7, 100);
    delay(10);
  }
}



//
void moveBackward(int leftSpeed, int rightSpeed)
{
  frontLeft(0, leftSpeed);  // ccw
  frontRight(1, rightSpeed); // cw
  rearLeft(0, leftSpeed);   // ccw
  rearRight(1, rightSpeed);  // cw
}

void stopMoveForward()
{
  stopFrontLeft(0);  // cw
  stopFrontRight(1); // ccw
  stopRearLeft(0);   // cw
  stopRearRight(1);  // ccw
}


void moveForward(int leftSpeed, int rightSpeed)
{
  frontLeft(1, leftSpeed);  // cw
  frontRight(0, rightSpeed); // ccw
  rearLeft(1, leftSpeed);   // cw
  rearRight(0, rightSpeed);  // ccw
}

void stopMoveBackward()
{
  stopFrontLeft(1);  // cw
  stopFrontRight(0); // ccw
  stopRearLeft(1);   // cw
  stopRearRight(0);  // ccw
}
//
void leftTurn(int leftSpeed, int rightSpeed)
{
  frontLeft(1, leftSpeed);  // cw
  frontRight(1, rightSpeed); // cw
  rearLeft(1, leftSpeed);   // cw
  rearRight(1, rightSpeed);  // cw
}

void stopLeftTurn()
{
  stopFrontLeft(1);  // cw
  stopFrontRight(1); // ccw
  stopRearLeft(1);   // cw
  stopRearRight(1);  // ccw
}
//
void rightTurn(int leftSpeed, int rightSpeed)
{
  frontLeft(0, leftSpeed);  // cw
  frontRight(0, rightSpeed); // cw
  rearLeft(0, leftSpeed);   // cw
  rearRight(0, rightSpeed);  // cw
}

void stopRighTurn()
{
  stopFrontLeft(0);  // cw
  stopFrontRight(0); // ccw
  stopRearLeft(0);   // cw
  stopRearRight(0);  // ccw
}
