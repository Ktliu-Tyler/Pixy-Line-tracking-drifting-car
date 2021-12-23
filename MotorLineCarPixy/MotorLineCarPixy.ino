#include <Pixy2.h>
#include <SoftwareSerial.h> // 引用「軟體序列埠」程式庫
SoftwareSerial BT(3, 2); // 設定軟體序列埠(接收腳, 傳送腳)
Pixy2 pixy;

char command; // 接收序列埠值的變數
const byte EA = 9;
const byte M1 = 4;
const byte M2 = 5;
const byte M3 = 6;
const byte M4 = 7;
const byte EB = 10;

// 設定 PWM 輸出值
const int speedHigh = 50;
const int speedTurn = 150;
const int speedforward = 80;
const int speedLow = 30;

void stop() { // 馬達停止
  analogWrite(EA, 0); // 馬達 A 的 PWM 輸出
  analogWrite(EB, 0); // 馬達 B 的 PWM 輸出
}
void forward() { // 馬達轉向：前進
  analogWrite(EA, speedHigh); // 馬達 A 的 PWM 輸出
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  analogWrite(EB, speedHigh); // 馬達 A 的 PWM 輸出
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
}
void backward() { // 馬達轉向：後退
  analogWrite(EA, speedHigh); // 馬達 A 的 PWM 輸出
  digitalWrite(M2, HIGH);
  digitalWrite(M1, LOW);
  analogWrite(EB, speedHigh); // 馬達 A 的 PWM 輸出
  digitalWrite(M4, HIGH);
  digitalWrite(M3, LOW);
}
void turnRight() { // 馬達轉向：右轉
  analogWrite(EA, speedTurn); // 馬達 A 的 PWM 輸出
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  analogWrite(EB, speedLow+10); // 馬達 A 的 PWM 輸出
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
}
void turnLeft() { // 馬達轉向：左轉
  analogWrite(EA, speedLow+10); // 馬達 A 的 PWM 輸出
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  analogWrite(EB, speedTurn); // 馬達 A 的 PWM 輸出
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
}
void littleRight() { // 馬達微調轉向：右轉
  analogWrite(EA, speedHigh+10); // 馬達 A 的 PWM 輸出
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  analogWrite(EB, speedLow); // 馬達 A 的 PWM 輸出
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
}
void littleLeft() { // 馬達微調轉向：左轉
  analogWrite(EA, speedLow); // 馬達 A 的 PWM 輸出
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  analogWrite(EB, speedHigh+10); // 馬達 A 的 PWM 輸出
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
}

void setup() {
  Serial.begin(115200);
  Serial.print("Starting...\n");
  pixy.init();
  pixy.setLamp(1, 1);
  Serial.println(pixy.changeProg("line"));
  pinMode(EA, OUTPUT);
  pinMode(EB, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
  stop();
}

void moveCar(int Hx,int Hy, int Tx, int Ty) {
  if ((Hx - Tx) > 15 && (Hx + Tx)/2 > 43) {
    Serial.println("Turn Right\n");
    turnRight();
  } else if ((Hx - Tx) < -15 && (Hx + Tx)/2 < 35) {
    Serial.println("Turn Left\n");
    turnLeft();
  } else if ((Hx + Tx)/2 > 41) {
    Serial.println("little Right\n");
    littleRight();
  } else if ((Hx + Tx)/2 < 37) {
    Serial.println("little Left\n");
    littleLeft();
  } else {
    Serial.println("Forward\n");
    forward();
  }
}

void loop() {
  int8_t i;
  uint8_t Hx, Hy, Tx, Ty;
  char buf[128];
  pixy.line.getAllFeatures();
  pixy.line.vectors[0].print();
  Hx = pixy.line.vectors[0].m_x1;
  Hy = pixy.line.vectors[0].m_y1;
  Tx = pixy.line.vectors[0].m_x0;
  Ty = pixy.line.vectors[0].m_y0;
  if ((Hy - Ty)< 0) {
    moveCar(Hx, Hy, Tx, Ty);
  }else if((Hy - Ty)> 0){
    moveCar(Tx, Ty, Hx, Hy);
  }else {
    stop();
  }
}
