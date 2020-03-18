#include <SoftwareSerial.h>

#ifndef BUTTON_H
#define BUTTON_H

#include "Motion.h"
#include "directives.h"

int tempRead1;
int tempRead2;

//FrontLeft == S2
//FrontRight == S3
//RearLeft == S1
//RearRight == S4

void Button(int rx[]) {
  if (rx[0] == -1 && rx[1] == 128 && rx[2] == 127 && rx[3] == 128 && rx[4] == 127 && rx[5] == 8 && rx[6] == 0 && rx[7] == 124) {
    Serial.print("No input");
    Serial.println();
    Stop();
  }
  
  if (rx[5] == 72) {
    Serial.print("Button B");
    Serial.println();
    //MoveRightForward();
    GapMotorOpen();
  }

  if (rx[5] == 40) {
    Serial.print("Button A");
    Serial.println();
    //MoveLeftBackward();
    Motor_Down();
  }
  
  if (rx[5] == 136) {
    Serial.print("Button Y");
    Serial.println();
    //MoveRightBackward();
    Motor_Up();
  }

  if (rx[5] == 24) {
    Serial.print("Button X");
    Serial.println();
    //MoveLeftForward();
    GapMotorClose();
  }

  if (rx[5] == 104) {
    Serial.print("Button A+B");
    Serial.println();
  }

  if (rx[5] == 56) {
    Serial.print("Button A+X");
    Serial.println();
  }

  if (rx[5] == 152) {
    Serial.print("Button X+Y");
    Serial.println();
   }

  if (rx[5] == 200) {
    Serial.print("Button Y+B");
    Serial.println();
   }

  if (rx[5] == 2) {
    Serial.print("Button Left");
    Serial.println();
    MoveLeft();
  }

  if (rx[5] == 6) {
    Serial.print("Button Right");
    Serial.println();
    MoveRight();
  }

  if (rx[5] == 0) {
    Serial.print("Button Up");
    Serial.println();
    Forward();
  }

  if (rx[5] == 4) {
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
    Stop();
  }
}

#endif
