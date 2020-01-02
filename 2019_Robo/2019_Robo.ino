#include "Motor.h"
#include "Compass.h"
#include "PID.h"
#include "Ultrasound.h"
#include "CPEye.h"
#include "ball.h"
#include "go_back_default_pos.h"
#include "whiteLine.h"
#include "lightSensor.h"
#include "defense_strategy.h"

#include <Arduino.h>

 
void setup() {  
  Serial.begin(9600);
  setupMotors();
  initializeJoinmaxEye(0);
  initializeJoinmaxEye(1);
}  


void loop() {
   
   float Kp = 0.8;
   float Ki = 1.65;
   float Kd = 0.0;
   float Exp = 0.0;
   float Act = (float)getCompassVal();
   float Vr = 0.0;
   PID_init(Kp, Ki, Kd, Exp, Act);

   
   while(1) { 
      getAreaNumber_striker();
      Vr = reposition(0);
      if (OnWhiteLine()) { 
         setMotors(0,0,0,0);
         avoidWhiteLine1(); 
      } else {
           if (isBallPresent()) { 
                traceBall();
          } else {
            go_back_default_pos_striker();
          }
      }
      setMotors(Vr+v1,Vr+v2,Vr+v3,Vr+v4);
   }
}
