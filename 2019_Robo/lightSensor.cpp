#include "lightSensor.h"

int getFrontLightVal() {
  return analogRead(FRONT_IN_LIGHT_PIN);
}
int getBackInLightVal() {
  return analogRead(BACK_IN_LIGHT_PIN);
}
int getBackOutLightVal() {
  return analogRead(BACK_OUT_LIGHT_PIN);
}
int getLeftInLightVal() {
  return analogRead(LEFT_IN_LIGHT_PIN);
}
int getLeftOutLightVal() {
  return analogRead(LEFT_OUT_LIGHT_PIN);
}
int getRightInLightVal() {
  return analogRead(RIGHT_IN_LIGHT_PIN);
}
int getRightOutLightVal() {
  return analogRead(RIGHT_OUT_LIGHT_PIN);
}
 
bool isFrontWhite() {
   return getFrontLightVal() < FRONT_LIGHT_THRES;
}

bool isBackInWhite() {
   return getBackInLightVal() < BACK_IN_LIGHT_THRES;
}
bool isBackOutWhite() {
   return getBackOutLightVal() < BACK_OUT_LIGHT_THRES;
}
bool isLeftInWhite() {
   return getLeftInLightVal() < LEFT_IN_LIGHT_THRES;
}
bool isLeftOutWhite() {
   return getLeftOutLightVal() < LEFT_OUT_LIGHT_THRES;
}
bool isRightInWhite() {
   return getRightInLightVal() < RIGHT_IN_LIGHT_THRES;
}
bool isRightOutWhite() {
   return getRightOutLightVal() < RIGHT_OUT_LIGHT_THRES;
}

void displayLightVals() {
   Serial.println("=================== light sensor values: ==================="); 
   Serial.println();
   Serial.println("     front |  back_in  |  back_out  |  left_in  | left_out  |  right_in  |  right_out");
   Serial.print("     ");
   Serial.print(getFrontLightVal());
   Serial.print("    |");
   Serial.print("  ");
   Serial.print(getBackInLightVal());
   Serial.print("    |");
   Serial.print("  ");
   Serial.print(getBackOutLightVal());
   Serial.print("    |");
   Serial.print("  ");
   Serial.print(getLeftInLightVal());
   Serial.print("    |");
   Serial.print("  ");
   Serial.print(getLeftOutLightVal());
   Serial.print("    |");
   Serial.print("  ");
   Serial.print(getRightInLightVal());
   Serial.print("    |");
   Serial.print("  ");
   Serial.println(getRightOutLightVal());
   Serial.println();
}
