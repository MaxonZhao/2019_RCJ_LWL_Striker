#include "Motor.h"
float v1;
float v2;
float v3;
float v4;
int Dir = 0;
void setupMotors() {
  pinMode(PWM[1],OUTPUT);
  pinMode(PWM[2],OUTPUT);
  pinMode(DIR[1],OUTPUT);
  pinMode(DIR[2],OUTPUT);
  pinMode(PWM[3],OUTPUT);
  pinMode(PWM[4],OUTPUT);
  pinMode(DIR[3],OUTPUT);
  pinMode(DIR[4],OUTPUT);
  TCCR1B = TCCR1B & B11111000 | B00000010;    // set timer 1 divisor to     8 for PWM frequency of  3921.16 Hz
  TCCR2B = TCCR2B & B11111000 | B00000010;    // set timer 2 divisor to     8 for PWM frequency of  3921.16 Hz
}

void setMotor(int which,float motorSpeed){
  //set one motor


  //protect the motor not to over-speed
  if(motorSpeed > MAX_SPEED){
    motorSpeed = MAX_SPEED;
  }
  else if(motorSpeed < -MAX_SPEED){
    motorSpeed = -MAX_SPEED;
  }
  digitalWrite(DIR[which],motorSpeed>=0?LOW:HIGH);
  analogWrite(PWM[which],motorSpeed>=0?motorSpeed*255/100:255+motorSpeed*255/100);
}

void setMotors(float speed1, float speed2, float speed3, float speed4){
  setMotor(1,-speed1);
  setMotor(2,speed2);
  setMotor(3,-speed3);
  setMotor(4,-speed4);
}

float toRadians(int angle) {
  return (float)angle*PI/180;
}
void move(int direction, float pwm) {
    float u1 = (cos(toRadians(direction))/(2*cos(toRadians(alpha))) - sin(toRadians(direction))/(2*sin(toRadians(alpha))))*pwm;
    float u2 = (sin(toRadians(direction))/(2*sin(toRadians(alpha))) + cos(toRadians(direction))/(2*cos(toRadians(alpha))))*pwm;
    float ratio = 0; 
    if (u1 == 0 && u2 == 0) {
        u1 = 0;
        u2 = 0;
    } else if (u1 == 0 && u2 != 0) {
        u2 = pwm;
    } else if (u1 != 0 && u2 == 0) {
       u1 = pwm; 
    } else if (abs(u1) > abs(u2) ) {
      ratio = abs(u2/u1);
      u1 = pwm*abs(u1)/u1;
      u2 = pwm*ratio*abs(u2)/u2; 
    } else {
      ratio = abs(u1/u2);
      u2 = pwm*abs(u2)/u2;
      u1 = pwm*ratio*abs(u1)/u1; 
    }
    v1 = u1;
    v2 = u2;
    v3 = -u1;
    v4 = -u2; 
    setDir(direction);
//    Serial.print("--------------  ");
//    Serial.print("direction: ");
//    Serial.print(direction);
//    Serial.println("  --------------");
//    Serial.println();
//    Serial.println("v1  |  v2  |  v3  |  v4  ");
//    Serial.print(v1);
//    Serial.print("  |  ");
//    Serial.print(v2);
//    Serial.print("  |  ");
//    Serial.print(v3);
//    Serial.print("  |  ");
//    Serial.println(v4);
}

void setDir(int dir) {
   Dir = dir;
}
int getDir() {
  return Dir;
}
