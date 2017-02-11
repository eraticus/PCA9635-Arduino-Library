#include <PCA9635.h>
#include <Wire.h>

PCA9635::PCA9635(int address)
{
  _address = address;
 
}

void PCA9635::begin()
{
  setRegister(MODE1, B00000000);
  setRegister(MODE2, B00000000);

  setRegister(LEDOUT0, 0xFF);
  setRegister(LEDOUT1, 0xFF);
  setRegister(LEDOUT2, 0xFF); 
  setRegister(LEDOUT3, 0xFF);
}

void PCA9635::analogWrite(int pin, int value)
{
	int reg = 0x2 + pin;

	setRegister(reg, value);
}




void PCA9635::setRegister(int reg, int value)
{
  //WRITE LED0 byte
  Wire.beginTransmission(_address);

  Wire.write(reg);
  Wire.write(value);

  int result = Wire.endTransmission();

  //return result;
}


