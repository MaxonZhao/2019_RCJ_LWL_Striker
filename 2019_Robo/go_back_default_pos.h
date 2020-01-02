#include <Arduino.h>

#ifndef GO_BACK_DEFAULT_POS.H
#define GO_BACK_DEFAULT_POS.H

static const int left_ultra_thres[2] = {94,159};
static const int right_ultra_thres[2] = {158,90};
static const int front_ultra_thres[6] = {195,117,44,237,153,82};
static const int back_left_ultra_thres[6] = {44,117,195,82,153,237}; 
static const int back_right_ultra_thres[6] = {44,117,195,82,153,237}; 


static const int front_ultra_striker_thres[6] = {195,117,44,237,153,82};
static const int back_left_ultra_striker_thres[6] = {66,112,192,110,172,232}; 

static const int backSpeed = 85;
extern int areaNumber;

int getAreaNumber();  
int getAreaNumber_striker();
void go_back_default_pos();   
void go_back_default_pos_striker();


#endif
