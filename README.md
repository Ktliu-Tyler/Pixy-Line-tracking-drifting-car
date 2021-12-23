# Pixy-Line-tracking-drifting-car
## Author: Tyler  <a href='https://www.instagram.com/ktliu1995/'>(follow my instagram)</a>
### In our project :
```
We use Pixy2 and Arduino to build a line-tracking car that can drifting like a sports car.
```

### Before started :
* Download PixyMon-v2.  (<a href = https://github.com/charmedlabs/pixy2/raw/master/releases/pixymon_windows/pixymon_v2_windows-3.0.24.exe>Download here</a>)
* Download Arduino-ADE. (<a href = https://www.arduino.cc/en/software>Download here</a>)
* Download Pixy2 Arduino library .zip (<a href = https://github.com/charmedlabs/pixy2/raw/master/releases/arduino/arduino_pixy2-1.0.3.zip>Download here</a>)
* Add the Pixy2.zip into your Arduino library.
* Cut a plank of the size you want your car will be like.
* The Arduino Nano is the most important part in this project, it is responsible for your car controlling.
* Prepare N20 motors and wheels for your car.
* Don't forget the L298n motor controller.
* Some Battery like 18650 battery that enough to power your car.

### Build the car :
```
Weild the wires on your motor(N20), use screws to lock your motor, Pixy2, Arduino-Nano, battery on the planks.
Connecting the wire to the right pin.
In1 => pin4
In2 => pin5
In3 => pin6
In4 => pin7
EnA => pin9
EnB => pin10
```

### Set Pixy2 Cam :
```
Connect the Pixy cam to your computer(or laptop) and open the PixyMon-v2 to set your Pixy Cam.
Remenber to change it to the line tracking mode, or you can't access any server from the Pixy Cam built-in functioin.
```

### Start to code :
```
Copy the code on my github and open the MoterLineCarPixy.ino in the forder with Arduino-ADE.
Then, you can build it and upload the code to your Arduino Nano.
```

### Draw your map:
```
Use some paper or tape to build a map that you want to try your car on, the example we provide is using a white line map.
If you want to change another color, you can change it in your PixyMon-v2 settings.
```

### Play with it !!!
```
Keep trying and changing your speed value in the Arduino code.
Once you find your car can turn without any strange problem.
Then that most the best condition of your drifting car !!!
Try more different and rough map !!!
```
### Code detail: (我不想打英文了抱歉)
設定參數以及引入所需的模組與物件
```cpp
#include <Pixy2.h>
#include <SoftwareSerial.h> // 引用「軟體序列埠」程式庫
SoftwareSerial BT(3, 2); // 設定軟體序列埠(接收腳, 傳送腳)
Pixy2 pixy;
char command; // 接收序列埠值的變數

// 設定接線的腳位
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
```
停止所有馬達
```cpp
void stop() { // 馬達停止
  analogWrite(EA, 0); // 馬達 A 的 PWM 輸出
  analogWrite(EB, 0); // 馬達 B 的 PWM 輸出
}
```
馬達前進
```cpp
void forward() { // 馬達轉向：前進
  analogWrite(EA, speedHigh); // 馬達 A 的 PWM 輸出
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  analogWrite(EB, speedHigh); // 馬達 A 的 PWM 輸出
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
}
```
馬達倒退
```cpp
void backward() { // 馬達轉向：後退
  analogWrite(EA, speedHigh); // 馬達 A 的 PWM 輸出
  digitalWrite(M2, HIGH);
  digitalWrite(M1, LOW);
  analogWrite(EB, speedHigh); // 馬達 A 的 PWM 輸出
  digitalWrite(M4, HIGH);
  digitalWrite(M3, LOW);
}
```
車輛右轉
```cpp
void turnRight() { // 馬達轉向：右轉
  analogWrite(EA, speedTurn); // 馬達 A 的 PWM 輸出
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  analogWrite(EB, speedLow+10); // 馬達 A 的 PWM 輸出
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
}
```
車輛左轉
```cpp
void turnLeft() { // 馬達轉向：左轉
  analogWrite(EA, speedLow+10); // 馬達 A 的 PWM 輸出
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  analogWrite(EB, speedTurn); // 馬達 A 的 PWM 輸出
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
}
```
右轉微調
```cpp
void littleRight() { // 馬達微調轉向：右轉
  analogWrite(EA, speedHigh+10); // 馬達 A 的 PWM 輸出
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  analogWrite(EB, speedLow); // 馬達 A 的 PWM 輸出
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
}
```
左轉微調
```cpp
void littleLeft() { // 馬達微調轉向：左轉
  analogWrite(EA, speedLow); // 馬達 A 的 PWM 輸出
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  analogWrite(EB, speedHigh+10); // 馬達 A 的 PWM 輸出
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
}
```
車輛移動指令判斷
```cpp
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
```
Arduino初始化函式
將各pin腳設為OUTPUT
序列埠鮑率設為115200
```cpp
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
```
Arduino迴圈函式
```cpp
void loop() {
  int8_t i;
  uint8_t Hx, Hy, Tx, Ty;
  char buf[128];
  pixy.line.getAllFeatures();
  pixy.line.vectors[0].print();
  Hx = pixy.line.vectors[0].m_x1;//取得Vector的頭部座標X
  Hy = pixy.line.vectors[0].m_y1;//取得Vector的頭部座標y
  Tx = pixy.line.vectors[0].m_x0;//取得Vector的尾部座標X
  Ty = pixy.line.vectors[0].m_y0;//取得Vector的尾部座標Y
  if ((Hy - Ty)< 0) {
    moveCar(Hx, Hy, Tx, Ty);
  }else if((Hy - Ty)> 0){
    moveCar(Tx, Ty, Hx, Hy);
  }else {
    stop();
  }
}
```
<hr>

## 所以說......有將這篇文章看到最後的人...
# **加入附中機研社!!!!!!**
<hr>

### Reference:
* Click me: <a href='https://pixycam.com/'>Pixy.com</a>

* Click me: <a href='https://www.arduino.cc/'>Arduino.cc</a>
* Click me: <a href='https://www.instagram.com/hsnuddrc_4th/'>hsnuddrc</a>

