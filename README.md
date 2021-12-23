# Pixy-Line-tracking-drifting-car
## Author: Tyler
### In our project :
    We use Pixy2 and Arduino to build a line-tracking car that can drifting like a sports car.

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
    Weild the wires on your motor(N20), use screws to lock your motor, Pixy2, Arduino-Nano, battery on the planks.
    Connecting the wire to the right pin.
    In1 => pin4
    In2 => pin5
    In3 => pin6
    In4 => pin7
    EnA => pin9
    EnB => pin10

### Set Pixy2 Cam :
    Connect the Pixy cam to your computer(or laptop) and open the PixyMon-v2 to set your Pixy Cam.
    Remenber to change it to the line tracking mode, or you can't access any server from the Pixy Cam built-in functioin.

### Start to code :
    Copy the code on my github and open the MoterLineCarPixy.ino in the forder with Arduino-ADE.
    Then, you can build it and upload the code to your Arduino Nano.

### Draw your map:
    Use some paper or tape to build a map that you want to try yuor car on, the example we provide is using a white line map. If you wwant to change another color, you can change it in your PixyMon-v2 settings.

### Play with it !!!
    Keep trying and changing your speed value in the Arduino code. Once you find your car can turn without any strange problem. Then that most the best condition of your drifting car !!!
    Try more different and rough map !!!

#### Reference:
* <a herf='https://pixycam.com/'>Pixy.com</a>
* <a herf='https://www.arduino.cc/'>Arduino.cc</a>

