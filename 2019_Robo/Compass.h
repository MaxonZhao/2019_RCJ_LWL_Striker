#include <Arduino.h> 

#ifndef COMPASS_H
#define COMPASS_H

static const int COMPASS_PIN = 4;    
static const int compass_max_value = 481;
static const int compass_adjustment_max_speed = 60;

int getCompassVal();
float Angular_PID(float Exp, float Act);
float reposition(int angle);

#endif
