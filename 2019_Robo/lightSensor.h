#include <Arduino.h> 

#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H 

static const int FRONT_IN_LIGHT_PIN=8;
static const int FRONT_OUT_LIGHT_PIN=8;
static const int BACK_IN_LIGHT_PIN=12;
static const int BACK_OUT_LIGHT_PIN=9;
static const int LEFT_IN_LIGHT_PIN=10;
static const int LEFT_OUT_LIGHT_PIN=6;
static const int RIGHT_IN_LIGHT_PIN=11;
static const int RIGHT_OUT_LIGHT_PIN=7;

static const int FRONT_LIGHT_THRES = 163;
static const int BACK_IN_LIGHT_THRES = 186;
static const int BACK_OUT_LIGHT_THRES = 137;
static const int LEFT_IN_LIGHT_THRES = 151;
static const int LEFT_OUT_LIGHT_THRES = 197;
static const int RIGHT_IN_LIGHT_THRES = 153;
static const int RIGHT_OUT_LIGHT_THRES = 151;

int getFrontInLightVal();
int getFrontOutLightVal();
int getBackInLightVal();
int getBackOutLightVal();
int getLeftInLightVal();
int getLeftOutLightVal();
int getRightInLightVal();
int getRightOutLightVal();
bool isFrontWhite();
bool isBackInWhite();
bool isBackOutWhite();
bool isLeftInWhite();
bool isLeftOutWhite();
bool isRightInWhite();
bool isRightOutWhite();
void displayLightVals();

#endif
