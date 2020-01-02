#include "Ultrasound.h"

int getLeftUltra(){
  return analogRead(LEFT_ULTRA_PIN);
}

int getRightUltra(){
  return analogRead(RIGHT_ULTRA_PIN);
}

int getFrontUltra(){
  return analogRead(FRONT_ULTRA_PIN);
}

int getBackRightUltra(){
  return analogRead(BACK_RIGHT_ULTRA_PIN);
}

int getBackLeftUltra(){
  return analogRead(BACK_LEFT_ULTRA_PIN);
}

bool isBlocked() {
  return isBlockedHorizontally() || isBlockedVertically();
}
bool isBlockedHorizontally() {
   return getLeftUltra() + getRightUltra() < 240;
}
bool isBlockedVertically() {
   return getFrontUltra() + getBackLeftUltra() < 305; 
}

void displayUltraValues() {
   Serial.print("front ultra: ");    
   Serial.print(getFrontUltra());
   Serial.print("  ");
   Serial.print("back left ultra: ");
   Serial.print(getBackLeftUltra());
   Serial.print("  ");
   Serial.print("back right ultra: ");
   Serial.println(getBackRightUltra());
   Serial.print("left ultra: ");
   Serial.print(getLeftUltra());
   Serial.print("  ");
   Serial.print("right ultra: ");
   Serial.println(getRightUltra());
   Serial.println();
   delay(300);
}
