#include <Arduino.h>

#ifndef BALL_H
#define BALL_H 

#define MAX_BALL_VAL 98
#define MIN_BALL_VAL 10
#define MAX_BALL_DIR 60

const int MAXBALLVAL[14] = {98,70,98,98,98,70};

int gotoBall();  
bool isBallPresent();
void defend_movement();
void around_ball();
void traceBall();
bool holdBall();
void attack();
bool isOnEdge();
void reverseAroundBall();
int getGoalAngle();
#endif
