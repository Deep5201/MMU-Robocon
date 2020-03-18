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
  Serial.println("Stop");
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

void MoveLeft(){
  Serial2.print("S1");Serial2.println(spd);Serial2.print("\r");
  Serial2.print("S2");Serial2.println(-spd);Serial2.print("\r");
  Serial2.print("S3");Serial2.println(-spd);Serial2.print("\r");
  Serial2.print("S4");Serial2.println(spd);Serial2.print("\r");
  Serial.print("MoveRight");
}

void MoveRight(){
  Serial2.print("S1");Serial2.println(-spd);Serial2.print("\r");
  Serial2.print("S2");Serial2.println(spd);Serial2.print("\r");
  Serial2.print("S3");Serial2.println(spd);Serial2.print("\r");
  Serial2.print("S4");Serial2.println(-spd);Serial2.print("\r");
  Serial.print("MoveLeft");
}

void MoveLeftForward(){
  Serial2.print("S1");Serial2.println(spd);Serial2.print("\r");
  Serial2.print("S2");Serial2.println(stp);Serial2.print("\r");
  Serial2.print("S3");Serial2.println(-spd);Serial2.print("\r");
  Serial2.print("S4");Serial2.println(stp);Serial2.print("\r");
  Serial.print("MoveLeftForward");
}

void MoveRightForward(){
  Serial2.print("S1");Serial2.println(stp);Serial2.print("\r");
  Serial2.print("S2");Serial2.println(spd);Serial2.print("\r");
  Serial2.print("S3");Serial2.println(stp);Serial2.print("\r");
  Serial2.print("S4");Serial2.println(-spd);Serial2.print("\r");
  Serial.print("MoveRightForward");
}

void MoveLeftBackward(){
  Serial2.print("S1");Serial2.println(stp);Serial2.print("\r");
  Serial2.print("S2");Serial2.println(-spd);Serial2.print("\r");
  Serial2.print("S3");Serial2.println(stp);Serial2.print("\r");
  Serial2.print("S4");Serial2.println(spd);Serial2.print("\r");
  Serial.print("MoveLeftBackward");
}

void MoveRightBackward(){
  Serial2.print("S1");Serial2.println(-spd);Serial2.print("\r");
  Serial2.print("S2");Serial2.println(stp);Serial2.print("\r");
  Serial2.print("S3");Serial2.println(spd);Serial2.print("\r");
  Serial2.print("S4");Serial2.println(stp);Serial2.print("\r");
  Serial.print("MoveRightBackward");
}

void RotateLeft(){
  Serial2.print("S1");Serial2.println(-spd);Serial2.print("\r");
  Serial2.print("S2");Serial2.println(-spd);Serial2.print("\r");
  Serial2.print("S3");Serial2.println(-spd);Serial2.print("\r");
  Serial2.print("S4");Serial2.println(-spd);Serial2.print("\r");
  Serial.print("Rotate Left");
}

void RotateRight(){
  Serial2.print("S1");Serial2.println(spd);Serial2.print("\r");
  Serial2.print("S2");Serial2.println(spd);Serial2.print("\r");
  Serial2.print("S3");Serial2.println(spd);Serial2.print("\r");
  Serial2.print("S4");Serial2.println(spd);Serial2.print("\r");
  Serial.print("Rotate Right");
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

void Leftjoystick(int rx[]){
  if((rx[2] >= 0 && rx[2] <= 125) && (rx[1] >= 127 && rx[1] <= 129)){
    Forward();   
  }
  else if((rx[2] > 129 && rx[2] <= 255) && (rx[1] >= 127 && rx[1] <= 129)){
    Backward();  
  }
  else if((rx[1] >= 0 && rx[1] <= 125) && (rx[2] >= 127 && rx[2] <= 129)){
    MoveRight();  
  }
  else if((rx[1] > 129 && rx[1] <= 255) && (rx[2] >= 127 && rx[2] <= 129)){
    MoveLeft();  
  }
  
  else if((rx[1] > 0 && rx[1] <= 126) && (rx[2] <= 125 && rx[2] > 0)){
    MoveLeftForward();  
  }
  else if((rx[1] >= 129 && rx[1] <= 255) && (rx[2] >0 && rx[2] <= 127)){
    MoveRightForward();
  }
  else if((rx[1] > 0 && rx[1] <= 126) && (rx[2] >= 129 && rx[2] <= 255)){
    MoveLeftBackward();
  }
  else if((rx[1] >= 129 && rx[1] <= 255) && (rx[2] >= 129 && rx[2] <= 255)){
    MoveRightBackward();  
  }
  
  else if((rx[2] > 125 && rx[2] <= 129) || (rx[1] > 125 && rx[1] <= 129)){
    Stop();  
  }else{
    Stop();
  }
}

#endif
