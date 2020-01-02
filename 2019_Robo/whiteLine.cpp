#include "whiteLine.h" 
#include "lightSensor.h"
#include "go_back_default_pos.h"
#include "Compass.h"
#include "Motor.h"
#include "Ultrasound.h"

bool OnWhiteLineOut() {
   if (isBackOutWhite() || isLeftOutWhite() || isRightOutWhite()) return true;
   else return false;
}
bool OnWhiteLineIn() {
   if (isFrontWhite() || isBackInWhite() || isLeftInWhite() || isRightInWhite()) return true;
   else return false;
}
bool OnWhiteLine() {
   return OnWhiteLineOut() || OnWhiteLineIn();
}
int avoidWhiteLine1() {
   if((isLeftInWhite() || isLeftOutWhite()) && isFrontWhite()) {
       float t = millis();
       while(millis() - t < backTimer) {
         float pwm = reposition(0);
         move(135,whiteLineSpeed_out);
         setMotors(v1+pwm,v2+pwm,v3+pwm,v4+pwm);
       }
    }
    else if((isLeftInWhite() || isLeftOutWhite()) && (isBackInWhite() || isBackOutWhite())) {
       float t = millis();
       while(millis() - t < backTimer) {
         float pwm = reposition(0);
         move(45,whiteLineSpeed_out);
         setMotors(v1+pwm,v2+pwm,v3+pwm,v4+pwm);
       }
    }
    else if((isRightInWhite() || isRightOutWhite()) && isFrontWhite()) {
       float t = millis();
       while(millis() - t < backTimer) {
         float pwm = reposition(0);
         move(225,whiteLineSpeed_out);
         setMotors(v1+pwm,v2+pwm,v3+pwm,v4+pwm);
       }
    }
    else if((isRightInWhite() || isRightOutWhite()) && (isBackInWhite() || isBackOutWhite())) {
       float t = millis();
       while(millis() - t < backTimer) {
         float pwm = reposition(0);
         move(315,backSpeed);
         setMotors(v1+pwm,v2+pwm,v3+pwm,v4+pwm);
       }
    } else {
       float t = millis();
       while(millis() - t < backTimer) {
         if (OnWhiteLine()) t = millis();
         float pwm = reposition(0);
         go_back_default_pos();
         setMotors(v1+pwm,v2+pwm,v3+pwm,v4+pwm); 
      } 
   }
}
int avoidWhiteLine2() {
 ;  
}


void blocked() {
        int t = millis();
       if (isBlockedHorizontally() && isBlockedVertically()) move(0,0); 
       else while(millis() - t < 200) {
          float pwm = reposition(0);
//          if (OnWhiteLine()) t = millis(); 
          if (isBlockedHorizontally()) {
              if (getFrontUltra() > getBackLeftUltra()) {
               move(0, 40);
              } else {
                move(180, 40);
             }
          } else {
              if (getLeftUltra() > getRightUltra()) {
                move(270, 40);
              } else {
                move(90, 40);
              } 
          }
          setMotors(v1+pwm,v2+pwm,v3+pwm,v4+pwm); 

       }
}

void forceStop() {
    float t = millis();
    while(millis() - t < 170) {
         float pwm = reposition(0);
         move(0,0);
         setMotors(v1+pwm,v2+pwm,v3+pwm,v4+pwm);
    }}
