#include <Arduino.h>

#ifndef PID_H    
#define PID_H

typedef struct {
    float P, I, D;
    float Ep, Ei, Ed;
    float Kp, Ki, Kd;
    float integral, differential;
    float pExp;
    float pAct;  // p means previous 
    uint64_t T;
} PID_Controller;

extern PID_Controller PID; 
  

void PID_init(float Kp, float Ki, float Kd, float Exp, float Act);

#endif 
