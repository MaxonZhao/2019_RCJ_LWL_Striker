#include "go_back_default_pos.h"
#include "Ultrasound.h"
#include "Motor.h"

int areaNumber = 21;

int getAreaNumber(){

//  if (isBlockedHorizontally()) {
////     Serial.println("blocked");
//     return areaNumber;
//  }
  if (getLeftUltra() <= left_ultra_thres[0] || getRightUltra() >= right_ultra_thres[0]) {
     if (getBackLeftUltra() <= back_left_ultra_thres[4]) {
           if (getBackLeftUltra() <= back_left_ultra_thres[3] ) {
               areaNumber = 11;
               return 11;
           } else {
               areaNumber = 12;
               return 12;
           }  
     } else {
          if (getBackLeftUltra() <= back_left_ultra_thres[5]) {
               areaNumber = 13;
               return 13;
           } else {
               areaNumber = 14;
               return 14;
           }  
     } 
  } else if (getLeftUltra() <= left_ultra_thres[1] || getRightUltra() >= right_ultra_thres[1]){  
     if (getBackLeftUltra() <= back_left_ultra_thres[1]) {
           if (getBackLeftUltra() <= back_left_ultra_thres[0]) {
               areaNumber = 21;
               return 21;
           } else {
               areaNumber = 22;
               return 22;
           }  
     } else {
          if (getBackLeftUltra() <= back_left_ultra_thres[2]) {
               areaNumber = 23;
               return 23;
           } else {
               areaNumber = 24;
               return 24;
           }  
     } 
  } else {
     if (getBackLeftUltra() <= back_left_ultra_thres[4]) {
           if (getBackLeftUltra() <= back_left_ultra_thres[3]) {
               areaNumber = 31;
               return 31;
           } else {
               areaNumber = 32;
               return 32;
           }  
     } else {
          if (getBackLeftUltra() <= back_left_ultra_thres[5]) {
               areaNumber = 33;
               return 33;
           } else {
               areaNumber = 34;
               return 34;
           }  
     } 
  }
}

int getAreaNumber_striker() {
//
  if (isBlockedHorizontally()) {
//     Serial.println("blocked");
     return areaNumber;
  }
  if (getLeftUltra() <= left_ultra_thres[0] || getRightUltra() >= right_ultra_thres[0]) {
     if (getBackLeftUltra() <= back_left_ultra_striker_thres[4]) {
           if (getBackLeftUltra() <= back_left_ultra_striker_thres[3]) {
               areaNumber = 11;
               return 11;
           } else {
               areaNumber = 12;
               return 12;
           }  
     } else {
          if (getBackLeftUltra() <= back_left_ultra_striker_thres[5]) {
               areaNumber = 13;
               return 13;
           } else {
               areaNumber = 14;
               return 14;
           }  
     } 
  } else if (getLeftUltra() <= left_ultra_thres[1] || getRightUltra() >= right_ultra_thres[1]){  
     if (getBackLeftUltra() <= back_left_ultra_striker_thres[1] + 10) {
           if (getBackLeftUltra() <= back_left_ultra_thres[0] + 15) {
               areaNumber = 21;
               return 21;
           } else {
               areaNumber = 22;
               return 22;
           }  
     } else {
          if (getBackLeftUltra() <= back_left_ultra_striker_thres[2]) {
               areaNumber = 23;
               return 23;
           } else {
               areaNumber = 24;
               return 24;
           }  
     } 
  } else {
     if (getBackLeftUltra() <= back_left_ultra_thres[4] + 10) {
           if (getBackLeftUltra() <= back_left_ultra_striker_thres[3]) {
               areaNumber = 31;
               return 31;
           } else {
               areaNumber = 32;
               return 32;
           }  
     } else {
          if (getBackLeftUltra() <= back_left_ultra_striker_thres[5]) {
               areaNumber = 33;
               return 33;
           } else {
               areaNumber = 34;
               return 34;
           }  
     } 
  }
}

void go_back_default_pos() {
   int area = getAreaNumber();
   if (area == 21) {
      if (getBackLeftUltra() > 18) { 
        if (getBackLeftUltra() > 26) move(180,backSpeed*0.2);
        else {
          if (getLeftUltra() > 110 && getLeftUltra() < 130 || getRightUltra() > 110 && getRightUltra() < 130) move(0,0); 
          else if (getLeftUltra() < 110 || getRightUltra() > 130) move(90,backSpeed*0.2);
          else if (getLeftUltra() > 130 || getRightUltra() < 110) move(270,backSpeed*0.2);
        }
      } else {
        move(0,backSpeed*0.2);
      }
   }
   else if (area == 22) move(180, backSpeed*0.6);
   else if (area == 23) move(180, backSpeed*0.9);
   else if (area == 24) move(180, backSpeed); 
   else if (area == 11) {
      if (getBackLeftUltra() > 72) move(85,backSpeed*0.6);  
      else {
         int dir;
         dir = 82 - abs(72 - getBackLeftUltra())*1.95;
         move(dir,backSpeed*0.6);   
      } 
//      move(85,backSpeed*0.6);
   }
   else if (area == 12) move(100, backSpeed*0.9);
   else if (area == 13) move(135, backSpeed);  
   else if (area == 14) move(135, backSpeed);  
   else if (area == 31) {
      if (getBackLeftUltra() > 72) move(275, backSpeed*0.6);  
      else {
         int dir;
         dir = 278 + abs(72 - getBackLeftUltra())*1.95;
//         Serial.println(dir);
         move(dir,backSpeed*0.6);
      }
//      move(275, backSpeed*0.6);
   }
   else if (area == 32) move(260, backSpeed*0.9);  
   else if (area == 33) move(225, backSpeed);  
   else if (area == 34) move(225, backSpeed);  
}


void go_back_default_pos_striker() {
   int area = getAreaNumber_striker();
   if (area == 22) {
       if (getLeftUltra() > 110 && getLeftUltra() < 130 || getRightUltra() > 110 && getRightUltra() < 130) {
          if (getBackLeftUltra() < 70 && getBackLeftUltra() > 44) move(0,0); 
          else if (getBackLeftUltra() < 44) move(0,backSpeed*0.3);
          else if (getBackLeftUltra() > 70) move(180,backSpeed*0.3);
       }
       else if (getLeftUltra() < 110 || getRightUltra() > 130) move(90,backSpeed*0.2);
       else if (getLeftUltra() > 130 || getRightUltra() < 110) move(270,backSpeed*0.2);
   }
   else if (area == 21) move(0, backSpeed*0.8);
   else if (area == 23) move(180, backSpeed*0.8);
   else if (area == 24) move(180, backSpeed); 
   else if (area == 11) {
//      if (getBackLeftUltra() > 72) move(35,backSpeed*0.8);  
//      else {
//         int dir;
//         dir = 82 - abs(72 - getBackLeftUltra())*2.0;
//         move(dir,backSpeed*0.6);   
//      } 
      move(41,backSpeed);
   }
   else if (area == 12) move(90, backSpeed*0.8);
   else if (area == 13) move(135, backSpeed*0.85);  
   else if (area == 14) move(135, backSpeed);  
   else if (area == 31) {
//      if (getBackLeftUltra() > 72) move(275, backSpeed*0.6);  
//      else {
//         int dir;
//         dir = 278 + abs(72 - getBackLeftUltra())*2.0;
////         Serial.println(dir);
//         move(dir,backSpeed*0.6);
//      }
      move(311, backSpeed);
   }
   else if (area == 32) move(270, backSpeed*0.8);  
   else if (area == 33) move(225, backSpeed*0.85);  
   else if (area == 34) move(225, backSpeed);  
}
