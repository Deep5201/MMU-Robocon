#include "directives.h"
#include "Button.h"

int rx[8] = {0};
int i = 0;

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
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial3.available()) {
    for(i=0;i<8;i++){
      rx[i] = Serial3.read();
      Serial.print(rx[i]);
      Serial.print(" ");
    }
    Serial.println();
    
    /*
    If the last byte is -1, there is some error in the entire input byte array.
    In that case issue a warning and stop all motion.
    */     
    if(rx[7] == -1){
      Serial.println("Warning: Bad input");
      Stop();
    }else if(rx[7] != -1){
      Button(rx);
    }
    
    //Ensure Serial2 Tx buffer is empty before executing next instruction set. Not strictly necessary but may reduce errors.
    //Serial2.flush();
  }
  /*
  The delay gives time for the program to recieve every byte in from the controller input and issue the relevant commands
  before the next loop starts, thus making the controller input much less error-prone.
  */
  delay(100);
}
