#include <SoftwareSerial.h>
#include "directives.h"
#include "Button.h"
#include "Motion.h"

int rx[8] = {0};
int i = 0;
int acc = 300; //acceleration

void setup() {
  // put your setup code here, to run once:
  Serial3.begin(115200);
  Serial2.begin(115200);
  Serial.begin(115200);
  //Acceleration
  Serial2.print("A1");Serial2.println(acc);Serial2.print("\r");
  Serial2.print("A2");Serial2.println(acc);Serial2.print("\r");
  Serial2.print("A3");Serial2.println(acc);Serial2.print("\r");
  Serial2.print("A4");Serial2.println(acc);Serial2.print("\r");
  //Speed
  Serial2.print("S1");Serial2.println(stp);Serial2.print("\r");
  Serial2.print("S2");Serial2.println(stp);Serial2.print("\r");
  Serial2.print("S3");Serial2.println(stp);Serial2.print("\r");
  Serial2.print("S4");Serial2.println(stp);Serial2.print("\r");

  pinMode(Gap_DIR, OUTPUT);
  pinMode(Gap_PWM, OUTPUT);
  pinMode(UpDown_DIR, OUTPUT);
  pinMode(UpDown_PWM, OUTPUT);

  analogWrite(Gap_PWM, 0);
  analogWrite(UpDown_PWM, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial3.available() > 0) {
    if(Serial3.read() == -1){
      Serial.println("Buffer error: no data");
      Stop();
    }
    for(i=0;i<8;i++){
      rx[i] = Serial3.read();
      Serial.print(rx[i]);
      Serial.print(" ");
    }
    Serial.println();
    Leftjoystick(rx);
    Button(rx);
    //Ensure Serial2 TX buffer is empty before executing next instruction set. Not strictly necessary but may reduce errors.
    //Serial2.flush();
  }
}
