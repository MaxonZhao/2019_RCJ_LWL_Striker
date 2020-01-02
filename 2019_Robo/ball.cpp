#include "ball.h"
#include "CPEye.h"
#include "Motor.h"
#include "go_back_default_pos.h"
#include "Ultrasound.h"
#include "WhiteLine.h"
#include "Compass.h"
#include "lightSensor.h"
 
int eyeValue = 0;
int eyePort = 0;
int speed = 65;
 bool attackingMode = false;

int gotoBall() { 
    eyePort = getEyePort();  
    int direction = 0;
    if (getEyePort() == 7 || getEyePort() == 8) direction = 0;
//    else direction = (getEyePort() > 8? (getEyePort()- 8)*30+70:((getEyePort()-1)*30 + 180-70));
    else direction = (getEyePort() > 8? (getEyePort()- 8)*30: 360 - (7-getEyePort())*30);
    return direction; 
}
void traceBall() {
  int value = analogRead(A14);
  int d = 0;
  long shift = 120; //the maximum difference in the robot's movement direction within the same ball port
  long eyeMax = 620; //maximum value of ball
  long eyeMin = 20; //minumum value of ball
  long eyeValue = value;//current distance the ball is away from the robot
  int port = getEyePort();
  float ballSpeed;
  int base_dir;

     base_dir = (getEyePort() > 8? (getEyePort()- 8)*30: 360 - (7-getEyePort())*30); 
//    
     if (holdBall()) {
        if (!isBlockedHorizontally()) { 
               attack();
         } 
     }
     if (isOnEdge()) reverseAroundBall();
     else if ((getEyePort() < 4 || getEyePort() > 11) && getBackLeftUltra() < 30) move(0,0); 
     else if (getBackLeftUltra() < 30 && getEyeValue() > 65) gotoBall();
     else if (getEyePort() == 7 || getEyePort() == 8) { 
         d = 0;
         ballSpeed = 100;
      } else {
          if(port>8) //ball on right
        {
//             d = base_dir + 8 + 1.08*constrain(shift * value/eyeMax * base_dir/150, 0, 90);
//             if(getEyeValue() > 82) d += 20; 
                    d = base_dir + constrain(shift * (float)value/eyeMax * base_dir/67.0, 0, 90);
                    if(getEyeValue() > 65 && getEyeValue() < 80) d += getEyeValue()*0.1;
                    else if(getEyeValue() >= 80) d += getEyeValue()*0.15;
                    else if (getEyeValue() < 30) d += 10;
          }
          else //ball on left
          {
//            d = base_dir - 8 - 1.08*constrain(shift * value/eyeMax * (360-base_dir)/140.0, 0, 90);
//            if(getEyeValue() > 82) d -= 20; 
              d = base_dir - constrain(shift * (float)value/eyeMax * (360-base_dir)/67.0, 0, 90); 
              if(getEyeValue() > 65 && getEyeValue() < 80) d -= getEyeValue()*0.1;
              else if(getEyeValue() >= 80) d -= getEyeValue()*0.17;
              else if (getEyeValue() < 30) d -= 10;

          }   
          ballSpeed = abs(MAX_BALL_VAL - getEyeValue())*0.78 + 35;
      }
//      Serial.print(getEyeValue());
      move(d,ballSpeed);

//        Serial.println("  direction  |  speed  |");
//    Serial.print("     ");
//    Serial.print(d);
//    Serial.print("     |  ");
//    Serial.println(ballSpeed);
//    Serial.println();
}

bool isBallPresent() {
  return getEyeValue() > 5;
}

bool holdBall() {
  return (getEyeValue() >= 84 && (getEyePort() == 7 || getEyePort() == 8));
}


void attack() {
    int area = getAreaNumber();
    int dir = 0;
    int dis = getFrontUltra();
    if (dis>240) dis = 240; 
    if (area/10 == 2) {attackingMode = false; dir = 0;}
    else if (area/10==1)  { // area is in column 1
        attackingMode = true;
        dir = (240-dis)*0.55; 
        if (getFrontUltra() > 180) dir+=10;   
        if (dir > 45) dir = 45;
    } else { // area is in column 3
        attackingMode = true; 
        dir = 360 - (240-dis)*0.55;
        if (getFrontUltra() > 180) dir-=10;  
        if (dir < 315) dir = 315;
    } 
//    Serial.println(dir);

    if (attackingMode== true) { 
       while(getEyeValue() > 80 && (getEyePort() ==7 || getEyePort() ==8)) { 
         int Vr = reposition(dir);
//         if (OnWhiteLine()) break;
         if (isBackInWhite()) break;
         else {
            move(0,90);
            setMotors(v1+Vr,v2+Vr,v3+Vr,v4+Vr);
         }
       } 
    }
}

bool isOnEdge() {
  return (getEyePort() < 4 && getRightUltra() < 80) || (getEyePort() > 11 && getLeftUltra() < 80);
}

void reverseAroundBall() {
   if (getEyePort() < 4 && getRightUltra() < 80) {
//       Serial.println("near right edge");
      if (getEyeValue() > 62) {
          while(getRightUltra() < 94 && getEyePort() < 4) {
             float Vr = reposition(0);
             if (OnWhiteLine()) break;
             else move(260,60); 
             setMotors(v1+Vr,v2+Vr,v3+Vr,v4+Vr);
          }
      }
    } else if (getEyePort() > 11 && getLeftUltra() < 80) {
//      Serial.println("near left edge");
        if (getEyeValue() > 62) {
          while(getLeftUltra() < 94 && getEyePort() > 11) {
            float Vr = reposition(0);
            if (OnWhiteLine()) break;
            else move(100,60);
            setMotors(v1+Vr,v2+Vr,v3+Vr,v4+Vr);
          }
        }
    }
}

int getGoalAngle() {
   int area = getAreaNumber_striker();
   int dir = 0;
   int dis = getFrontUltra();
   if (dis>240) dis = 240;  
   if (area/10 == 2) {attackingMode = false; dir = 0;}
    else if (area/10==1)  { 
        attackingMode = true;
        dir = (240-dis)*0.4; 
        if (getFrontUltra() > 160) dir+=10;   
    } else {
        attackingMode = true; 
        dir = 360 - (240-dis)*0.4;
         if (getFrontUltra() > 160) dir-=10;  
    } 
    return dir;
}
