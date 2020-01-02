#include "defense_strategy.h"
#include "Ultrasound.h"
#include "Motor.h"
#include "CPEye.h"
#include "go_back_default_pos.h"

int back_ultra_prev = getBackLeftUltra();
float T = millis();
int currentDir = getDir();

bool isOutOfGoal() {
     float dT = (float)(millis() - T)/1000.00; // period
     if (dT > 0.3) {
        T = millis();
        back_ultra_prev = getBackLeftUltra();
     }
     if (getBackLeftUltra() - back_ultra_prev > 30) return true;
     else return false;
}

void defend() {
  int eyePort = getEyePort();
  if (eyePort == 7 || eyePort == 8) move(0,0);
  else if (eyePort <= 3 || eyePort >= 12) go_back_default_pos();
  else {
     if (eyePort < 7) move(270,getEyeValue()*1.32 + 25);
     else if(eyePort > 8) move(90,getEyeValue()*1.32 + 25);
  }
}
