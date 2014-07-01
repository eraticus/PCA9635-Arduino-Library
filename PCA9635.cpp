#include "PCA9635.h"

PCA9635::PCA9635(int address)
{
  _address = address;
  for(int i=0; i<16; i++)
  {
    ledvalues[i] = 0; 
  }

  /*
 
   */



}

void PCA9635::begin()
{
  setRegister(MODE1, 0b00000000);
  setRegister(MODE2, 0b00001101);

  setRegister(LEDOUT0, 0xFF);
  setRegister(LEDOUT1, 0xFF);
  setRegister(LEDOUT2, 0xFF); 
  setRegister(LEDOUT3, 0xFF);
  

  for(int i=0; i<16; i++)
  {
    ledvalues[i]=0;
    setLED(i,ledvalues[i]); 
  }
  
}

int PCA9635::version()
{
  return 1; 
}

void PCA9635::setLED(int led, int pwm)
{
  ledvalues[led] = pwm;

  setRegister(led + PWM0, ledvalues[led]);
}

void PCA9635::setGroup(int pwm)
{
  setRegister(GRPPWM, pwm);

}

int PCA9635::setRegister(int reg, int value)
{
  //WRITE LED0 byte
  Wire.beginTransmission(_address);

  Wire.write(0b00011111 & reg);
  Wire.write(value);

  int result = Wire.endTransmission();

  return result;
}


