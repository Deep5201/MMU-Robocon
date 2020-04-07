#ifndef HEADER_H
#define HEADER_H

void dec2hex(int input) {
  int temp_quotient = 0;
  int temp_remainder = 0;
  temp_quotient = input / 16;
  temp_remainder = input % 16;
  if (temp_quotient == 10) {
    Serial.print("A");
  }
  else if (temp_quotient == 11) {
    Serial.print("B");
  }
  else if (temp_quotient == 12) {
    Serial.print("C");
  }
  else if (temp_quotient == 13) {
    Serial.print("D");
  }
  else if (temp_quotient == 14) {
    Serial.print("E");
  }
  else if (temp_quotient == 15) {
    Serial.print("F");
  }
  else {
    Serial.print(temp_quotient);
  }

  if (temp_remainder != 0) {
    input = temp_remainder;
    temp_quotient = input % 16;
    if (temp_quotient == 10) {
      Serial.print("A");
    }
    else if (temp_quotient == 11) {
      Serial.print("B");
    }
    else if (temp_quotient == 12) {
      Serial.print("C");
    }
    else if (temp_quotient == 13) {
      Serial.print("D");
    }
    else if (temp_quotient == 14) {
      Serial.print("E");
    }
    else if (temp_quotient == 15) {
      Serial.print("F");
    }
    else {
      Serial.print(temp_remainder);
    }
  }
}

#endif
