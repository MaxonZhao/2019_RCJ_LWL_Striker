#include <Arduino.h>

#ifndef WHITELINE_H
#define WHITELINE_H

#define backTimer 450
#define backTimer2 200
#define whiteLineSpeed_out 65

bool OnWhiteLineIn();
bool OnWhiteLineOut();
bool OnWhiteLine();
int avoidWhiteLine1();
int avoidWhiteLine2();
int getAvoidWhiteLineDir();
void blocked();
void forceStop ();
#endif
