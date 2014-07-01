#include <Arduino.h>
#include <Wire.h>

class PCA9635
{
public:
  PCA9635(int address);
  int version();

  void begin();
  void setGroup(int pwm);
  void setLED(int led, int pwm);
  void setLED0(int pwm);
  void setLED1(int pwm);


private:
  int setRegister(int reg, int value);
  int setRegisters(int values[]);
  int _address;
  int ledvalues [16];


};

// Register numbers

const int MODE1 = 0x00;
const int MODE2 = 0x01;
const int PWM0 = 0x02;
const int PWM1 = 0x03;
const int LEDOUT0 = 0x14;
const int LEDOUT1 = 0x15;
const int LEDOUT2 = 0x16;
const int LEDOUT3 = 0x17;
const int GRPPWM = 0x12;


