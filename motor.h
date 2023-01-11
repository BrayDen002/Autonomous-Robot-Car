#ifndef MOTOR_H_
#define MOTOR_H_

void PWMInit();

// direction for motors
// 1 for clockwise
// 0 for counterclockwise
// individual motor control START
void frontLeft(int direction, int speed);
void frontRight(int direction, int speed);
void rearLeft(int direction, int speed);
void rearRight(int direction, int speed);

// individual motor control STOP
void stopFrontLeft(int direction);
void stopFrontRight(int direction);
void stopRearLeft(int direction);
void stopRearRight(int direction);


// 4 motor control START
void moveBackward(int leftSpeed, int rightSpeed);
void moveForward(int leftSpeed, int rightSpeed);

// 4 motor control STOP
void stopMoveForward();
void stopMoveBackward();

// 4 motor control START
void leftTurn(int leftSpeed, int rightSpeed);
void rightTurn(int leftSpeed, int rightSpeed);

// 4 motor control STOP
void stopLeftTurn();
void stopRighTurn();



void runAllMotors();
void stopAllMotors();

#endif
