#include <Arduino.h> 

#ifndef CPEYE_H
#define CPEYE_H

//I2C ADDRESSES
#define TCAADDR 0x70

void tcaselect(uint8_t i); 
void initializeJoinmaxEye(int which); 
int joinmaxEyePort(int which);
int joinmaxEyeValue(int which);
int getEyePort();
int getEyeValue();

#endif   
