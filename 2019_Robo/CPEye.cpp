#include "CPEye.h"
#include <Wire.h>

void tcaselect(uint8_t i) {
  if (i > 7) return;
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}

void initializeJoinmaxEye(int which)
{
  tcaselect(which);
  int i;
  Wire.begin();
  Wire.beginTransmission(0x01);
  Wire.write(0x0e);
  Wire.endTransmission();
  while(Wire.available() > 0)
    i = Wire.read();
    Serial.println("reading");
    Serial.println(i);
}

int joinmaxEyePort(int which){
  tcaselect(which);
  Wire.begin();
  Wire.beginTransmission(0x01);//address for compound eye
  Wire.write(0x08);
  Wire.endTransmission();
  //Serial.print("port: ");
  Wire.requestFrom(0x01,1);
  while(Wire.available()){
    int i = Wire.read();
    return i;
  }
}

int joinmaxEyeValue(int which){
  tcaselect(which);
  Wire.begin();
  Wire.beginTransmission(0x01);
  Wire.write(0x09);
  Wire.endTransmission();
  //Serial.print("value:");
  Wire.requestFrom(0x01,1);
  while(Wire.available()){
    int i = Wire.read();
    return i;
  }
}

int getEyePort(){ 
  int rawPort = analogRead(A13);
  int eyePort;
  if(rawPort<40) eyePort=1;//+40
  else if(rawPort<=67.5) eyePort=2;//+27.5
  else if(rawPort<=95) eyePort=3;//+27.5
  else if(rawPort<=122.5) eyePort=4;//+27.5
  else if(rawPort<=150) eyePort=5;//+27.5
  else if(rawPort<=178) eyePort=6;//+28
  else if(rawPort<=208) eyePort=7;//+30
  else if(rawPort<=238) eyePort=8;//+30
  else if(rawPort<=266) eyePort=9;//+28
  else if(rawPort<=294) eyePort=10;//+28
  else if(rawPort<=322) eyePort=11;//+28   
  else if(rawPort<=350) eyePort=12;//+28
  else if(rawPort<=377) eyePort=13;//+27
  else eyePort=14; 
  return eyePort;
}

int getEyeValue() {
  return map(analogRead(A14),2,630,0,100);
}
