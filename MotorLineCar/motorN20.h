#ifndef _MOTORN20_H_
#define _MOTORN20_H_
#include <Vector.h>

class MotorN20 {
  public:
    Vector<byte> motorL;
    Vector<byte> motorR;  
    int highSpeed = 255;
    int lowSpeed = 100;
    void setMotor();
    void stopMotor();
    void forward();
    void turnLeft();
    void turnRight();
    void backward();
    void littleLeft();
    void littleRight();
    void setMotor(byte EnA, byte In1, byte In2, byte EnB, byte In3, byte In4);
  MotorN20(byte EnA, byte In1, byte In2, byte EnB, byte In3, byte In4);

  
  
};


#endif
