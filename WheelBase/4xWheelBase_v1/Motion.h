#include <SoftwareSerial.h>

#ifndef MOTION_H
#define MOTION_H

#include "directives.h"

int spd = 200; //speed
int stp = 0; //stop

void Stop(){
  Serial2.print("S1");Serial2.println(stp);Serial2.print("\r");
  Serial2.print("S2");Serial2.println(stp);Serial2.print("\r");
  Serial2.print("S3");Serial2.println(stp);Serial2.print("\r");
  Serial2.print("S4");Serial2.println(stp);Serial2.print("\r");
  Serial.println("Stopped.");
}


void Forward(){
  Serial2.print("S1");Serial2.println(spd);Serial2.print("\r");
  Serial2.print("S2");Serial2.println(spd);Serial2.print("\r");
  Serial2.print("S3");Serial2.println(-spd);Serial2.print("\r");
  Serial2.print("S4");Serial2.println(-spd);Serial2.print("\r");
  Serial.println("Forward");
}

void Backward(){
  Serial2.print("S1");Serial2.println(-spd);Serial2.print("\r");
  Serial2.print("S2");Serial2.println(-spd);Serial2.print("\r");
  Serial2.print("S3");Serial2.println(spd);Serial2.print("\r");
  Serial2.print("S4");Serial2.println(spd);Serial2.print("\r");
  Serial.println("Backward");
}

void MoveRight(){
  Serial2.print("S1");Serial2.println(spd);Serial2.print("\r");
  Serial2.print("S2");Serial2.println(-spd);Serial2.print("\r");
  Serial2.print("S3");Serial2.println(-spd);Serial2.print("\r");
  Serial2.print("S4");Serial2.println(spd);Serial2.print("\r");
  Serial.println("MoveRight");
}

void MoveLeft(){
  Serial2.print("S1");Serial2.println(-spd);Serial2.print("\r");
  Serial2.print("S2");Serial2.println(spd);Serial2.print("\r");
  Serial2.print("S3");Serial2.println(spd);Serial2.print("\r");
  Serial2.print("S4");Serial2.println(-spd);Serial2.print("\r");
  Serial.println("MoveLeft");
}

void MoveLeftForward(){
  Serial2.print("S1");Serial2.println(spd);Serial2.print("\r");
  Serial2.print("S2");Serial2.println(stp);Serial2.print("\r");
  Serial2.print("S3");Serial2.println(-spd);Serial2.print("\r");
  Serial2.print("S4");Serial2.println(stp);Serial2.print("\r");
  Serial.println("MoveLeftForward");
}

void MoveRightForward(){
  Serial2.print("S1");Serial2.println(stp);Serial2.print("\r");
  Serial2.print("S2");Serial2.println(spd);Serial2.print("\r");
  Serial2.print("S3");Serial2.println(stp);Serial2.print("\r");
  Serial2.print("S4");Serial2.println(-spd);Serial2.print("\r");
  Serial.println("MoveRightForward");
}

void MoveLeftBackward(){
  Serial2.print("S1");Serial2.println(stp);Serial2.print("\r");
  Serial2.print("S2");Serial2.println(-spd);Serial2.print("\r");
  Serial2.print("S3");Serial2.println(stp);Serial2.print("\r");
  Serial2.print("S4");Serial2.println(spd);Serial2.print("\r");
  Serial.println("MoveLeftBackward");
}

void MoveRightBackward(){
  Serial2.print("S1");Serial2.println(-spd);Serial2.print("\r");
  Serial2.print("S2");Serial2.println(stp);Serial2.print("\r");
  Serial2.print("S3");Serial2.println(spd);Serial2.print("\r");
  Serial2.print("S4");Serial2.println(stp);Serial2.print("\r");
  Serial.println("MoveRightBackward");
}

void RotateLeft(){
  Serial2.print("S1");Serial2.println(-spd);Serial2.print("\r");
  Serial2.print("S2");Serial2.println(-spd);Serial2.print("\r");
  Serial2.print("S3");Serial2.println(-spd);Serial2.print("\r");
  Serial2.print("S4");Serial2.println(-spd);Serial2.print("\r");
  Serial.println("Rotate Left");
}

void RotateRight(){
  Serial2.print("S1");Serial2.println(spd);Serial2.print("\r");
  Serial2.print("S2");Serial2.println(spd);Serial2.print("\r");
  Serial2.print("S3");Serial2.println(spd);Serial2.print("\r");
  Serial2.print("S4");Serial2.println(spd);Serial2.print("\r");
  Serial.println("Rotate Right");
}

void LeftJoystick(int dir){
  switch(dir){
    case 0:
      Forward();
      break;
    case 1:
      MoveRightForward();
      break;
    case 2:
      MoveRight();
      break;
    case 3:
      MoveRightBackward();
      break;
    case 4:
      Backward();
      break;
    case 5:
      MoveLeftBackward();
      break;
    case 6:
      MoveLeft();
      break;
    case 7:
      MoveLeftForward();
      break;
    case 8:
      Stop();
      break;
    default:
      Serial.println("Error");
  }
}

void GapMotorOpen() {
  digitalWrite(Gap_DIR, HIGH);
  analogWrite(Gap_PWM, half_speed);
  Serial.println("Open");
}

void GapMotorClose() {
  digitalWrite(Gap_DIR, LOW);
  analogWrite(Gap_PWM, half_speed);
  Serial.println("Close");
}

void Motor_Up() {
  digitalWrite(UpDown_DIR, LOW);
  analogWrite(UpDown_PWM, half_speed);
  Serial.println("Up");
}

void Motor_Down() {
  digitalWrite(UpDown_DIR, HIGH);
  analogWrite(UpDown_PWM, half_speed);
  Serial.println("Down");
}



#endif
