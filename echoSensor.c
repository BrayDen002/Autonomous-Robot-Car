#include "echoSensor.h"
#include "wiringPi.h"
#include <time.h>


double frontEchoDistance()
{

  pinMode(FRONT_TRIG, OUTPUT); // trigger
  pinMode(FRONT_ECHO, INPUT);  // echo

  clock_t startTime, endTime;

  digitalWrite(FRONT_TRIG, HIGH);
  delay(10);
  digitalWrite(FRONT_TRIG, LOW);

  // loops used to calculate start and end time of echo signal
  while(digitalRead(FRONT_ECHO) == 0) { startTime = clock(); }
  while(digitalRead(FRONT_ECHO) == 1) { endTime = clock(); }

  // used to calculate seconds from clock ticks per seconds
  double elapsedTime = ((double)endTime - startTime) / CLOCKS_PER_SEC;

  // convert distance to centimeters and
  // divides by 2 to get rid of round trip distance
  double finalDistance = (elapsedTime * SPEED_OF_SOUND) / 2;
  return finalDistance;
}

double leftEchoDistance()
{
  pinMode(LEFT_TRIG, OUTPUT); // trigger
  pinMode(LEFT_ECHO, INPUT);  // echo

  clock_t startTime, endTime;

  digitalWrite(LEFT_TRIG, HIGH);
  delay(10);
  digitalWrite(LEFT_TRIG, LOW);

  // loops used to calculate start and end time of echo signal
  while(digitalRead(LEFT_ECHO) == 0) { startTime = clock(); }
  while(digitalRead(LEFT_ECHO) == 1) { endTime = clock(); }

  // used to calculate seconds from clock ticks per seconds
  double elapsedTime = ((double)endTime - startTime) / CLOCKS_PER_SEC;

  // convert distance to centimeters and
  // divides by 2 to get rid of round trip distance
  double finalDistance = (elapsedTime * SPEED_OF_SOUND) / 2;
  return finalDistance;
}

double rightEchoDistance()
{
  pinMode(RIGHT_TRIG, OUTPUT); // trigger
  pinMode(RIGHT_ECHO, INPUT);  // echo
  clock_t startTime, endTime;

  digitalWrite(RIGHT_TRIG, HIGH);
  delay(10);
  digitalWrite(RIGHT_TRIG, LOW);

  // loops used to calculate start and end time of echo signal
  while(digitalRead(RIGHT_ECHO) == 0) { startTime = clock(); }
  while(digitalRead(RIGHT_ECHO) == 1) { endTime = clock(); }

  // used to calculate seconds from clock ticks per seconds
  double elapsedTime = ((double)endTime - startTime) / CLOCKS_PER_SEC;

  // convert distance to centimeters and
  // divides by 2 to get rid of round trip distance
  double finalDistance = (elapsedTime * SPEED_OF_SOUND) / 2;
  return finalDistance;
}
