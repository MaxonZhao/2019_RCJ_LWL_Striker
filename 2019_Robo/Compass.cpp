#include "Compass.h"
#include "PID.h"

PID_Controller PID;

int getCompassVal() {
  return ((long)analogRead(COMPASS_PIN)*360/compass_max_value);
}
float reposition(int angle) { 
   float Vr = 0.00f;
   int CV = getCompassVal(); 
   CV = getCompassVal() - angle;  
    if (CV < 0) CV = 360 + CV;
    if(CV < 180) { 
       Vr = Angular_PID(0.000f, CV);
    }
    else {
        Vr = Angular_PID(360.000f, CV);
    }
    return Vr;
}



float Angular_PID(float Exp, float Act) {
    float dT = (float)(millis() - PID.T)/1000.00; // period
    //-------P--------//
    PID.Ep = Exp - Act;
    float P = PID.Kp * PID.Ep; 
    
    if(dT > 0.01) { // 0.01 second 
        PID.pExp = Exp;
        PID.pAct = Act;
        PID.T = millis();
        return P + PID.I + PID.D;
    }
    //-------I--------//
    if(PID.pExp != Exp)PID.integral = 0.00;
    PID.integral += (((Exp - Act) + (PID.pExp - PID.pAct)) / 2.0) * dT ;  // average value of error
    float I = PID.Ki * PID.integral;
    //-------D--------//
    float D = 0;
    //----update-----//
    PID.pExp = Exp;
    PID.pAct = Act;
    PID.T = millis();
    //----return-----//
    PID.P = P; PID.I = I; PID.D = D;
    return (P + I + D);
    //return P;
}
