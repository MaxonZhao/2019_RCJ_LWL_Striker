#include "PID.h"

void PID_init(float Kp, float Ki, float Kd, float Exp, float Act) {
    PID.Kp = Kp;
    PID.Ki = Ki;
    PID.Kd = Kd;
    PID.pExp = Exp;
    PID.pAct = Act;
    PID.integral = 0.000f;
    PID.P = Kp * (Exp - Act); 
    PID.I = 0.000f; 
    PID.D = 0.000f;
    PID.T = millis();
}
