#include <Arduino.h>

#ifndef ULTRASOUND_H
#define ULTRASOUND_H

static const int LEFT_ULTRA_PIN = 0;
static const int RIGHT_ULTRA_PIN = 1;
static const int FRONT_ULTRA_PIN = 2;
static const int BACK_LEFT_ULTRA_PIN = 3; 
static const int BACK_RIGHT_ULTRA_PIN = 15; 


int getLeftUltra();  
int getRightUltra();
int getFrontUltra();
int getBackLeftUltra();
int getBackRightUltra();
void displayUltraValues(); 
bool isBlocked();
bool isBlockedHorizontally();
bool isBlockedVertically();

#endif
