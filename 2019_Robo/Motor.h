#include <Arduino.h>


#ifndef Motor_H
#define Motor_H


#define MAX_SPEED 90
#define alpha 50
#define PI 3.1416

extern int Dir;
extern float v1;
extern float v2;
extern float v3;
extern float v4;
static int PWM[5] = {0,9,10,11,12};// pin number of motor 1,2,3,4's pwm
static int DIR[5] = {0,25,26,27,28};// pin number of motor 1,2,3,4's direction

float toRadians(int angle);
void setupMotors();
void setMotor(int, float);
void setMotors(float,float,float,float);  
void move(int, float);
void setDir(int dir);
int getDir();

#endif
