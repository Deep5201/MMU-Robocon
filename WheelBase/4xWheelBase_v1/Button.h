#include "Motion.h"
#include "directives.h"

#ifndef BUTTON_H
#define BUTTON_H

const int right_mode = 124;
const int wrong_mode = 116;

void Button(int rx[]){
  
  if(rx[7] == wrong_mode){              //check if controller is in the right mode
    Serial.println("Change mode!");
    return;
    
  }else if(rx[7] == right_mode){
    
    LeftJoystick(rx[5]);
    
    if (rx[0] == 1 && rx[1] == 128 && rx[2] == 127 && rx[3] == 128 && rx[4] == 127 && rx[5] == 8 && rx[6] == 0 && rx[7] == right_mode) {
    Serial.print("No input");
    Serial.println();
    Stop();
    }
  
    if (rx[5] == 72) {
      Serial.print("Button B");
      Serial.println();
      MoveRightForward();
    }
  
    if (rx[5] == 40) {
      Serial.print("Button A");
      Serial.println();
      MoveLeftBackward();
    }
    
    if (rx[5] == 136) {
      Serial.print("Button Y");
      Serial.println();
      MoveRightBackward();
    }
  
    if (rx[5] == 24) {
      Serial.print("Button X");
      Serial.println();
      MoveLeftForward();
      
    }
  
    /*if (rx[5] == 104) {
      Serial.print("Button A+B");
      Serial.println();
      }*/
  
    /*if (rx[5] == 56) {
      Serial.print("Button A+X");
      Serial.println();
      }*/
  
    /*if (rx[5] == 152) {
      Serial.print("Button X+Y");
      Serial.println();
      }*/
  
    /*if (rx[5] == 200) {
      Serial.print("Button Y+B");
      Serial.println();
      }*/
  
    if (rx[1] == 0) {
      Serial.print("Button Left");
      Serial.println();
      MoveLeft();
    }
  
    if (rx[1] == 255) {
      Serial.print("Button Right");
      Serial.println();
      MoveRight();
    }
  
    if (rx[2] == 0) {
      Serial.print("Button Up");
      Serial.println();
      Forward();
    }
  
    if (rx[2] == 255) {
      Serial.print("Button Down");
      Serial.println();
      Backward();
    }
  
    if (rx[6] == 1) {
      Serial.print("Button LB");
      Serial.println();
      RotateLeft();
    }
  
    if (rx[6] == 2) {
      Serial.print("Button RB");
      Serial.println();
      RotateRight();
    }
  
    if (rx[6] == 4) {
      Serial.print("Button LT");
      Serial.println();
    }
  
    if (rx[6] == 8) {
      Serial.print("Button RT");
      Serial.println();
      Serial.println("Emergency stop!");
      Stop();
    } 
  }
}


#endif
