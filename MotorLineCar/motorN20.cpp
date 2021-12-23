#include "motorN20.h"
#include "Arduino.h"


MotorN20::MotorN20(byte EnA, byte In1, byte In2, byte EnB, byte In3, byte In4){
    motorL.push_back(EnA);
    motorL.push_back(In1);
    motorL.push_back(In2);
    motorR.push_back(EnB);
    motorR.push_back(In3);
    motorR.push_back(In4);
}

//void MotorN20::setMotor() {
//  MotorN20(byte EnA, byte In1, byte In2, byte EnB, byte In3, byte In4);
//  for(vector<byte>::iterator i=motorL.begin();i!=motorL.end();++i){
//    pinMode(*i, OUTPUT);
//  }
//  for(vector<byte>::iterator i=motorR.begin();i!=motorR.end();++i){
//    pinMode(*i, OUTPUT);
//  }
//  
//}

void MotorN20::stopMotor() {
  analogWrite(motorL[0], 0); // 馬達 A 的 PWM 輸出
  analogWrite(motorR[0], 0); // 馬達 B 的 PWM 輸出
}

void MotorN20::forward() { // 馬達轉向：前進
  analogWrite(motorL[0], speedHigh); // 馬達 A 的 PWM 輸出
  digitalWrite(motorL[1], HIGH);
  digitalWrite(motorL[2], LOW);
  analogWrite(motorR[0], speedHigh); // 馬達 A 的 PWM 輸出
  digitalWrite(motorR[1], HIGH);
  digitalWrite(motorR[2], LOW);
}
void MotorN20::backward() { // 馬達轉向：後退
  analogWrite(motorL[0], speedHigh); // 馬達 A 的 PWM 輸出
  digitalWrite(motorL[1], HIGH);
  digitalWrite(motorL[2], LOW);
  analogWrite(motorR[0], speedHigh); // 馬達 A 的 PWM 輸出
  digitalWrite(motorR[1], HIGH);
  digitalWrite(motorR[2], LOW);
}
void MotorN20::turnRight() { // 馬達轉向：右轉
  analogWrite(motorL[0], speedHigh); // 馬達 A 的 PWM 輸出
  digitalWrite(motorL[1], HIGH);
  digitalWrite(motorL[2], LOW);
  analogWrite(motorR[0], 0); // 馬達 A 的 PWM 輸出
  digitalWrite(motorR[1], HIGH);
  digitalWrite(motorR[2], LOW);
  delay(1000);
}
void MotorN20::turnLeft() { // 馬達轉向：左轉
  analogWrite(motorL[0], 0); // 馬達 A 的 PWM 輸出
  digitalWrite(motorL[1], HIGH);
  digitalWrite(motorL[2], LOW);
  analogWrite(motorR[0], speedHigh); // 馬達 A 的 PWM 輸出
  digitalWrite(motorR[1], HIGH);
  digitalWrite(motorR[2], LOW);
  delay(1000);
}
void MotorN20::littleRight() { // 馬達微調轉向：右轉
  analogWrite(motorL[0], speedHigh); // 馬達 A 的 PWM 輸出
  digitalWrite(motorL[1], HIGH);
  digitalWrite(motorL[2], LOW);
  analogWrite(motorR[0], speedLow); // 馬達 A 的 PWM 輸出
  digitalWrite(motorR[1], HIGH);
  digitalWrite(motorR[2], LOW);
}
void MotorN20::littleLeft() { // 馬達微調轉向：左轉
  analogWrite(motorL[0], speedLow); // 馬達 A 的 PWM 輸出
  digitalWrite(motorL[1], HIGH);
  digitalWrite(motorL[2], LOW);
  analogWrite(motorR[0], speedHigh); // 馬達 A 的 PWM 輸出
  digitalWrite(motorR[1], HIGH);
  digitalWrite(motorR[2], LOW);
}
